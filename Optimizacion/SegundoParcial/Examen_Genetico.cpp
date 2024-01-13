/*
¿De cuántas formas se pueden colocar ocho torres 
en el tablero de ajedrez de manera que no se ataquen mutuamente?
¿De cuántas formas se pueden colocar ocho t
orres en el tablero de ajedrez de manera que no se ataquen mutuamente?
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
//Creo una lista de string para guardar los individuos
string Individuos[51];
string Nueva_Generacion[1000];
int Choques_Generacion[51];
int Choques_Ordenados[51];
int Choques_Segunda_Generacion[1000];
int Choques_Segunda_Generacion_Ordenados[1000];

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

string CrearIndividuo()
{
    string Individuo = "";
    for(int i = 0; i < 8; i++)
    {
        int n = rand() % 8;
        Individuo.append(to_string(n));
    }
    return Individuo;
}
void Cruzar()
{
    //Cruzar los 25 mejores
    for(int i = 0; i<26;i++)
    {
        int cruce = rand() % 8;
        string NuevoIndiiduo = "";
        string NuevoIndiiduo2 = "";
        NuevoIndiiduo.append(Individuos[i].substr(0,cruce));
        NuevoIndiiduo.append(Individuos[i+25].substr(cruce,8));
        NuevoIndiiduo2.append(Individuos[i+25].substr(0,cruce));
        NuevoIndiiduo2.append(Individuos[i].substr(cruce,8));
        Nueva_Generacion[i] = NuevoIndiiduo;

    }
}


int main()
{
    srand(time(NULL));
    //Primer generacion
    cout<<"Sin ordenar"<<endl;
    for(int i = 0; i<51;i++)
    {
        Individuos[i] = CrearIndividuo();
        Choques_Generacion[i] = Choques(Individuos[i]);
    }
    cout<<""

    return 0;
}