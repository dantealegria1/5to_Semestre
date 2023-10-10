/*
Implementar un programa para obtener el valor minimo de la siguiente funcion:
5x2+3x+2 con un rango de -3 a 3 y un punto de inicio de x0=-0.9
Nombre de la institucion: Universidad autonoma de aguascalientes
Nombre del centro: centro de ciencias basicas
Nombre del departamento: ciencias de la computacion
Nombre de la materia: optimizacion
Nombre del alumno: Dante Alejandro Alegria Romero

Descripcion del programa:

Utilizamos el metodo de newton para encontrar el valor minimo de la funcion
Primero pido el valor de x0 y despues calculo la primera y segunda derivada
Despues sustituyo los valores en la formula de newton y lo guardo en la misma variable
Despues comienzo a comprobar que este valor sea mayor que el error para poder seguir 
sustituyendo los valores en las derivadas
hasta que el valor de "resultado" sea menor al error
Por ultimo el valor final lo sustituyo en la funcion principal que es la xo para obtener el minimo encontrado

*/

/* Incluimos las librerias necesarias */
#include <iostream>
#include <math.h>

using namespace std;

/*
Creamos una funcion que pida x0
*/
float pedir_x0()
{
    float x0;
    cout<<"Ingrese el valor de x0: ";
    cin>>x0;
    return x0;
}
/*
Creamos una funcion que calcule el valor minimo de la funcion
*/
int Newton()
{
    float x0 = pedir_x0();
    float d0,d1,d2;
    float resultado;
    int iteracion = 0;
    float error = 0.0001;

    cout <<"Iteración |       d0       |       d1       |       d2       |    resultado" <<endl;
    cout <<"---------------------------------------------------------------------------" <<endl;
    do{
        iteracion++;

        d0 = 5*(x0*x0)+3*x0-2;
        d1 = 10*x0+3;
        d2 = 10;
        x0 = x0 - (d1/d2);
        cout <<  "    " << iteracion << "     |    " << d0 << "    |    " << d1 << "    |    " << d2 << "    |    " << resultado << endl;
    }while (abs(d1)>error);

    resultado = 5*(x0*x0)+3*x0-2;
    cout << "El valor minimo es: " << resultado << endl;
    return resultado;
}

/*
Creamos el menu para que el usuario pueda elegir que hacer
*/
int main()
{
    int opcion;
    cout<<"La funcion objetivo es: 5x2+3x-2"<<endl;
    cout<<"Su primer derivada es: 10x+3"<<endl;
    cout<<"Su segunda derivada es: 10"<<endl;

    do{
        cout<<"menu"<<endl;
        cout<<"1.- Calcular el valor minimo"<<endl;
        cout<<"2.- Salir"<<endl;
        cin>>opcion;
        
        if (opcion==1)
        {
            Newton();
        }
        else if (opcion==2)
        {
            cout<<"Gracias por usar el programa"<<endl;
        }
        else
        {
            cout<<"Opcion no valida"<<endl;
        }

    }while (opcion!=2);
}