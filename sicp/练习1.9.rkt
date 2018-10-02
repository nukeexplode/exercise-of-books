Welcome to DrRacket, version 7.0 [3m].
Language: planet neil/sicp, with debugging; memory limit: 128 MB.
> (define (+ a b)
    (if (= a 0)
        b
        (inc (+ (dec a) b))))
> (define (inc x)
    (+ x 1))
> (define (dec x)
    (- x 1))
> (+ 2 1)
3
> 