#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

//Creamos mis constantes para el problema que son las filas y columnas
// @param filas: numero de filas del tablero
// @param columnas: numero de columnas del tablero
// @param tamano_Poblacion: numero de individuos que va a tener la poblacion
// @param Choques_Generacion: numero de choques que tiene cada individuo de la generacion
// @param Choques_Generacion_Organizada: numero de choques que tiene cada individuo de la generacion organizada
// @param Choques_Generacion_Cortada: numero de choques que tiene cada individuo de la generacion cortada
// @param individuos_Organizados: individuos de la generacion organizada
// @param individuos_Organizados_Cortados: individuos de la generacion cortada
// @param Numero_Individuo: numero de individuo que se esta creando
// @param individuo: individuo que se esta creando

const int filas = 8;
const int columnas = 8;
const int tamano_Poblacion = 50;
int Choques_Generacion[tamano_Poblacion]; 
int Choques_Generacion_Organizada[tamano_Poblacion];
int Choques_Generacion_Cortada[tamano_Poblacion/2];
string individuos_Organizados[tamano_Poblacion];
string individuos_Organizados_Cortados[tamano_Poblacion/2];
int Numero_Individuo = 0;
string individuo[tamano_Poblacion];
string Siguiente_Generacion[tamano_Poblacion];


//Funcion para convertir un numero a binario
// @param numero: numero que se desea convertir a binario pero en string
// @return binarioString: numero convertido a binario pero en string
// @param exp: exponente que se utiliza para convertir el numero a binario
// @param binario: numero binario pero en entero
// @param numero_Int: numero que se desea convertir a binario pero en entero

//Primero converitmos el numero a entero para poder operar con el
//Despues hacemos la operacion para convertirlo a binario
//Despues lo convertimos a string para, esto para poder agregar los 0's que le faltan
//Finalmente lo retornamos

string Binario(string numero)
{
    string binarioString = "";
    int binario = 0;
    int exp = 0;
    int numero_Int = stoi(numero);
    while(numero_Int > 0){
        binario += (numero_Int%2) * pow(10, exp);
        exp++;
        numero_Int /= 2;
    }
    
    binarioString = to_string(binario);
    if(binarioString.length() == 1){
        binarioString = "00"+binarioString;
    }else if(binarioString.length() == 2){
        binarioString = "0"+binarioString;
    }
    return binarioString;
}

//Funcion para calcular los choques de un individuo
// @param individuo: individuo que se desea calcular los choques
// @param choques: numero de choques que tiene el individuo
// @param diccionario: diccionario que se utiliza para saber si el individuo tiene numeros repetidos
// @param c: caracter que se utiliza para saber si el individuo tiene numeros repetidos
// @param found: variable que se utiliza para saber si el individuo tiene numeros repetidos

//Primero inicializo el diccionario con los numeros del 0 al 7 que son los que son los valores posibles de las reinas
//Despues itero sobre el individuo para saber si tiene numeros repetidos, esto lo hago con la funcion find
//Si el caracter no se encuentra en el diccionario, entonces se aumenta el numero de choques
//Si el caracter se encuentra en el diccionario, entonces se elimina del diccionario

//La segunda parte del codigo es para saber si hay choques en las diagonales
//Primero convierto el caracter a entero para poder operar con el
//Despues itero sobre el individuo para saber si hay choques en las diagonales esto lo hago con la funcion abs
//Resto el numero de la columna con el numero de la columna de la siguiente reina, si el resultado es igual a la resta de la fila con la fila de 
//la siguiente reina, entonces hay choques
//Si hay choques en las diagonales, entonces se aumenta el numero de choques

int Calculo_Choques(string individuo)
{   int choques = 0;
    string diccionario="01234567";
    for (int i = 0; i < individuo.length(); i++)
    {
        char c = individuo[i];
        size_t found = diccionario.find(c);
        if(found != string::npos)
        {
            diccionario.erase(found,1);
        }
        else
        {
            choques++;
        }
    }

    for (int i = 0; i < individuo.length() - 1; i++)
    {
        int numero = individuo[i] - '0';  
        for(int j = i+1; j < individuo.length(); j++)
        {
            int numero2 = individuo[j] - '0';  
            if(abs(numero - numero2) == abs(i - j))
            {
                choques++;
            }
        }
    }
    return choques;
}

//Funcion para inicializar la matriz
// @param matriz: matriz que se desea inicializar
// @param Individuo: individuo que se desea crear
// @param IndividuoString: individuo que se desea crear pero en string
// @param FilaString: es la fila donde se encuentra la reina en esa columna pero en string
// @param fila: es la fila donde se encuentra la reina en esa columna pero en entero

//Primero inicializo la matriz con 0's
//Despues creo un numero aleatorio para cada columna que es la posicion de la reina
//Despues convierto el numero a binario para poder agregarlo al individuo
//Despues agrego el numero a mi individuo

