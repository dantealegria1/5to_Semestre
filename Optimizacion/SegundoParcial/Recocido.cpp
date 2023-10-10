/*
Nombre de la instituciÃ³n: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de básicas
Nombre del departamento al que pertence la carrera: ciencias de la computación 
Nombre de la materia: Optimizaciónn inteligente
Nombre(s) de quien(es) realiza(n) la practica: 
*Dante Alejandro Alegria Romero
*Andrea margarita Balandran Felix
nombre profesor: Luis Fernando GutiÃ©rrez MarfileÃ±o

Breve descripciÃ³n de lo que realiza el programa: 
Cuando hablamos del recocido simulado, nos referimos a un mÃ©todo metaheuristico que nos ayuda a encontrar 
la mejor solucion en problemas de combinatoria y optimizacion. Este metodo se basa en buscar la mejora de 
manera iterativa. El recocido se basa en tres principios:
1. mecanismo de caminada: busqueda de soluciÃ³n de la situaciÃ³n actual
2. mecanismo de soluciÃ³n: un soluciÃ³n sera aceptada si es mejor que la anterior
3. mecanismo de enfriamiento: es la manera en que la temperatura disminuye a lo largo de las iteraciones
el siguiente codigo presenta de manera explicada como es que se emplean cada uno de estos principios por medio 
del uso de distintas librerias que nos ayudaran a encontrar el mejor camino posible para el problema del viajero
donde se busca encontrar la mejor ruta para recorrer 25 ciudades de manera que se recorra la menor distancia posible.
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;
/*
@param x: arreglo que contiene las coordenadas en x de las ciudades
@param y: arreglo que contiene las coordenadas en y de las ciudades
*/
int x[25] = {5, 7, 5, 4, 3, 4, 2, 1, 1, 3, 6, 7, 6, 4, 1, 1, 4, 7, 9, 8, 10, 11, 10, 13, 12};
int y[25] = {4, 4, 6, 3, 6, 5, 4, 3, 5, 2, 3, 7, 1, 1, 7, 7, 7, 2, 2, 5, 4, 1, 7, 6, 8};

/*
@distancia: funcion que nos va a servir para calcular la distancia entre dos ciudades
@param individuo: arreglo que contiene el orden en el que se van a recorrer las ciudades
como funciona:
dentro de un for se van a recorrer las 25 ciudades y se va a calcular la distancia entre cada una de ellas
por medio de la formula de distancia entre dos puntos, se va a sumar la distancia entre cada una de las ciudades
y se va a regresar la distancia 
*/
int distancia(int individuo[25])
{
    int distancia = 0;
    for (int i = 0; i < 25; i++)
    {
        distancia += sqrt(pow(x[individuo[i]] - x[individuo[i + 1]], 2) + pow(y[individuo[i]] - y[individuo[i + 1]], 2));
    }
    return distancia;
}

