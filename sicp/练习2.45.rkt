
(#%require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))

(define (split f g)
  (lambda(painter n)
    (if(= n 0)
       painter
       (let ((smaller ((split f g) painter (- n 1))))
       (f painter (g smaller smaller))))))

(define right-split (split beside below))
(define up-split (split below beside))

;another choose
(define (split1 f g)
  (define (rec painter n)
    (if(= n 0)
       painter
       (let ((smaller (rec painter (- n 1))))
       (f painter (g smaller smaller)))))
  rec)

(define right-split1 (split1 beside below))
(define up-split1 (split1 below beside))