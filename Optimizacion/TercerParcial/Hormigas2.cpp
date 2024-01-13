#include <iostream>
#include <math.h>

using namespace std;

    int alpha = 1;
    int betaa = 2;
    int parametroEvaporacion = 10;
    int NumeroHormigas = 50;
    int T = 0;


float CalcularProbabilidad(int feromona, int tiempo)
{
    float probabilidad = 0;
    probabilidad = (feromona * pow(1.0f / tiempo, betaa));
    return probabilidad;
}


void Hormigas(int jobs[3][3],int tiempos[3][3],int feromonas[3][3])
{

    int random = rand() % 3;
    int nodoActual = jobs[random][0];
    cout<<"Nodo actual: "<<nodoActual<<endl;
    bool visitados[3][3] = {{false, false, false},
                            {false, false, false},
                            {false, false, false}};
    visitados[random][0] = true;
    feromonas[random][0] = 35;
    //Caminos posibles
    int caminos[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};

    caminos[random][1] = 1;

    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(jobs[i][j] == nodoActual)
            {
                if(i != random)
                {
                    caminos[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            cout<<caminos[i][j]<<" ";
        }
        cout<<endl;
    }
    //Calculo de probabilidad
    float probabilidad[3][3] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(caminos[i][j] == 1)
            {
                probabilidad[i][j] = CalcularProbabilidad(feromonas[i][j], tiempos[i][j]);
            }
        }
    }
    cout<<"Probabilidad: "<<endl;
    float mayorProbabilidad = 0;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            cout<<probabilidad[i][j]<<" ";
            if(probabilidad[i][j] > mayorProbabilidad)
            {
                mayorProbabilidad = probabilidad[i][j];
            }
        }
        cout<<endl;
    }


    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(probabilidad[i][j] == mayorProbabilidad)
            {
                feromonas[i][j] = feromonas[i][j] + parametroEvaporacion;
            }
        }
    }
    
    cout<<"Feromonas: "<<endl;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            cout<<feromonas[i][j]<<" ";
        }
        cout<<endl;
    }

    //Decisión de camino
    
}

int main() 
{
    srand(time(NULL));

    int alpha = 1;
    int beta = 2;
    int parametroEvaporacion = 10;
    int NumeroHormigas = 50;
    int T = 0;

    int jobs[3][3] = 
    {
    {1, 2, 3},  
    {3, 3, 1},  
    {2, 2, 2}   
    };

    int tiempos[3][3] = 
    {
    {3, 3, 3},  
    {2, 3, 4},  
    {3, 3, 2}   
    };

    int feromonas[3][3] = 
    {
    {1, 1, 1},  
    {1, 1, 1},  
    {1, 1, 1}   
    };

    Hormigas(jobs, tiempos, feromonas);
}