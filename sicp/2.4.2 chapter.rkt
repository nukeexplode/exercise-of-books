(define (add-complex z1 z2)
  (make-from-real-imag (+ (real-part z1) (real-part z2))
                       (+ (imag-part z1) (imag-part z2))))

(define (sub-complex z1 z2)
  (make-from-real-imag (- (real-part z1) (real-part z2))
                       (- (imag-part z1) (imag-part z2))))

(define (mul-complex z1 z2)
  (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                     (+ (angle z1) (angle z2))))

(define (div-complex z1 z2)
  (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                     (- (angle z1) (angle z2))))

(define (square x)
  (* x x))

(define (attach-tag type-tag contents)
  (cons type-tag contents))

(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (error "bad tagged datum")))

(define (contents datum)
  (if (pair? datum)
      (cdr datum)
      (error "contents")))

(define (rectangular? z)
  (eq? (type-tag z) 'rectangular))

(define (polar? z)
  (eq? (type-tag z) 'polar))

;ben
(define (real-part-rectangular z) (car z))
(define (imag-part-rectangular z) (cdr z))
(define (magnitude-rectangular z)
  (sqrt (+ (square (real-part-rectangular z))
           (square (imag-part-rectangular z)))))
(define (angle-rectangular z)
  (atan (imag-part-rectangular z)
        (real-part-rectangular z)))
(define (make-from-real-imag-retangular x y)
  (attach-tag 'rectangular (cons x y)))
(define (make-from-mag-ang-rectangular r a)
  (attach-tag 'rectangular
              (cons (* r (cos a)) (* r (sin a)))))

;alyssa
(define (real-part-polar z)
  (* (magnitude-polar z) (cos (angle-polar z))))

(define (imag-part-polar z)
  (* (magnitude-polar z) (sin (angle-polar z))))

(define (magnitude-polar z) (car z))
(define (angle-polar z) (cdr z))

(define (make-from-real-imag-polar x y)
  (attach-tag 'polar
              (cons (sqrt (+ (square x) (square y)))
                    (atan y x))))

(define (make-from-mag-ang-polar r a)
  (attach-tag 'polar (cons r a)))

;choose function
(define (real-part z)
  (cond ((rectangular? z)
         (real-part-rectangular (contents z)))
        ((polar? z)
         (real-part-polar (content z)))
        (else (error "real-part"))))

(define (imag-part z)
  (cond ((rectangular? z)
         (imag-part-rectangular (content z)))
        ((polar? z)
         (imag-part-polar (contents z)))
        (else (error "imag-part"))))

(define (magnitude z)
  (cond ((rectangular? z)
         (magnitude-rectangular (content z)))
        ((polar? z)
         (magnitude-polar (contents z)))
        (else (error "magnitude"))))

(define (angle z)
  (cond ((rectangular? z)
         (angle-rectangular (content z)))
        ((polar? z)
         (angle-polar (contents z)))
        (else (error "angle"))))

;construct function
(define (make-from-real-imag x y)
  (make-from-real-imag-rectangular x y))

(define (make-from-mag-ang r a)
  (make-from-mag-polar r a))

;the defination of put and get
(define global-array '())

(define (make-entry k v) (list k v))
(define (key entry) (car entry))
(define (value entry) (cadr entry))

(define (put op type item)
  (define (put-helper k array)
    (cond ((null? array) (list(make-entry k item)))
          ((equal? (key (car array)) k) array)
          (else (cons (car array) (put-helper k (cdr array))))))
  (set! global-array (put-helper (list op type) global-array)))

(define (get op type)
  (define (get-helper k array)
    (cond ((null? array) #f)
          ((equal? (key (car array)) k) (value (car array)))
          (else (get-helper k (cdr array)))))
  (get-helper (list op type) global-array))

;start with page 123

;strat with page 125
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-args)))
      (if proc
          (apply proc (map contents args))
          (error "no method for these types"
                 (list op type-tags))))))

(define (real-part z) (apply-generic 'real-part z))
(define (imag-part z) (apply-generic 'imag-part z))
(define (magnitude z) (apply-generic 'magnitude z))
(define (angle z) (apply-generic 'angle z))

(define (make-from-real-imag x y)
  ((get 'make-from-real-imag 'rectangular) x y))

(define (make-from-real-ang r a)
  ((get 'make-from-real-ang 'polar) r a))

;ex2.73
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
        (else ((get 'deriv (operator exp)) (operands exp)
                                           var))))

(define (operator exp) (car exp))
(define (operands exp) (cdr exp))

;make-sum
(define (install-sum-package)
  (define (addend s)
    (car s))
  
  (define (augend s)
    (cadr s))

  (define (make-sum x y)
    (cond ((=number? x 0)
           y)
          ((=number? y 0)
           x)
          ((and (number? x) (number? y))
           (+ x y))
          (else
           (attach-tag '+ x y))))

  (put 'addend '+ addend)
  (put 'augend '+ augend)
  (put 'make-sum '+ make-sum)

  (put 'deriv '+
       (lambda (exp var)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))))

  (define (make-sum x y)
    ((get 'make-sum '+) x y))

  (define (addend sum)
    ((get 'addend '+) (contents sum)))

  (define (augend sum)
    ((get 'augend '+) (contents sum)))

;make-product
  (define (install-product-package)
    ;;; internal procedures
    (define (multiplier p)
      (car p))

    (define (multiplicand p)
      (cadr p))

    (define (make-product x y)
      (cond ((or (=number? x 0) (=number? y 0))
             0)
            ((=number? x 1)
             y)
            ((=number? y 1)
             x)
            ((and (number? x) (number? y))
             (* x y))
            (else
             (attach-tag '* x y))))

    ;;; interface to the rest of the system
    (put 'multiplier '* multiplier)
    (put 'multiplicand '* multiplicand)
    (put 'make-product '* make-product)

    (put 'deriv '*
         (lambda (exp var)
           (make-sum
            (make-product (multiplier exp)
                          (deriv (multiplicand exp) var))
            (make-product (deriv (multiplier exp) var)
                          (multiplicand exp)))))

    'done)

  (define (make-product x y)
    ((get 'make-product '*) x y))

  (define (multiplier product)
    ((get 'multiplier '*) (contents product)))

  (define (multiplicand product)
    ((get 'multiplicand '*) (contents product)))

  ;; number

(define (=number? exp num)
  (and (number? exp)
       (= exp num)))

;; variable

(define (variable? x)
  (symbol? x))

(define (same-variable? v1 v2)
  (and (variable? v1)
       (variable? v2)
       (eq? v1 v2)))

;tag
(define (attach-tag type-tag x y)
    (list type-tag x y))

(define (type-tag datumn)
    (car datumn))

(define (contents datumn)
    (cdr datumn
  