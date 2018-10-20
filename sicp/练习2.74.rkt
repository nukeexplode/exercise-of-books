(define (get-record key)
  (define (get-record-iter file)
    ((get (tag file) 'search) key))
  (map get-record-iter key))

(define (get-record key)
  (define (get-salary-iter file)
    ((get (tag file) 'salary) (content key)))
  (map get-record-iter key))

(define (find-employee-record name division-files)

	(define (apply-generic file)

		((get 'search-by-name (tag file)) name)

	)

	(map apply-generic division-files)

)



; c



; d:

;只要把那些操作put进去