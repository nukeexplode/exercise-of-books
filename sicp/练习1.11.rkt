Welcome to DrRacket, version 7.0 [3m].
Language: planet neil/sicp, with debugging; memory limit: 128 MB.
> (define (function x)
    (cond ((< n 3) n)
          (else
          (+ (function(- n 1))
          (* (function(- n 2)) 2)
          (* (function(- n 3)) 3)))))
> (function 0)
. . n: undefined;
 cannot reference an identifier before its definition
> (define (function n)
    (cond ((< n 3) n)
          (else
          (+ (function(- n 1))
          (* (function(- n 2)) 2)
          (* (function(- n 3)) 3)))))
> (function 0)
0
> (function 3
            )
4
> (function 4)
11
> (define (f-iter a b c i n)
    (if (= i n)
        c
        (f-iter (+ a (* 2 b) (* 3 c))   ; new a
                a                       ; new b
                b                       ; new c
                (+ i 1)
                n)))
> (define (f n)
    (f-iter 2 1 0 0 n))

> (f 3)
4
> (f 2)
2
> (f 1
     )
1
> (define (f x)
    (f-iter 2 1 0 x))
> (define (f-iter a b c x)
    (cond ((= x 0) c)
          else
          (+ a (* 2 b) (* 3 c)
             (- x 1))))
. else: bad syntax in: else
> (define (f-iter a b c x)
    (cond ((= x 0) c)
          (else
          (+ a (* 2 b) (* 3 c)
             (- x 1)))))
> (f 3)
6
> (define (f-iter a b c x)
    (cond ((= x 0) c)
          (else
          (f-iter (+ a (* 2 b) (* 3 c))
                 b
                 c
                 (- x 1)))))
> (f 3)
0
> (define (f-iter a b c x)
    (cond ((= x 0) c)
          (else
          (f-iter (+ a (* 2 b) (* 3 c))
                 a
                 b
                 (- x 1)))))
> (f 3)
4
> 