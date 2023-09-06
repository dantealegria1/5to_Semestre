/*
Nombre de la institución: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de básicas
Nombre del departamento al que pertence la carrera: ciencias de la computación 
Nombre de la materia: Optimización inteligente
Nombre(s) de quien(es) realiza(n) la práctica: Dante Alejandro Alegria Romero
Andrea margarita Balandran Felix

Breve descripción de lo que realiza el programa: 
La "búsqueda aleatoria" en el contexto de la optimización se refiere a un enfoque 
donde los valores de las variables de un problema se generan de manera aleatoria 
en el espacio de búsqueda con el objetivo de encontrar soluciones óptimas o al 
menos mejorar las soluciones existentes. Este método es muy simple y se basa en 
la idea de que, al explorar aleatoriamente el espacio de soluciones, existe una 
posibilidad de encontrar una solución aceptable.
*/

/*
Agregamos las librerias necesarias para el funcionamiento del programa
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

/*
*Creamos una funcion que tome los valores generados aleatoriamente y los sustituya en la formula, 
*para despues regresar el resultado de la funcion
*/

int funcion(int x1, int x2)
{
    int function;
    function = -(x2+47)*sin(sqrt(abs(x2+x1/2+47)))-x1*sin(sqrt(abs(x1-(x2+47))));
    return function;
}

/*
Inicializamos el main
Iniciamos la semilla para generar los numeros aleatorios
inicializamos las variables que vamos a utilizar
* function: que es donde vamos a guardar los valores de la funcion
* resultado: que es donde vamos a guardar el resultado menor que se vaya obteniendo
* x1 y x2: que son los valores que se van a generar aleatoriamente
Dentro de un for:
generamos los valores de x1 y x2 en un rango de -512 a 512
y despues sustituimos estos valores en la funcion y lo guardamos en la variable function
despues comparamos si el valor de function es menor que el valor de resultado, si es asi,
guardamos el valor de function en resultado
Cuando termina el for, mostramos el resultado minimo de la funcion
*/

int main()
{

    srand(time(NULL));

    float function, resultado=1000000;
    int x1,x2;

    for (int i = 0; i < 10001; i++)
    {
        x1 = rand() % 1024-512;
        x2 = rand() % 1024-512;
        function = funcion(x1,x2);
        cout<<"iteracion: "<<i<<endl;
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
        if (function < resultado)
        {
            resultado = function;
        }
    }

    cout << "El resultado minimo de la funcion es: " << resultado << endl;
}