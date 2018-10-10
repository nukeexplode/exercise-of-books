
(#%require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))

;page 91

(define (square-four tl tr bl br)
  (lambda (painter)
    (let ((top (beside (tl painter) (tr painter)))
          (down (beside (bl painter) (br painter))))
      (below down top))))

(define (flipped-pairs painter)
  (let ((combine4 (square-four identity flip-vert
                               identity flip-vert)))
    (combine4 painter)))

(define (square-limit painter n)
    (let ((combine4 (square-four flip-horiz identity
                                 rotate180 flip-vert)))
      (combine4 (corner-split painter n))))

;necessary for square-limit
(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))

(define (up-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (up-split painter (- n 1))))
        (below painter (beside smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((top-left (beside up up))
              (bottom-right (below right right)) (corner (corner-split painter (- n 1))))
          (beside (below painter top-left)
                  (below bottom-right corner))))))
