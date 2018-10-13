(define (frame-coord-map frame)
  (lambda (v)
    (add-vect
     (origin-frame frame)
     (add-vect (scale-vect (xcor-vect v)
                           (edge1-frame frame))
               (scale-vect (ycor-vect v)
                           (edge2-frame frame))))))

;ex2.46
(define (make-vect x y) (cons x y)) 
(define (xcor-vect vec) (car vec)) 
(define (ycor-vect vec) (cdr vec)) 

(define (add-vect v1 v2) 
  (make-vect (+ (xcor-vect v1) (xcor-vect v2)) 
             (+ (ycor-vect v1) (ycor-vect v2)))) 
(define (sub-vect v1 v2) 
  (make-vect (- (xcor-vect v1) (xcor-vect v2)) 
             (- (ycor-vect v1) (ycor-vect v2)))) 
(define (scale-vect s vec) 
  (make-vect (* s (xcor-vect vec)) 
             (* s (ycor-vect vec)))) 

;ensure vect operate is true
;(ensure-all 
; (list (= (xcor-vect (make-vect 3 4)) 3) "x" 
;   (= (ycor-vect (make-vect 3 4)) 4) "y" 
;    (eq-vect? (make-vect 7 11) (add-vect v5-8 v2-3)) "add" 
;     (eq-vect? (make-vect 3 5) (sub-vect v5-8 v2-3)) "sub" 
;      (eq-vect? (make-vect 10 16) (scale-vect 2 v5-8)) "scale" 
;       ))

;i can't understand
(define (ensure b err-msg) 
  (if (not b) (error err-msg))) 
  
(define (ensure-all list-of-tests-and-messages) 
  (cond ((null? list-of-tests-and-messages) true) 
        (else 
         (ensure (car list-of-tests-and-messages) 
                 (cadr list-of-tests-and-messages)) 
         (ensure-all (cddr list-of-tests-and-messages)))))

;ex2.46   higher-abstraction
(define (f-vect v1 v2 f)
  (cons (f (xcor-vect v1)
           (xcor-vect v2))
        (f (ycor-vect v1)
           (ycor-vect v2))))

;ex2.47
(define (make-frame origin edge1 edge2)
  (list origin edge1 edge2))

(define (make-frame origin edge1 edge2)
  (cons origin (cons edge1 edge2)))


(define (make-frame origin edge1 edge2) 
  (list origin edge1 edge2)) 
(define (frame-origin f) (car f)) 
(define (frame-edge1 f) (cadr f)) 
(define (frame-edge2 f) (caddr f)) 
  
(define f (make-frame 1 2 3)) 
(frame-origin f) 
(frame-edge1 f) 
(frame-edge2 f) 
  
(define (make-frame origin edge1 edge2) 
  (cons origin (cons edge1 edge2))) 
(define (frame-origin f) (car f)) 
(define (frame-edge1 f) (cadr f)) 
(define (frame-edge2 f) (cddr f))
  
