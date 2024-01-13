
/*
Pasos
Para elegir la ciudad a donde ir ------------------------
La distancia entre las ciudades
La suma de las distancias entre las ciudades
Divido el valor de la distancia entre las ciudades entre la suma de las distancias
entre las ciudades, asi hasta acabar el recorrido, esto es para elegir a donde ir
Saco el coste de todo el recorrido
Para actualizar las feromonas --------------------------
Dependiendo del coste de todo el recorrido, se actualiza la feromona entre mas bajo
sea el coste mayor la cantidad de feromonas
Para actualizar las feromonas es (1-p)Tij + 1/Lk
p es la evaporacion de las feromonas es una constante
Lk es el coste del recorrido pero de todo el recorrido
Si ese nodo no fue visitado entonces solo es 1-pTij
*/
#include <iostream>
#include <vector>

using namespace std;

int CiudadSiguiente(float Ciudad[])
{
    float posibilidades[7];
    for(int i=0; i<7; i++)
    {

            posibilidades[i] = 1/Ciudad[i];
    }
    float suma = 0;
    for(int i=0; i<7; i++)
    {
        if(posibilidades[i] != 0 && posibilidades[i] < 10000)
        {
            suma += posibilidades[i];
        }
    }
    for(int i=0; i<7; i++)
    {
        if(posibilidades[i] != 0 && posibilidades[i] < 10000)
        {
            posibilidades[i] = posibilidades[i]/suma;
        }
    }
    float aleatorio = rand()%100;
    float acumulado = 0;
    int ciudad = 0;
    aleatorio = aleatorio/100;
    cout<<aleatorio<<endl;
    for(int i=0; i<7; i++)
    {
        if(posibilidades[i] != 0 && posibilidades[i] < 10000)
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

int main()
{
    srand(time(NULL));
    //Distancias entre las ciudades
    float Ciudad1[7] = {0, 5, 3.1, 0, 0,5.2,0};
    float Ciudad2[7] = {5, 0, 4.9, 0, 0, 0, 5.2};
    float Ciudad3[7] = {3.1, 4.9, 0, 0, 6, 3.2, 3};
    float Ciudad4[7] = {0, 0, 0, 0, 5.5, 0, 4.8};
    float Ciudad5[7] = {0, 0, 6, 5.5, 0, 4.8, 0};
    float Ciudad6[7] = {5.2, 0, 3.2, 0, 4.7, 0, 0};
    float Ciudad7[7] = {0, 5.2, 3, 4.8, 0, 0, 0};

    //inicio en la ciudad 1
    int inicio = 1;
    //fin en la ciudad 4
    int fin = 4;
    //cantidad de hormigas
    int hormigas = 10;
    //cantidad de iteraciones
    int iteraciones = 10;
    //constante de evaporacion
    float p = 0.5;
    //cantidad de feromonas
    int recorrido[7];
    recorrido[0] = inicio;
    recorrido[6] = fin;
    recorrido[1] = CiudadSiguiente(Ciudad1);
    //Si ya paso por esa ciudad ya no puede volver a pasar por ella
    
    
}