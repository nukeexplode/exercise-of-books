(define (install-scheme-number-package) 
  ;; ... 
  (put '=zero? 'scheme-number
    (lambda(x) (= 0 x)))
  'done)

(define (install-rational-package) 
  ;; ... 
  (put '=zero? 'rational
    (lambda(x) (= 0 (numer x))))
  'done) 

(define (install-complex-package)   
  ;; ... 
  (put '=zero? 'complex 
    (lambda (z) (and (= 0 (real-part z)) (= (imag-part z) 0))))
  'done)

(define (zero? x y) (apply-generic 'zero? x y)) 