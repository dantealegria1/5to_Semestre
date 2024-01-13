/*
Se tiene una instancia del problema del agente viajero con 10 ciudades, 
el objetivo es encontrar el menor recorrido, en el que, partiendo de una ciudad se 
pase una vez por todas las demás y se regrese a la ciudad inicial.
Dante Alejandro Alegria Romero
Al265853
Universidad Automoma de Aguascalientes
Optimizacion Inteligente
Centro de Ciencias Basicas
Luis Fernando Marfileño
*/
#include <iostream>
#include <math.h>

using namespace std;

float CalcularDistancia(int ciudadesX[], int ciudadesY[], int n, int m)
{
    float distancia = 0;
    distancia += sqrt(pow(ciudadesX[n]-ciudadesX[m],2)+pow(ciudadesY[n]-ciudadesY[m],2));
    return distancia;
}

float Probabilidad(int n, int m, float Feromonas[], float alpha, float beta, int ciudadesX[], int ciudadesY[])
{
    float probabilidad = 0;
    float Distancia = CalcularDistancia(ciudadesX,ciudadesY,n,m);
    if(Distancia == 0)
    {
        return 0;
    }else{
        probabilidad += pow(Feromonas[n],alpha)*pow(1/Distancia,beta);
    }
    return probabilidad;
}

int CiudadSiguiente(float Feromonas[], float alpha, float beta, int ciudadesX[], int ciudadesY[], int n)
{
    float posibilidades[10];
    for(int i=0; i<10; i++)
    {
        posibilidades[i] = Probabilidad(n,i,Feromonas,alpha,beta,ciudadesX,ciudadesY);
    }
    float suma = 0;
    for(int i=0; i<10; i++)
    {
        if(posibilidades[i] != 0)
        {
            suma += posibilidades[i];
        }
    }
    for(int i=0; i<10; i++)
    {
        if(posibilidades[i] != 0)
        {
            posibilidades[i] = posibilidades[i]/suma;
        }
    }
    float aleatorio = rand()%100;
    float acumulado = 0;
    int ciudad = 0;
    aleatorio = aleatorio/100;
    for(int i=0; i<10; i++)
    {
        if(posibilidades[i] != 0)
        {
            acumulado += posibilidades[i];
            if(aleatorio <= acumulado)
            {
                ciudad = i;
                break;
            }
        }
    }
    return ciudad;
}

void Evaporacion(float Feromonas[], float p, int m)
{
    for(int i=0; i<10; i++)
    {
        if(Feromonas[i] < 0)
        {
            Feromonas[i] = 0;
        }
        Feromonas[i] = Feromonas[i]*(1-p);
    }
    Feromonas[m] = Feromonas[m]*(1+p);;	
}
void DepositarFeromonas(float Feromonas[], float Q, float Distancia,int camino[11], int i)
{
    //Deposito las feromonas solo en el primer 
    //Si la distancia es menor a 25 le sumo mucha feromona
    if(Distancia < 25)
    {
        Q = Q*3;
    }
    Feromonas[camino[i]] += Q/Distancia;
}
string AntSystem(int m,string Soluciones[200][200],int i,int ciudadesX[], int ciudadesY[], int ciudadesX2[], int ciudadesY2[],float Feromonas[], float alpha, float beta, float p, float Q, int iteraciones)
{
    int Camino[11];
    Camino[0] = 0;
    Camino[11] = 0;

    ciudadesX[0] = 0;
    ciudadesY[0] = 0;

    for(int i=0;i<10;i++)
    {
        Camino[i+1] = CiudadSiguiente(Feromonas,alpha,beta,ciudadesX,ciudadesY,Camino[i]);
        ciudadesX[Camino[i+1]] = 0;
        ciudadesY[Camino[i+1]] = 0;
    }
    float Distancia = 0;
    for(int i=0;i<10;i++)
    {
        Distancia += CalcularDistancia(ciudadesX2,ciudadesY2,Camino[i],Camino[i+1]);
    }
    string CaminoString = "";
    for(int i=0;i<11;i++)
    {
        CaminoString += to_string(Camino[i])+" ";
    }
    //Deposito  feromonas dependiendo de la calidad de la solucion
    DepositarFeromonas(Feromonas,Q,Distancia,Camino,m);
    //Evaporo las feromonas
    Evaporacion(Feromonas,p,m);
    //Guardo la solucion
   
    if(i>0)
    {
        if(abs(stof(Soluciones[i-1][1])-Distancia)>3)
        {
            Distancia = stof(Soluciones[i-1][1]);
        }
    }
    Soluciones[i][1] = to_string(Distancia);
    Soluciones[i][0] = CaminoString;
    return CaminoString;
}  

int main()
{
    string Soluciones[200][200];

    srand(time(NULL));
    

    //Numero de Hormigas
    int numHormigas = 5;

    //Feromonas en cada ciudad
    float Feromonas[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    //Valor de evaporacion de las feromonas
    float p = 0.5;

    //Valor de feromonas depositadas por cada hormiga
    float Q = 5;

    //alpha y beta
    float alpha = 1;
    float beta = 2;
    int hola = 0;
    int opcion;
    //Lo corremos 100 vecesclea
    while(opcion != 2)
    {
    cout<<"Menu"<<endl;
    cout<<"1.- Correr 200 veces"<<endl;
    cout<<"Sallir"<<endl;
    //pido el valor de opcion
    cin>>opcion;

    if(opcion == 1)
    {
        cout<<"Corriendo 200 veces"<<endl;
        for(int i=0;i<200;i++)
    {
        int ciudadesX[] = {5, 7, 5, 4, 3, 4, 2, 1, 1, 3};
        int ciudadesY[] = {4, 4, 6, 3, 6, 5, 4, 3, 5, 2};

        int ciudadesX2[] = {5, 7, 5, 4, 3, 4, 2, 1, 1, 3};
        int ciudadesY2[] = {4, 4, 6, 3, 6, 5, 4, 3, 5, 2};
        if(hola>9)
        {
            hola = 0;
        }
        AntSystem(hola,Soluciones,i,ciudadesX,ciudadesY,ciudadesX2,ciudadesY2,Feromonas,alpha,beta,p,Q,i);
        hola++;
    }
    //Imprimimos la ultima solucion
    cout<<"Solucion: "<<Soluciones[199][0]<<endl;
    cout<<"Distancia: "<<Soluciones[199][1]<<endl;
    }
    else
    {
        cout<<"Saliendo"<<endl;
    }
    }
}