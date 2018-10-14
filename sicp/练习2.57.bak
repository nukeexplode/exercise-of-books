;page 100-101
;(define (deriv exp var)
 ; (cond ((number? exp) 0)
  ;      ((variable? exp)
   ;      (if (same-variable? exp var) 1 0))
    ;    ((sum? exp)
     ;    (make-sum (deriv (addend exp) var)
      ;             (deriv (augend exp) var)))
      ;  ((product? exp)
      ;   (make-sum
      ;    (make-product (multiplier exp)
      ;                  (deriv (multiplicand exp) var))
      ;    (make-product (multiplicand exp)
      ;                  (deriv (multiplier exp) var))))
      ;  (else (error "error"))))

(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))
(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))
(define (addend s) (cadr s))
(define (augend s) (caddr s))
(define (product? x)
  (and (pair? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))

(define (=number? exp num)
  (and (number? exp) (= exp num)))

;> (display (deriv '(* x y) 'x))
;(+ (* x 0) (* y 1))
;> (display (deriv '(* (* x y) (+ x 3)) 'x))
;(+ (* (* x y) (+ 1 0)) (* (+ x 3) (+ (* x 0) (* y 1))))

;> (display (deriv '(* x y) 'x))
;y
;> (display (deriv '(* (* x y) (+ x 3)) 'x))
;(+ (* x y) (* (+ x 3) y))

;ex2.56
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        ((exponentitation? exp)
         (make-product (deriv (base exp) var)
                       (make-product (exponent exp)
                                     (make-exponentitation (base exp)
                                                          ; (if (number? (exponent exp))
                                                          ;     (- (exponent exp) 1)
                                                          ;     ('(- (exponent exp) 1)))
                                                          ;可以make-sum来代替
                                                           (make-sum (exponent exp) -1)))
                                                           ))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (deriv (multiplicand exp) var))
          (make-product (multiplicand exp)
                        (deriv (multiplier exp) var))))
        (else (error "error"))))

(define (exponentitation? exp)
  (and (pair? exp) (eq? (car exp) '**)));其实这个pair做的是判断exp是否是需对

(define (base x)
  (cadr x))

(define (exponent exp)
  (caddr exp))

(define (make-exponentitation base exp);表达式油画
  (cond ((=number? base 1) 1)
        ((=number? exp 1) base)
        ((=number? exp 0) 1)
        (else
         (list '** base exp))))