string inicializarMatriz(int matriz[filas][columnas]) {

    string Individuo = "";
    string IndividuoString = "";

    for (int i = 0; i < columnas; i++) {  
        int fila = rand() % 8;
        matriz[fila][i] = 1;

        string FilaString = to_string(fila);
        IndividuoString = IndividuoString + FilaString;
        FilaString = Binario(FilaString);
        Individuo = Individuo + FilaString;
    }
    int choques = Calculo_Choques(IndividuoString);
    Choques_Generacion[Numero_Individuo] = choques;
    individuo[Numero_Individuo] = Individuo;
    Numero_Individuo++;
    return Individuo;
}

//Ordenar la poblacion de menor a mayor choques
//Vamos a ir comparando, y organizando en Choques_Generacion_Organizada 
// Modificada para organizar los individuos junto con los choques
// @param aux: variable auxiliar para hacer el intercambio de los choques y los individuos

//Primero copio los choques de la generacion a Choques_Generacion_Organizada
//Despues itero sobre Choques_Generacion_Organizada para poder ordenarla
//Si el numero de choques de la posicion i es menor al numero de choques de la posicion j, entonces se intercambian
//Ahora Individuos_Organizados[i] es igual a Individuos_Organizados[j] y viceversa

void Organizar()
{
    int aux;
    for(int i = 0; i < tamano_Poblacion; i++)
    {
        Choques_Generacion_Organizada[i] = Choques_Generacion[i];
    }
    for(int i = 0; i < tamano_Poblacion; i++)
    {
        for(int j = i+1; j < tamano_Poblacion; j++)
        {
            if(Choques_Generacion_Organizada[i] > Choques_Generacion_Organizada[j])
            {
                aux = Choques_Generacion_Organizada[i];
                Choques_Generacion_Organizada[i] = Choques_Generacion_Organizada[j];
                Choques_Generacion_Organizada[j] = aux;
                individuos_Organizados[i] = individuo[j];
                individuos_Organizados[j] = individuo[i];
            }
        }
    }
}

//Aqui Eliminamos los peores, esto lo hacemos dividiendo el tamano de la poblacion entre 2
//y de la generacion organizada, copiamos la primera mitad a Choques_Generacion_Cortada

void Eliminar_Peores()
{
    for(int i = 0; i < tamano_Poblacion/2; i++)
    {
        Choques_Generacion_Cortada[i] = Choques_Generacion_Organizada[i];
        individuos_Organizados_Cortados[i] = individuos_Organizados[i];
    }
}

void cruzar()
{
    for(int i = 0; i < tamano_Poblacion/2; i++)
    {
        int cruce = 11;
        string hijo1 = "";
        string hijo2 = "";
        string padre1 = individuos_Organizados_Cortados[i];
        string padre2 = individuos_Organizados_Cortados[tamano_Poblacion/2 - i - 1];
        //Tomamos la primera mitad del padre 1 y la segunda del padre 2
        for(int j = 0; j < cruce; j++)
        {
            hijo1 = hijo1 + padre1[j];
        }
        for(int j = cruce; j < padre2.length(); j++)
        {
            hijo1 = hijo1 + padre2[j];
        }
        //Tomamos la primera mitad del padre 2 y la segunda del padre 1
        for(int j = 0; j < cruce; j++)
        {
            hijo2 = hijo2 + padre2[j];
        }
        for(int j = cruce; j < padre1.length(); j++)
        {
            hijo2 = hijo2 + padre1[j];
        }
        //Agregamos los hijos a la siguiente generacion
        Siguiente_Generacion[i] = hijo1;
        Siguiente_Generacion[tamano_Poblacion/2 - i - 1] = hijo2;
    }
}
//Funcion main
// @param matriz: matriz que se desea inicializar

//Primero inicializo la matriz con 0's
//Despues creo mi individuo muchas veces para generar la poblacion
//Despues organizo la poblacion
//Despues elimino los peores que son los 25 con mas errores
//Finalmente imprimo los 25 mejores
//*Baila como en el fornite*

int main() 
{
    srand(time(NULL));
    int matriz[filas][columnas] = {0};
    string Generacion_Final[tamano_Poblacion];

    for (int i = 0; i < tamano_Poblacion; i++) 
    {
        string Individuo = inicializarMatriz(matriz);
        Individuo = "";
    }

    Organizar();
    Eliminar_Peores();
    cout<<"Generacion 1"<<endl;
    for(int i = 0; i < tamano_Poblacion/2; i++)
    {
        cout << "Individuo: " << individuos_Organizados_Cortados[i] << endl;
        cout << "Choques: " << Choques_Generacion_Cortada[i] << endl;
    }
    cout<<"Generacion 2"<<endl;
    cruzar();
    for(int i = 0; i < tamano_Poblacion/2; i++)
    {
        cout << "Individuo: " << Siguiente_Generacion[i] << endl;
    }
    
    cout<<"Comparamos"<<endl;
    cout<<individuos_Organizados_Cortados[0]<<endl;
    cout<<Siguiente_Generacion[0]<<endl;
    return 0;
}
//0101010100101}{2}