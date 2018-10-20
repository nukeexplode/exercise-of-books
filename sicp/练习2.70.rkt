(define (make-leaf symbol weight)
  (list 'leaf symbol weight))

(define (leaf? object)
  (eq? (car object) 'leaf))

(define (symbol-leaf x) (cadr x))
(define (weight-leaf x) (caddr x))

(define (make-code-tree left right)
  (list left
        right
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))

(define (left-branch tree) (car tree))
(define (right-branch tree) (cadr tree))

(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

;decoding process
(define (decode bits tree)
  (define (decode-l bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch
               (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-l (cdr bits) tree))
              (decode-l (cdr bits) next-branch)))))
  (decode-l bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- choose-branch" bit))))

;the set with weight element
(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) (cons x set))
        (else (cons (car set) (adjoin-set x (cdr set))))))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)
                               (cadr pair))
                    (make-leaf-set (cdr pairs))))))

;ex2.69
(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

(define (successive-merge ordered-set)
  (cond ((= 0 (length ordered-set))
         '())
        ((= 1 (length ordered-set))
         (car ordered-set))
        (else
         (let ((new-tree (make-code-tree (car ordered-set)
                                         (cadr ordered-set)))
               (remained-tree (cddr ordered-set)))
           (successive-merge (adjoin-set new-tree remained-tree))))))

;EX2.68
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

(define sample-tree
    (make-code-tree (make-leaf 'A 4)
                    (make-code-tree
                        (make-leaf 'B 2)
                        (make-code-tree (make-leaf 'D 1)
                                        (make-leaf 'C 1)))))

(define (encode-symbol symbol tree)
  (cond ((leaf? tree)
         '())
        ((symbol-in-tree? symbol (left-branch tree))
         (cons 0 (encode-symbol symbol (left-branch tree))))
        ((symbol-in-tree? symbol (right-branch tree))
         (cons 1 (encode-symbol symbol (right-branch tree))))
        (else (error "not in tree"))))

(define (symbol-in-tree? given-symbol tree)
  (define (iter given-symbol symbol)
    (cond ((null? symbol)
          false)
          ((eq? given-symbol (car symbol))
          true)
          (else (iter given-symbol (cdr symbol)))))
  (iter given-symbol (symbols tree)))

(define tree (generate-huffman-tree '((a 1) (na 16) (boom 1) (Sha 3) (Get 2) (yip 9) (job 2) (Wah 1))))

(define msg '(Get a job Sha na na na na na na na na Wah yip yip yip yip yip yip yip yip yip Sha boom))