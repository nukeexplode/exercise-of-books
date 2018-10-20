(define (lookup given-key set-of-records)
  (cond ((null? set-of-records) false)
        ((equal? given-key (key (car set-of-records)))
         (car set-of-records))
        (else (lookup givenkey (cdr set-of-records)))))

(define (make-tree entry left right)
  (list entry left right))

(define (entry tree)
  (car tree))

(define (left-branch tree)
  (cadr tree))

(define (right-branch tree)
  (caddr tree))

(define (lookup given-key tree-of-records)
  (if (null? tree-of-records)
      false
      (let ((entry-key (key (entry tree-of-records))))
        (cond ((= given-key entry-key)
               true
              ((< given-key entry-key)
               (look-up given-key (right-branch tree-of-records)))
              ((> given-key entry-key)
               (look-up given-key (left-branch tree-of-records))))))))