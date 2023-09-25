/*
Minimizar con busqueda aleatoria
Nombre de la institucion: Universidad autonoma de aguascalientes
Nombre del centro: centro de ciencias basicas
Nombre del departamento: ciencias de la computacion
Nombre de la materia: optimizacion
Nombre del alumno: Dante Alejandro Alegria Romero

Descripcion del programa:
Minimizar la funcion drop wave con busqueda aleatoria
Primero generamos dos numeros aleatorios entre -5.12 y 5.12
Despues sustituimos los valores en la funcion drop wave
Despues comparamos el resultado con el valor minimo encontrado
Si el resultado es menor que el valor minimo encontrado, entonces el resultado se convierte en el nuevo valor minimo
Esto se repite 1000 veces
Por ultimo se imprime el valor minimo encontrado

*/
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

float funcion(float x1, float x2)
{
    float resultado;
    resultado =-1*(1 + cos(12*sqrt(pow(x1,2) + pow(x2,2))))/(0.5*(pow(x1,2)+pow(x2,2))+2);
    return resultado;
}

float random()
{
    float resultado;
    resultado = 10.24 * rand() / RAND_MAX - 5.12;
    return resultado;
}

int main()
{
    cout<<"menu"<<endl;
    cout<<"1. Minimizar con busqueda aleatoria"<<endl;
    cout<<"2. Salir"<<endl;
    int opcion;
    cin>>opcion;
    srand(time(NULL));

    float resultado, minimo=1000000;
    float x1,x2;
    if (opcion == 1)
    {
    for (int i = 0; i < 1001; i++)
    {
        x1 = random();
        x2 = random();

        resultado = funcion(x1,x2);
        cout<<"iteracion: "<<i<<endl;
        cout<< "x1: " << x1 <<endl;
        cout<< "x2: " << x2 <<endl;
        cout<<"Resultado: "<<resultado<<endl;
            if (resultado<minimo)
            {
                minimo = resultado;
            }

        cout<<" El valor minimo encontrado es: "<<minimo<<endl;
    }
    }
    else
    {
        cout<<"Adios"<<endl;
    }
}