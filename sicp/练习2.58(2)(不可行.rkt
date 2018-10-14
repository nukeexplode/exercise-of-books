(define (augend s)
  (let ((tail-operand (cddr s)))
    (if (single-operand? tail-operand)
        (car tail-operand)
        (apply make-sum tail-operand))))
        ;(make-sum (car tail-operand) (cdr tail-operand)))));会变为一个list的
;> (define (test a . b)
;    (display a)
;    (newline)
;    (display b))
;> (test 1 (list 1 2 3))
;1
;((1 2 3))

(define (make-sum a1 a2)
    (cond ((=number? a1 0)
            a2)
          ((=number? a2 0)
            a1)
          ((and (number? a1) (number? a2))
            (+ a1 a2))
          (else
            (list a1 '+ a2))))

(define (make-sum a1 . a2)
  (if (number? (car a2))
      (+ a1 (car a2))
  (let ((a2 (cdr a2)))
    (if (single-operand? a2)
        (let ((a2 (car a2)))
          (cond ((=number? a1 0)
                 a2)
                ((=number? a2 0)
                 a1)
                ((and (number? a1) (number? a2))
                 (+ a1 a2))
                (else
                 (list a1 '+ a2))));递归到最后做的
        (cons a1 (cons '+ a2))))));传入deriv的

(define (sum? x)
  (and (pair? x)
       (eq? (cadr x) '+)))

(define (addend s)
  (car s))

(define (deriv exp var)
  (cond ((number? exp)
         0)
        ((variable? exp)
         (if (same-variable? exp var)
             1
             0))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (deriv (multiplicand exp) var))
          (make-product (deriv (multiplier exp) var)
                        (multiplicand exp))))
        (else
         (error "unknown expression type -- DERIV" exp))))

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

(define (make-product m1 . m2)
  (if (number? (car m2))
      (* m1 m2)
    (if (single-operand? m2)
        (let ((m2 (car m2)))
            (cond ((or (=number? m1 0) (=number? m2 0))
                    0)
                  ((=number? m1 1)
                    m2)
                  ((=number? m2 1)
                    m1)
                  ((and (number? m1) (number? m2))
                    (* m1 m2))
                  (else
                    (list m1 '* m2))))
        (cons m1 (cons '* m2))))

(define (product? x)
    (and (pair? x)
         (eq? (cadr x) '*)))

(define (multiplier p)
    (car p))

(define (multiplicand p)
    (let ((tail-operand (cddr p)))
        (if (single-operand? tail-operand)
            (car tail-operand)
            (apply make-product tail-operand))))

(define (single-operand? s)
  (null? (cdr s)))