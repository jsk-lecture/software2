;; test0
(define (test i j)
  (* i j))

(define i 3)
(define j 2)
(define k (test i j))
(if (> k 5)
    (print ">5")
    (print "<=5"))
