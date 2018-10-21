(define (greatest-common-divisor x y) (apply-generic 'gcd x y))

; in the integer package
(put 'gcd        '(integer integer) (lambda (x y) (tag (gcd x y))))
 
; in the polynomial package
(define (gcd-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (make-poly (variable p1)
                 (greatest-common-divisor (term-list p1)
                                          (term-list p2)))
      (error "Polys not in same var -- GCD-POLY"
             (list p1 p2))))
(put 'gcd    '(polynomial polynomial) (lambda (p1 p2)       (tag (gcd-poly p1 p2))))

; in the dense terms package
(define (remainder-terms a b)
  (cadr (div-terms a b)))
   
(define (gcd-terms a b)
  (if (empty-termlist? b)
      a
      (gcd-terms b (remainder-terms a b))))
...
...
(put 'gcd                '(dense dense)   (lambda (t1 t2)       (tag (gcd-terms t1 t2))))
(put 'gcd                '(dense sparse)  (lambda (t1 t2)       (tag (gcd-terms t1 (sparse->dense t2)))))
 
; in the dense terms package
(define (remainder-terms a b)
  (cadr (div-terms a b)))
...
...
; in the sparse-terms package  
(define (gcd-terms a b)
  (if (empty-termlist? b)
      a
      (gcd-terms b (remainder-terms a b))))
...
...
(put 'gcd                '(sparse sparse   (lambda (t1 t2)       (tag (gcd-terms t1 t2))))
(put 'gcd                '(sparse dense)  (lambda (t1 t2)       (tag (gcd-terms t1 (dense->sparse t2)))))