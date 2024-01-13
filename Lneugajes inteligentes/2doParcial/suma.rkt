#lang racket
(define (suma n m)
  (+ n m))

(define n (read))
(define m (read))

(display "Enter the value of n: ")
(set! n (read))

(display "Enter the value of m: ")
(set! m (read))

(display "The sum of n and m is: ")
(display (suma n m))
(newline)

