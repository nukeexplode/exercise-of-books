(define (sub-poly t1 t2)
  (if (same-variable? (variable t1) (same-variable t2))
      (make-poly (variable t1)
                 (add-terms (term-list t1)
                            (negate-terms (term-list t2))))
      (error "different variaable")))

(define (negate-terms p)
  (term-map negate-term p))
(define (term-map f terms)
  (if (empty-termlist? terms)
      (the-empty-termlist)
      (adjoin-term (f (fist-term terms))
                   (term-map f (rest-terms terms)))))
(define (negate-term term)
  (make-term (order term)
             (negate (coeff term))))

(define (negate x)
  (apply-generic 'negate x))

(define (negate-poly p)
  (make-poly (variable p)
             (negate-terms (term-list p))))

(put 'sub '(polynomial polynomial)
     (lambda (p1 p2)
       (tag (sub-poly p1 p2))))

(put 'negate 'polynomian
     (lambda (p)
       (tag (negate-poly p))))