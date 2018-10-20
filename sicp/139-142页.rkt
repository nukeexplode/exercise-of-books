

(define (install-polynomial-package)
  (define (make-poly variable term-list)
    (cons variable term-list))
  (define (variable p) (car p))
  (define (term-list p) (cdr p))

  (define (add-poly p1 p2)
    (if (same-variable? (variable? p1) (variable p2))
        (make-poly (variable? p1)
                   (add-term (term-list p1)
                             (term-list p2)))
        (error "different variable")))
  
  (define (mul-poly p1 p2)
    (if (same-variable? (variable? p1) (variable p2))
        (make-poly (variable? p1)
                   (mul-term (term-list p1)
                             (term-list p2)))
        (error "different variable")))

  (define (tag p) (attach-tag 'polynomial p))
  (put 'add '(polynomial polynomial)
       (lambda (p1 p2)
         (tag (add-poly p1 p2))))

  (put 'mul '(polynomial polynomial)
       (lambda (p1 p2)
         (tag (mul-poly p1 p2))))

  (put 'make 'polynomial
       (lambda (var terms)
         (tag (make-poly var terms))))
  'done)

;add
(define (add-terms p1 p2)
  (cond ((empty-termlist? p1) p2)
        ((empty-termlist? p2) p1)
        ((> (order (first-term p1)) (order (first-term p2)))
         (adjoin-term (first-term p1)
                      (add-terms (rest-terms p1)
                                 p2)))
        ((< (order (first-term p1)) (order (first-term p2)))
         (adjoin-term (first-term p2)
                      (add-terms (rest-terms p1)
                                 p2)))
        (else
         (adjoin-term
          (make-term (order p1)
                     (add (coeff (first-term p)) (coeff (first-term p))))
          (add-terms (rest-terms p1) (rest-terms p2))))))

;mul
(define (mul-term p1 p2)
  (if (empty-termllist? p1)
      (the-empty-termlist)
      (add-term (mul-term-all-terms (first-term p1) p2)
                (mul-term (rest-items p1) p2))))

(define (mul-term-all-terms t1 p2)
  (if (empty-termlist? p2)
      the-empty-termlist
      (let ((m1 (first-term p2)))
      (adjoin-term (make-term (add (order t) (order m1))
                              (mul (coeff t) (coeff m1)))
                   (mul-term-all-terms t1
                                       (rest-term p2))))))

(define (adjoin-term term term-list)
  (if (=zero? (coeff term))
      term-list
      (cons term term-list)))

(define (the-empty-termlist) '())
(define (first-term term-list)
  (car term-list))
(define (rest-term term-list)
  (cdr term-list))
(define (empty-termlist? term-list)
  (null? term-list))
(define (make-term order coeff)
  (list order coeff))
(define (order term)
  (car term))
(define (coeff term)
  (cadr term))

(define (make-polynomial var terms)
  ((get 'make 'polynomial) var terms))