(define (equal? list1 list2)
  (cond ((and (not (pair? list1)) (not (pair? list2)))
         (eq? list1 list2))
        ((and (pair? list1) (pair? list2))
         (and (equal? (car list1) (car list2)) (equal? (cdr list1) (cdr list2))))
        (else false)))

;> (eq? '(1 2 3 (4 5) 6) '(1 2 3 (4 5) 6))
;#f
(define (equal-? a b)
  (or
   (eq? a b)
   (and
    (pair? a)
    (pair? b)
    (equal-? (car a) (car b))
    (equal-? (cdr a) (cdr b)))))