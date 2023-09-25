/*
nombre de la institución: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de básicas
Nombre del departamento al que pertence la carrera: ciencias de la computación 
Nombre de la materia: Optimización inteligente
Nombre(s) de quien(es) realiza(n) la práctica: Dante Alejandro Alegria Romero
Andrea margarita Balandran Felix
Breve descripción de lo que realiza el programa: 
el programa cuenta con dos principales librerias (iostream, math.h) que nos proporcionan las
herramientas necesarias para el funcionamiento del código. Dentro del int main, comenzamos 
declarandotodos los valores y sus tipos necesarios como int y float, despues procedemos a mostrar con cout comentarios
en la terminal donde se presentaran las funciones vistas y sus derivadas de primer y segundo grado. Dentro de un
de un do while, cuya condicion es que el valor absoluto de la derivada 1 es menor al error, dentro de este comenzamos 
con la implementacion de la  derivada uno y la derivada dos donde sustituiremos el valor xo que nos propociono el 
usuario, en este caso 1 y los resultados de estos se ingresaran a la formula del método de newton y lo guarda en la misma variable, 
despues comenzara a comprobar que este valor de resultado sea mayor que el error para poder seguir sustituyendo los valores en las 
derivasa, hasta que el valor de "resultado" sea menos al error acaba el ciclo. 
por último el valor final lo sustiumos en la funcion principal que es la xo para obtener el minimo encontrado. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*
    Estblecemos las variables que vamos a utilizar, asi como un error y un contador de iteraciones
    Esto para evitar que corra de manera infinita
    Resultado es mi valor inicial de x0
    */

    float d0, d1, d2, resultado_inicial, resultado;
    float error = 0.001;
    int iteraciones = 0;

    /*
    Mostramos las funciones y derivadas de la función 
    Tambien pedimos el valor de x0
    */

    cout << "su función es: 2x^2 + 16/x " << endl;
    cout << "la primera derivada es: 4x - 16/x^2" << endl;
    cout << "la segunda derivada es: 32/x^3 + 4" << endl;
    cout << "------ RESOLVER LA FUNCIÓN ------" << endl;
    cout << "Ingrese su valor x0: " << endl;
    cin >> resultado;

    /*
    Hacemos un do while que ejecute hasta que el valor absoluto de la derivada sea menor al error
    Para eso primero calculamos la primera derivada y la segunda derivada y sustituimos
    los valores y utilizamos la formula de newton para encontrar el valor de x n+1, despues de eso
    aumentamos el contador de iteraciones y si este es mayor a 10, se rompe el ciclo
    */

    cout << "Iteración |       d0       |       d1       |       d2       |    resultado" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    do {
        d0 = 2 * (resultado * resultado) + 16 / resultado;
        d1 = 4 * resultado - 16 / (resultado * resultado);
        d2 = 32 / (resultado * resultado * resultado) + 4;
        resultado = resultado - (d1 / d2);
        iteraciones++;

        cout << "    " << iteraciones << "     | ";
        cout << " " << d0 << " | " << d1 << " | " << d2 << " | " << resultado << endl;

        if (iteraciones > 10)
            break;

    } while (abs(d1) > error);

    /*
    Por ultimo, mostramos el resultado sustituyendo el valor de x en la función con el resultado
    */

    resultado = 2 * (resultado * resultado) + 16 / resultado; //Tambien podria poner d0
    cout << "El resultado es: " << resultado << endl;
}
 