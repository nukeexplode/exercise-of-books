(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (drop (apply proc (map contents args)))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cdr type-tags))
                    (a1 (car args))
                    (a2 (cdr args)))
                (let ((diff (higher? type1 type2)))
                  (cond 
                    ((= 0 diff) (error "No method for these types" (list op type-tags)))
                    ((> 0 diff) (drop (apply-generic op (raise a1) a2 )))
                    (else (drop (apply-generic op a1 (raise a2)))))))
              (error "No method for these types" (list op type-tags)))))))

(define (type-val t) 
  (cond
    ((eq? t 'scheme-number) 1)
    ((eq? t 'rational) 2)
    ((eq? t 'real) 3)
    ((eq? t 'complex) 4)
    (else (error "No such type" t))))

(define (drop x)
  (let ((lower-project (get project (type-tag x))))
    (if lower-project
        (let ((low-x (lower-project x)))
          (if (equal? low-x x)
              (lower low-x)
              x))
        x)))

(define (equal? lower-x x)
  (let ((raised-x (raise-to-complex x))
        (raised-x (raise-to-complex x)))
    (and (= (image-part raised-x) (image-part raised-y))
         (= (real-part raised-x) (real-part raised-y)))))