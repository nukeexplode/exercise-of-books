(define (attach-tag type-flag datum)
  (if (number? datum)
      datum
      (cons type-flag datum)))

(define (type-flag datum)
  (cond ((number? datum) 'scheme-number)
        ((pair? datum) (car datum))
        (else (error "nmsl"))))

(define (contents datum)
  (cond ((number? datum) datum)
        ((pair? datum) (cdr datum))
        (else (error "ljasdflk"))))