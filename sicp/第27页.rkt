Welcome to DrRacket, version 7.0 [3m].
Language: planet neil/sicp, with debugging; memory limit: 128 MB.
> (define (count-change x)
    (cc amount 5)
    )
> define (cc amount denomination)
. define: bad syntax in: define
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        else
        (+ (cc (- amount (diplay-denomination denomination))   kind-of-denomination)
       (cc amount (- kind-of-demination 1)))))
. if: bad syntax in: (if ((= amount 0) 1) ((or (= kind-of-denomination 0) (< amount 0)) 0) else (+ (cc (- amount (diplay-denomination denomination)) kind-of-denomination) (cc amount (- kind-of-demination 1))))
> (define (cc amount denomination)
    (cond ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        else
        (+ (cc (- amount (diplay-denomination denomination))   kind-of-denomination)
       (cc amount (- kind-of-demination 1)))))
. else: bad syntax in: else
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else
        (+ (cc (- amount (diplay-denomination denomination))   kind-of-denomination)
       (cc amount (- kind-of-demination 1))))))
. else: not allowed as an expression in: (else (+ (cc (- amount (diplay-denomination denomination)) kind-of-denomination) (cc amount (- kind-of-demination 1))))
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        else
        (+ (cc (- amount (diplay-denomination denomination))      kind-of-denomination)   
       (cc amount (- kind-of-demination 1)))))
. if: bad syntax in: (if ((= amount 0) 1) ((or (= kind-of-denomination 0) (< amount 0)) 0) else (+ (cc (- amount (diplay-denomination denomination)) kind-of-denomination) (cc amount (- kind-of-demination 1))))
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else
         (+ (cc (- amount display-denomination) kind-of-denomination)
            (cc amount (- kind-of-denomination 1))))))
       
. else: not allowed as an expression in: (else (+ (cc (- amount display-denomination) kind-of-denomination) (cc amount (- kind-of-denomination 1))))
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else
         (+ (cc (- amount
                   (display-denomination kind-of-denomination)
                   kind-of-denomination)
            (cc amount
                (- kind-of-denomination 1))))))
    )
. else: not allowed as an expression in: (else (+ (cc (- amount (display-denomination kind-of-denomination) kind-of-denomination) (cc amount (- kind-of-denomination 1)))))
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else
         (+ (cc (- amount
                   (display-denomination kind-of-denomination))
                   kind-of-denomination)
            (cc amount
                (- kind-of-denomination 1))))))
. else: not allowed as an expression in: (else (+ (cc (- amount (display-denomination kind-of-denomination)) kind-of-denomination) (cc amount (- kind-of-denomination 1))))
> (define (cc amount denomination)
    (if ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else (+ (cc (- amount
                     (display-denomination kind-of-denomination))
              kind-of-denomination)
            (cc amount
                (- kind-of-denomination 1))))))
. else: not allowed as an expression in: (else (+ (cc (- amount (display-denomination kind-of-denomination)) kind-of-denomination) (cc amount (- kind-of-denomination 1))))
> (define (cc amount denomination)
    (cond ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else (+ (cc (- amount
                     (display-denomination kind-of-denomination))
              kind-of-denomination)
            (cc amount
                (- kind-of-denomination 1))))))
> (define display-denomination kind-of-denomination)
. . kind-of-denomination: undefined;
 cannot reference an identifier before its definition
> (define (display-denomination kind-of-denomination)
    (cond ((= kind-of-denomination 5) 50)
          ((= kind-of-denomination 4) 25)
          ((= kind-of-denomination 3) 10)
          ((= kind-of-denomination 2) 5)
          ((= kind-of-denomination 1) 1)))
> (count-change 100)
. . amount: undefined;
 cannot reference an identifier before its definition
> (define (count-change amount)
    (cc amount 5)
    )
> (count-change 100)
. . kind-of-denomination: undefined;
 cannot reference an identifier before its definition
> (define (cc amount kind-of-denomination)
    (cond ((= amount 0) 1)
        ((or (= kind-of-denomination 0) (< amount 0)) 0)
        (else (+ (cc (- amount
                     (display-denomination kind-of-denomination))
              kind-of-denomination)
            (cc amount
                (- kind-of-denomination 1))))))
> (count-change 100)
292
> 