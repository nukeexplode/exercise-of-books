(define (integerising-factor a b)
  (let ((tb (first-term b)))
    (expt (coeff tb) 
          (- (+ 1 
                (order (first-term a)))
             (order tb)))))
 
(define (pseudoremainder-terms a b)
  (cadr (div-terms (mul-integer-terms 
                    (integerising-factor a b)
                    a)
                   b)))
 
(define (gcd-terms a b)
  (if (empty-termlist? b)
      a
      (gcd-terms b (pseudoremainder-terms a b))))

;b
(define (reduce-list L factor)
  (term-map (lambda (t)
              (make-term (order t)
                         (/ (coeff t)
                            factor)))
            L))
   
(define (reduce L)
  (reduce-list L (apply gcd L)));最好设一下0的时候gcd是0
 
(put 'gcd '(dense dense) (lambda (t1 t2) (tag (reduce (gcd-terms t1 t2)))))
(put 'gcd '(dense sparse) (lambda (t1 t2) (tag (reduce (gcd-terms t1 (sparse->dense t2))))))