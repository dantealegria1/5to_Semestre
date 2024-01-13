#lang racket
(define nota 7)

(define (profesor)
  (if (>= nota 7)
      (display "Aprobado")
      (display "Reprobado")))

(define (evaluar)
  (cond
    ((>= nota 9) "Excelente")
    ((>= nota 8) "Notable")
    ((>= nota 7) "Aprobado")
    (else "Reprobado")))

(displayln (evaluar))
(profesor)
