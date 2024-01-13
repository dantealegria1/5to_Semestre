#include <iostream>
#include <math.h>
using namespace std;

//De momento funciona 
void EliminarTrabajo(int jobs[3][3], int trabajo)
{
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(jobs[i][j] == trabajo)
            {
                jobs[i][j] = 9;
            }
        }
    }
}
//Probabilidad de ir a un trabajo
float CalcularProbabilidad(int feromona, int tiempo,int SumaFeromonas)
{
    float probabilidad = 0;
    //probabilidad = (feromona * pow(1.0f / tiempo, 2));
    probabilidad = (feromona*pow(1.0f/tiempo,2))/(SumaFeromonas*pow(1.0f/tiempo,2));
    return probabilidad;
}
//Suma de los tiempos
int SumaTiempos(int tiempos[3][3])
{
    int suma = 0;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            suma += tiempos[i][j];
        }
    }
    return suma;
}

int SumaFeromonas(int Feromonas[3][3])
{
    int suma = 0;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            suma += Feromonas[i][j];
        }
    }
    return suma;
}
//Buscar el camino
int BuscarCamino(int jobs[3][3],int tiempos[3][3],int TrabajoActual,int CaminoActual[3][3])
{
    float mayor = 0.1;
    int caminos[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};

    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(jobs[i][j] != TrabajoActual && jobs[i][j] != 9 )
            {
                caminos[i][j] = 1;
            }
        }
    } 
    int Cono = 0;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(caminos[i][j] == 1)
            {
                Cono++;
            }
        }
    }
    if(Cono == 0)
    {
        //agregamos caminos posibles 
        caminos[0][0] = 1;
        caminos[1][1] = 1;
    }
    float probabilidad[3][3] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(caminos[i][j] == 1)
            {
                probabilidad[i][j] = CalcularProbabilidad(1,tiempos[i][j],SumaFeromonas(CaminoActual));
                if(probabilidad[i][j] > mayor)
                {
                    probabilidad[i][j] = mayor+.1;
                    mayor = probabilidad[i][j];

                }
            }
        }
    }

    //Pongo como 1 el camino con mayor probabilidad
    int conteo = 0;
    while(conteo < 4)
    {
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(probabilidad[i][j] == mayor)
                {
                    CaminoActual[i][j] = 1;
                    conteo++;
                }
            }
        }
    }

    //Imprimo el camino actual
    cout<<"Camino actual: "<<endl;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            cout<<CaminoActual[i][j]<<" ";
            for(int k = 0; k<3;k++)
            {
                if(CaminoActual[i][j] == 1)
                {
                    TrabajoActual = jobs[i][j];
                }
            }
        }
        cout<<endl;
    }

    //retorno el trabajo actual
    return TrabajoActual;
}
int Hormiguita(int jobs[3][3], int tiempos[3][3])
{

    int camino[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};
    int random = rand() % 2;
    int trabajoActual = jobs[random][0];
    camino[random][0] = 1;

    EliminarTrabajo(jobs,trabajoActual);

    //Caminos posibles
    trabajoActual = BuscarCamino(jobs,tiempos,trabajoActual,camino);
    //Actualizo mis feromonas
    BuscarCamino(jobs,tiempos,trabajoActual,camino);
    int costeTiempo = 0;
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(camino[i][j] == 1)
            {
                costeTiempo += tiempos[i][j];
            }
        }
    }
    return costeTiempo;
}

int main(){
    srand(time(NULL));

    int costeMinimo = 999;
    int jobs[3][3] = {{1, 2, 3},
                    {3, 1, 9},
                    {9, 2, 1}};

    int tiempos[3][3] = {{3, 4, 3},
                        {2, 3, 9},
                        {9, 3, 2}};

    int Feromonas[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};


for(int i = 0; i<50;i++)
{
        int coste = Hormiguita(jobs,tiempos);
        if(coste < costeMinimo)
        {
            costeMinimo = coste;
        }
}
    
    
    cout<<"Coste minimo: "<<costeMinimo<<endl;
}