/*
@mutar: esta funcion nos va ayudar a encontrar una mejor solucion en caso de que la solucion actual no sea la mejor
@param individuo: arreglo que contiene el orden en el que se van a recorrer las ciudades
@param tk: temperatura
@param pos1: posicion aleatoria del primer valor a intercambiar
@param pos2: posicion aleatoria del segundo valor a intercambiar
@param aux: arreglo auxiliar que nos va a ayudar a guardar el individuo actual
como funciona:
como primer paso se van a generar dos posiciones aleatorias que no sean ni la primera ni la ultima posicion
en un while vamos a verificar que no genere aleatorio la primera ni la ultima posicion
despues se va a generar un arreglo auxiliar que va a contener el individuo actual
se va a intercambiar los valores de las posiciones aleatorias
si la distancia del individuo auxiliar es menor a la distancia del individuo actual, se va a cambiar el individuo actual
si la distancia del individuo auxiliar es mayor a la distancia del individuo actual, se va a generar una probabilidad
*/
void mutar(int individuo[25],float tk)
{
    int pos1 = rand() % 25;
    int pos2 = rand() % 25;
    while (pos1 == 0 || pos1 == 25 || pos2 == 0 || pos2 == 25)
    {
        pos1 = rand() % 25;
        pos2 = rand() % 25;
    }
    int aux[25];
    for (int i = 0; i < 25; i++)
    {
        aux[i] = individuo[i];
    }
    swap(aux[pos1], aux[pos2]);
    if (distancia(aux) < distancia(individuo))
    {
        for (int i = 0; i < 25; i++)
        {
            individuo[i] = aux[i];
        }
    }
    else
    {
        int prob = exp((distancia(individuo) - distancia(aux)) / tk);
        int n = rand() % 1;
        if (prob > n)
        {
            for (int i = 0; i < 25; i++)
            {
                individuo[i] = aux[i];
            }
        }
    }
}
/*
@CrearIndividuo: funcion que nos va a ayudar a crear el individuo inicial
@param Individuo: arreglo que contiene el orden en el que se van a recorrer las ciudades
@param valores_disponibles: arreglo que contiene los valores disponibles para generar el individuo
como funciona:
se genera un arreglo de valores disponibles que va a contener los valores del 1 al 25
se genera un individuo aleatorio sin repetir valores y excluyendo el 0
se genra un for que recorre los 25 valores y se van a ir agregando los valores aleatorios al individuo
agrega el valor al individuo como cadena y lo mueve al final
como funciona enfrieamiento:
se genera una temperatura inicial de 1000
se genera un control de 0.8
se genera una temperatura final de 2000
se genera un for que va a recorrer las 2000 iteraciones
se genera un tk que va a ser igual a control*(to/i+1)
se manda a llamar a la funcion mutar
al final: 
imprimimos el individuo final
imprimimos la distancia final
*/
void CrearIndividuo()
{
    int Individuo[25];
    srand(time(NULL));
    int valores_disponibles[24];
    // Generar los valores disponibles exzcuyendo el 0
    for (int i = 0; i < 24; i++) {
        valores_disponibles[i] = i + 1;
    }
    Individuo[25] = 0;
    Individuo[0] = 0;
    // Generar el individuo aleatorio sin repetir valores
    for (int i = 1; i < 25; i++) {
        //Que el primer valor sea 0 
        int indice_aleatorio = rand() % (25 - i); // Elegir un ÃƒÂ­ndice aleatorio entre los valores disponibles
        Individuo[i] = valores_disponibles[indice_aleatorio]; // Agregar el valor al individuo como cadena
        swap(valores_disponibles[indice_aleatorio], valores_disponibles[24 - i]); // Mover el valor usado al final
    }
    cout<<"INDIVIDUO INICIAL:"<<endl;
    for(int i=0;i<26;i++)
    {
        cout<<Individuo[i]<<" ";
    }
    cout<<endl;
    cout<<"DISTANCIA INICIAL:"<<endl;
    cout<<distancia(Individuo)<<endl;
    cout<<endl;
    
    //parte enfriamiento 
    float to=1000;
    float control=0.8;
    float tk;
    for(int i=0;i<2000;i++)
    {
        tk=control*(to/i+1);
        mutar(Individuo,tk);
    }
    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"INDIVIDUO FINAL:"<<endl;
    for(int i=0;i<26;i++)
    {
        cout<<Individuo[i]<<" ";
    }
    cout<<endl;
    cout<<"DISTANCIA FINAL:"<<endl;
    cout<<distancia(Individuo)<<endl;
}
/*
@main: funcion principal
como funciona:
se crea un menu que nos va a ayudar a elegir que queremos hacer
si elegimos la opcion 1, se manda a llamar a la funcion CrearIndividuo
si elegimos la opcion 2, se sale del programa
*/
int main()
{
    int opcion;
    while (true)
    {
        //crear menu }
        cout<<endl;
        cout << "Viajero" << endl;
        cout << "1. Generar Individuo" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
        switch (opcion)
        {
            case 1:
                CrearIndividuo();
                break;
            case 2:
                return 0; // Salir del programa
            default:
                cout << "OpciÃƒÂ³n invÃƒÂ¡lida. Intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
