(define (element-of-set? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (element-of-set? x (cdr set)))));o(n)

(define (adjoin-set x set)
  (if (element-of-set? x set)
      set
      (cons x set)))

(define (intersection-set set1 set2)
  (cond ((or (null? set1) (sull? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons set1 (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))));o(n2)

;(define (union-set set1 set2)
;  (cond ((null? set1) set2)
;        ((element-of-set? (car set1) set2)
;         (union-set (cdr set1) set2))
;        (else
;         (cons (car set1) (union-set (cdr set1) set2)))));o(n2)

(define (union-set set1 set2)
    (iter (append set1 set2) '()))

(define (iter input result)
    (if (null? input)
        (reverse result)
        (let ((current-element (car input))
              (remain-element (cdr input)))
            (if (element-of-set? current-element result)
                (iter remain-element result)
                (iter remain-element
                      (cons current-element result))))));尾递归