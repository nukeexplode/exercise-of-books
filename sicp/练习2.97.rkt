;ex2.97(a)
(define (reduce-terms n d)
  (let* ((gcd (gcd-terms n d))
         (nd-factor (integerising-factor n d))
         (nn (div-terms (mul-integer-terms nd-factor n) gcd))
         (dd (div-terms (mul-integer-terms nd-factor d) gcd))
         (result-factor (apply gcd (append (map coeff nn) (map coeff dd)))))
    (list (reduce-list nn result-factor)
          (reduce-list dd result-factor))))
 
(define (reduce-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (div-result (variable p1) (reduce (term-list p1) (term-list p2)))
      (error "Polys not in same var -- DIV-POLY"
             (list p1 p2))))

;ex2.98(b)
(define (reduce x y) (apply-generic 'reduce x y))

; in the polynomial package
(put 'reduce '(polynomial polynomial) (lambda (p1 p2) (reduce-poly p1 p2)))
 
; in the dense terms package
(put 'reduce '(dense dense)  (lambda (t1 t2) (map tag (reduce-terms t1 t2))))
(put 'reduce '(dense sparse) (lambda (t1 t2) (map tag (reduce-terms t1 (sparse->dense t2)))))
 
; in the sparse terms package
(put 'reduce '(sparse sparse) (lambda (t1 t2) (map tag (reduce-terms t1 t2))))
(put 'reduce '(sparse dense)  (lambda (t1 t2) (map tag (reduce-terms t1 (dense->sparse t2)))))
 
; in the integer package
(define (reduce-integers n d)
  (let ((g (gcd n d)))
    (list (/ n g) (/ d g))))
 
(put 'reduce '(integer integer) (lambda (x y) (map tag (reduce-integers x y))))