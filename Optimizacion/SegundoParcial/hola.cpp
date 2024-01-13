/*
Resolver el problema utilizando un algoritmo genético el procedimiento es:
Generar una población inicial de 50 individuos en forma aleatoria
Mediante la función de evaluación seleccionar a los 10 mejores individuos
Para la siguiente población cada pareja de padres deberá procrear diez hijos, los cuales integran la siguiente generación con un punto de cruce a la mitad del cromosoma.
Agregar una mutación de un individuo por generación, el punto de mutación debe ser aleatorio.
Determinar soluciones posibles considerando 10 poblaciones
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
//Creo una lista de string para guardar los individuos
string Individuos[51];
string Nueva_Generacion[51];
int Choques_Generacion[51];
int Choques_Ordenados[51];
int Choques_Segunda_Generacion[51];
int Choques_Segunda_Generacion_Ordenados[51];

int Choques(string Individuo)
{
    int Choques = 0;
    for(int i = 0; i < 8; i++)
    {
        int n = Individuo[i] - '0';
        for(int j = i+1; j < 8; j++)
        {
            int m = Individuo[j] - '0';
            if(n == m)
            {
                Choques++;
            }
        }
    }
    return Choques;
}
