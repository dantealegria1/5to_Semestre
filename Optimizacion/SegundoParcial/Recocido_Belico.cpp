//Recocido simuladdo
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;

int x[25] = {5, 7, 5, 4, 3, 4, 2, 1, 1, 3, 6, 7, 6, 4, 1, 1, 4, 7, 9, 8, 10, 11, 10, 13, 12};
int y[25] = {4, 4, 6, 3, 6, 5, 4, 3, 5, 2, 3, 7, 1, 1, 7, 7, 7, 2, 2, 5, 4, 1, 7, 6, 8};
int individuo[26] = {0};
int T = 100;
float c = 0.8;
int iteraciones = 0;
int Estancamiento = 0;

float TK(int iteraciones)
{
    int gengar = iteraciones/5;
    return (T /(1+ gengar))*c;
}

float Distancia(int individuo[26])
{
    int distancia = 0;
    //Acuerdate que 25 por que al final compara la ciudad 25 con la 26 que es la 0
    for(int i = 0; i < 25; i++)
    {
        distancia += sqrt(pow(x[individuo[i]] - x[individuo[i+1]], 2) + pow(y[individuo[i]] - y[individuo[i+1]], 2));
    }
    return distancia;
}

void NuevoIndividuo(int individuo[26])
{

    int aux[26];
    int pos1 = rand() % 25;
    int pos2 = rand() % 25;
    while(pos1 == 0 || pos1 == 25 || pos2 == 0 || pos2 == 25)
    {
        pos1 = rand() % 25;
        pos2 = rand() % 25;
    }
    for(int i = 0; i < 26; i++)
    {
        aux[i] = individuo[i];
    }
    aux[pos1] = individuo[pos2];
    aux[pos2] = individuo[pos1];

    if(Distancia(aux) < Distancia(individuo))
    {
        for(int i = 0; i < 26; i++)
        {
            individuo[i] = aux[i];
        }
        Estancamiento = 0;
    }else
    {
        float probabilidad = exp((Distancia(individuo) - Distancia(aux))/TK(iteraciones));
        float aleatorio = rand() % 100;
        aleatorio = aleatorio/100;
        if(probabilidad > aleatorio)
        {
            for(int i = 0; i < 26; i++)
            {
                individuo[i] = aux[i];
            }
            Estancamiento = 0;
        }else
        {
            Estancamiento++;
        }
    }
    iteraciones++;

}

void Recocido(int individuo[26])
{
    int posicion = 0;
    
    for(int i = 1; i < 26; i++)
    {
        int numero = 26-i;
        while(individuo[posicion] != 0)
        {
            posicion = rand() % 25;
        }
        individuo[posicion] = numero;
    }

    individuo[0] = 0;

    cout << "Individuo: ";
    for(int i = 0; i < 26; i++)
    {
        cout << individuo[i] << " ";
    }
    cout<<Distancia(individuo)<<endl;
    cout << endl;
    while(Estancamiento < 100 && iteraciones < 10000)
    {
        NuevoIndividuo(individuo);
    }
    cout << "Individuo final: ";
    for(int i = 0; i < 26; i++)
    {
        cout << individuo[i] << " ";
    }
    if(iteraciones < 10000)
    iteraciones = iteraciones - 100;
    cout<<"iteraciones: "<<iteraciones<<endl;
    cout<<Distancia(individuo)<<endl;
    cout << endl;
}

int main()
{
    srand(time(NULL));
    Recocido(individuo);
    return 0;
}