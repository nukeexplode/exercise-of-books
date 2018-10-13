(define (segements->painter segement-list)
  (lambda (frame)
    (for-each
     (lambda (segement)
       (draw-line
        ((frame-coord-map frame) (start-segment segment))
        ((frame-coord-map frame) (end-segment segment))))
     segment-list)))

(define (frame-coord-map frame)
  (lambda (v)
    (add-vect
     (origin-frame frame)
     (add-vect (scale-vect (xcor-vect v)
                           (edge1-frame frame))
               (scale-vect (ycor-vect v)
                           (edge2-frame frame))))))

(define (flip-horiz painter) 
   (transform-painter painter 
                      (make-vect 1.0 0.0) 
                      (make-vect 0.0 0.0) 
                      (make-vect 1.0 1.0))) 
  
 (define (rotate180 painter) 
   (transform-painter painter 
                      (make-vect 1.0 1.0) 
                      (make-vect 0.0 1.0) 
                      (make-vect 1.0 0.0))) 
  
 (define (rotate270 painter) 
   (transform-painter painter 
                      (make-vect 0.0 1.0) 
                      (make-vect 0.0 0.0) 
                      (make-vect 1.0 1.0)))

;ex2.51
 (define (below painter1 painter2) 
   (let ((split-point (make-vect 0.0 0.5))) 
     (let ((paint-bottom 
            (transform-painter painter1 
                               (make-vect 0.0 0.0) 
                               (make-vect 1.0 0.0) 
                               split-point)) 
           (paint-top 
            (transform-painter painter2 
                               split-point 
                               (make-vect 1.0 0.5) 
                               (make-vect 0.0 1.0)))) 
       (lambda (frame) 
         (paint-bottom frame) 
         (paint-top frame))))) 
  
 (define (below-2 painter1 painter2) 
   (rotate90 (beside (rotate270 painter1) (rotate270 painter2)))) 
  
 ;; Another way 
 (define (below-2 painter1 painter2) 
   (rotate270 (beside (rotate90 painter2) (rotate90 painter1)))) 

;ex2.52
