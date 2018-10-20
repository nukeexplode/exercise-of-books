(define (apply-genric op . data)
  (let ((flag (map type-flag data)))
    (let ((proc (get op flag)))
      (if proc
          (apply proc (map content data))
          (error "134123")))))
;schemenumber
(put equ? ('seheme-number 'scheme-number) =)

;rational-number
(define (equ? x y) 
  (= (* (numer x) (denom y)) (* (numer y) (denom x))))
(put 'equ? '(rational rational) equ?)

;complex
(define (equ? x y) 
  (and (= (real-part x) (real-part y)) (= (imag-part x) (imag-part y))))
(put 'equ? '(complex complex) equ?)

;outside
(define (equ? x y) (apply-generic 'equ? x y)) 