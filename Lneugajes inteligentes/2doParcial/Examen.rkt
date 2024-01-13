#lang racket

(define (cuadrado n )
  (if(< n 0) (*(* -1 n) (* -1 n) )
     (* n n)))
(define (cubo n)
  (if(< n 0) (*(cuadrado n) (* -1 n) )
  (* (cuadrado n) n)))

(define n (read))

(display "Enter the value of n: ")
(set! n (read))

(display(cuadrado n))
(newline)
(display(cubo n))