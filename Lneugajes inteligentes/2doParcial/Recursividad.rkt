#lang racket
(define (factorial n)
  (if (> n 0)
      (* n (factorial (- n 1)))
      1))

(define (platica)
  (let ((input (read-line)))
    (if (string? input)
        (cond
          ((string-prefix? "hola" input)
           (begin
             (display "hola, ¿qué tal estás?")
             (newline)
             (platica)))
          ((string-prefix? "bien" input)
           (begin
             (display "Me alegro mucho, que has hecho?")
             (newline)
             (platica)))
          ((string-prefix? "adios" input)
           (begin
             (display "adiosito")))
          (else
           (begin
             (display "Perdona, aun no soy tan listo para responderte a eso")
             (newline)
             (platica))))
        (begin
          (display "Una disculpa, solo entiendo palabras, no números")
          (newline)
          (platica)))))
