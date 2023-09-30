/*
Nombre de la instituciÃ³n: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de bÃ¡sicas
Nombre del departamento al que pertence la carrera: ciencias de la computaciÃ³n 
Nombre de la materia: OptimizaciÃ³n inteligente
Nombre(s) de quien(es) realiza(n) la prÃ¡ctica: Dante Alejandro Alegria Romero
Andrea margarita Balandran Felix

Breve descripciÃ³n de lo que realiza el programa: 
El algortimo de las 8 reinas es un problema genetico que consiste en poner 8 reinas 
en posiciones distintas en un tablero de 8x8 y lo que buscamos es que ningunda de estas reinas
compartan ya sea fila columna o diagonal, para esto se utilizan los algoritmos geneticos
donde por medio de la creacion aleatoria de individuos, crearemos, cruzaremos y mutaremos un nÃºmero alto de 
generaciones hasta que en algunas de estas generaciones se encuentre la solucion al problema
y ninguna de las reynas genere choques. 
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
/*
@param filas: numero de filas del tablero
@param columnas: numero de columnas del tablero
@param tamano_Poblacion: numero de individuos que tendra la poblacion
@param Choques_Generacion: arreglo que guarda el numero de choques de cada individuo de la generacion
@param Choques_Generacion_Organizada: arreglo que guarda el numero de choques de cada individuo de la generacion organizada
@param Choques_Generacion_Cortada: arreglo que guarda el numero de choques de cada individuo de la generacion cortada
@param individuos_Organizados: arreglo que guarda los individuos de la generacion organizada
@param individuos_Organizados_Cortados: arreglo que guarda los individuos de la generacion cortada
@param Numero_Individuo: variable que guarda el numero de individuo que se esta creando
@param individuo: arreglo que guarda los individuos de la generacion
@param Siguiente_Generacion: arreglo que guarda los individuos de la siguiente generacion
@param Siguiente_Generacion_Organizada: arreglo que guarda los individuos de la siguiente generacion organizada
@param Choques_Siguiente_Generacion: arreglo que guarda el numero de choques de cada individuo de la siguiente generacion
@param Choques_Siguiente_Generacion_Organizada: arreglo que guarda el numero de choques de cada individuo de la siguiente generacion organizada
@param Gene_Final: arreglo que guarda los individuos de la generacion final
@param Choques_Gene_Final: arreglo que guarda el numero de choques de cada individuo de la generacion final

*/
const int filas = 8;
const int columnas = 8;
const int tamano_Poblacion = 10;
int Choques_Generacion[tamano_Poblacion]; 
int Choques_Generacion_Organizada[tamano_Poblacion];
int Choques_Generacion_Cortada[tamano_Poblacion/2];
string individuos_Organizados[tamano_Poblacion];
string individuos_Organizados_Cortados[tamano_Poblacion/2];
int Numero_Individuo = 0;
string individuo[tamano_Poblacion];
string Siguiente_Generacion[tamano_Poblacion];
string Siguiente_Generacion_Organizada[tamano_Poblacion];
int Choques_Siguiente_Generacion[tamano_Poblacion];
int Choques_Siguiente_Generacion_Organizada[tamano_Poblacion];
string Gene_Final[tamano_Poblacion];
int Choques_Gene_Final[tamano_Poblacion];

/*
@calculo_Choques: funcion que calcula el numero de choques de un individuo
@param diccionario: string que contiene los numeros del 0 al 7
como funcion: 
for filas: dentro de un for se recorre el individuo y se compara cada 
si se encuentra coincidencia en un numero del diccionario con el individuo
se incrementa el numero de choques, sino se elimina el numero del diccionario.
for para diagonal: Despues se recorre el individuo y se resta el numero de cada posicion con el numero 
de la posicion siguiente y si el valor absoluto de la resta es 
igual a la resta de las dos filas es 1 y significa que hay un choque en diagonal. 
*/

int Calculo_Choques(string individuo) {
    int choques = 0;
    string diccionario = "01234567";

    for (int i = 0; i < individuo.length(); i++) {
        char c = individuo[i];
        size_t found = diccionario.find(c);

        if (found != string::npos) {
            diccionario.erase(found, 1);
        } else {
            choques++;
        }
    }

    for (int i = 0; i < individuo.length() - 1; i++) {
        int numero = individuo[i] - '0';  

        for (int j = i + 1; j < individuo.length(); j++) {
            int numero2 = individuo[j] - '0';  

            if (abs(numero - numero2) == abs(i - j)) {
                choques++;
            }
        }
    }

    return choques;
}
/*
@inicializarMatriz: funcion que inicializa la matriz con los individuos
@param matriz: matriz que contiene los individuos
@param IndividuoString: string que contiene el individuo
como funciona: 
primer for: se recorre la matriz y en el int fila se guarda un numero aleatorio del 0 al 7
y se guarda en la matriz en la posicion [fila][i] un 1. con el filastring se guarda el 
numero en un string y se concatena con el individuostring.
depues en @param choques se guarda el calculo de choques del individuo y
 se guarda en el arreglo
*/
string inicializarMatriz(int matriz[filas][columnas]) {
    string IndividuoString = "";

    for (int i = 0; i < columnas; i++) {  
        int fila = rand() % 8;
        matriz[fila][i] = 1;

        string FilaString = to_string(fila);
        IndividuoString += FilaString;
    }

    int choques = Calculo_Choques(IndividuoString);
    Choques_Generacion[Numero_Individuo] = choques;
    individuo[Numero_Individuo] = IndividuoString;
    Numero_Individuo++;

    return IndividuoString;
}
/*
@Organizar: funcion que organiza los individuos de la generacion
@param aux: string auxiliar para guardar el individuo
como funciona:
primer for: se recorre el tamaÃ±o de la poblacion y se guarda en el arreglo de choques
choques_generacion_organizada copia de choques_generacion e individuos_organizados copia de individuo
segundo for: se recorre el tamaÃ±o de la poblacion y se compara 
el numero de choques de cada individuo y lo organiza.
*/
void Organizar() {
    string aux;  

    for (int i = 0; i < tamano_Poblacion; i++) {
        Choques_Generacion_Organizada[i] = Choques_Generacion[i];
        individuos_Organizados[i] = individuo[i];
    }

    for (int i = 0; i < tamano_Poblacion; i++) {
        for (int j = i + 1; j < tamano_Poblacion; j++) {
            if (Choques_Generacion_Organizada[i] > Choques_Generacion_Organizada[j]) {
                int auxChoques = Choques_Generacion_Organizada[i];
                Choques_Generacion_Organizada[i] = Choques_Generacion_Organizada[j];
                Choques_Generacion_Organizada[j] = auxChoques;

                aux = individuos_Organizados[i];
                individuos_Organizados[i] = individuos_Organizados[j];
                individuos_Organizados[j] = aux;
            }
        }
    }
}
/*
@Eliminar_Peores: funcion que elimina los 25 peores individuos de la generacion
como funciona:
for: se recorre la mitad de la poblacion y se guarda en el individuo_organizado_cortado
*/
void Eliminar_Peores() {
    for (int i = 0; i < tamano_Poblacion/2; i++) {
        Choques_Generacion_Cortada[i] = Choques_Generacion_Organizada[i];
        individuos_Organizados_Cortados[i] = individuos_Organizados[i];
    }
}
/*
@para mutar_padre: funcion que muta a los padres de manera aleatoria 
@param padre: string que contiene el padre
como funciona:
como es un string tiene funcionamienot distinto, recibe al padrre y rnadomiza 
un numero del 0 al 7 y numerostring guarda el numero en un string y padre[posicion]=numerostring[0]
*/
string mutar_Padre(string padre)
{
  //muta un numero al azar
    int posicion = rand() % 8;
    int numero = rand() % 8;
    string numeroString = to_string(numero);
    padre[posicion] = numeroString[0];
    return padre;  
}
/*
@cruzar: funcion que cruza a los padres y guarda a los hijos en la siguiente generacion
como funciona:
primer for: se recorre el tamaÃ±o de la poblacion y randomiza en @param cruce un numero del 0 al 7
ahora en madrePos y padrePos se randomiza de acuerdo a la mitad de la poblacion
segundo for: hace una condicion de que si j es menor a cruce se guarda en hijo1 el padre1 en la posicion j
tercer for: hace una condicion de que si j es mayor a cruce se guarda en hijo1 el padre2 en la posicion j
*/

void cruzar() {
    for (int i = 0; i < tamano_Poblacion; i++) {
        int cruce = rand() % 7;
        int padrePos = rand() % tamano_Poblacion/2;
        int madrePos = rand() % tamano_Poblacion/2;
        string hijo1 = "";
        string padre1 = individuos_Organizados_Cortados[padrePos];
        padre1 = mutar_Padre(padre1);
        string padre2 = individuos_Organizados_Cortados[madrePos];
        padre2 = mutar_Padre(padre2);

        for (int j = 0; j < cruce; j++) {
            hijo1 += padre1[j];
        }
        for (int j = cruce; j < padre2.length(); j++) {
            hijo1 += padre2[j];
        }
        Siguiente_Generacion[i] = hijo1;
        Choques_Siguiente_Generacion[i] = Calculo_Choques(hijo1);
    }
}
/*
@organizar_Siguiente_Gen: funcion que organiza los individuos de la siguiente generacion
@param aux: string auxiliar para guardar el individuo
como funciona:
esta funcion nos ayuda a comprara las anteriores versiones organizadas para poder 
sacar una mejorada 
for: sirven para compar entre las dos generaciones y organizarlas
*/
void organizar_Siguiente_Gen() {
    string aux;

    for (int i = 0; i < tamano_Poblacion; i++) {
        Choques_Siguiente_Generacion_Organizada[i] = Choques_Siguiente_Generacion[i];
        Siguiente_Generacion_Organizada[i] = Siguiente_Generacion[i];
    }
    
    for (int i = 0; i < tamano_Poblacion; i++) {
        for (int j = i + 1; j < tamano_Poblacion; j++) {
            if (Choques_Siguiente_Generacion_Organizada[i] > Choques_Siguiente_Generacion_Organizada[j]) {
                int auxChoques = Choques_Siguiente_Generacion_Organizada[i];
                Choques_Siguiente_Generacion_Organizada[i] = Choques_Siguiente_Generacion_Organizada[j];
                Choques_Siguiente_Generacion_Organizada[j] = auxChoques;

                aux = Siguiente_Generacion_Organizada[i];
                Siguiente_Generacion_Organizada[i] = Siguiente_Generacion_Organizada[j];
                Siguiente_Generacion_Organizada[j] = aux;
            }
        }
    }
}
/*
@mutar2: funcion que muta a los individuos de la siguiente generacion
como funciona:
for: agarra 3 individuos al azar y les cambia un numero al azar
agarra los cruces que ya se generaron con anterioridad. entonces se agrega un numero 
aleatorio y lo agrega a la siguiente generacion. este muta hijos 
*/
void mutar2() {
    // Agarra 3 individuos al azar y les cambia un nÃºmero al azar
    for (int i = 0; i < 3; i++) {
        int individuoIndex = rand() % tamano_Poblacion;
        int posicion = rand() % 8;
        int numero = rand() % 8;
        string numeroString = to_string(numero);
        Siguiente_Generacion[individuoIndex][posicion] = numeroString[0];
    }
}
/*
@comparar_Generaciones: funcion que compara las posicion  de la anterior 
y de la siguiente de los hijos.
como funciona:
for: agarra los individuos de la generacion anterior y los compara con los de la siguiente
y si los de la siguiente son menores a los de la anterior se guardan en la generacion final
*/
void comparar_Generaciones() {
    // Si ambas tienen el mismo nÃºmero de choques, muta
    for (int i = 0; i < tamano_Poblacion; i++) {
        if (Choques_Generacion_Organizada[i] == Choques_Siguiente_Generacion_Organizada[i]) {
            mutar2();
        }
    }

    for (int i = 0; i < tamano_Poblacion; i++) {
        if (Choques_Generacion_Organizada[i] < Choques_Siguiente_Generacion_Organizada[i]) {
            Gene_Final[i] = individuos_Organizados[i];
            Choques_Gene_Final[i] = Choques_Generacion_Organizada[i];
        } else {
            Gene_Final[i] = Siguiente_Generacion_Organizada[i];
            Choques_Gene_Final[i] = Choques_Siguiente_Generacion_Organizada[i];
        }
    }
}
/*
@AlgoritmoGenetico: funcion que contiene el algoritmo genetico
como funciona:
manda a llamar a las funciones de mutar2, eliminar_peores, cruzar
y calculo_choques para poder organizar la siguiente generacion y comparar las generaciones
primer for: recorre el tamaÃ±o de la poblacion y manda a llamar a la funcion de 
calculo_choques para poder calcular los choques de la siguiente generacion
segundo for: recorre el tamaÃ±o de la poblacion y muestra los individuos y los choques
if: si el numero de choques es igual a 0, significa que ya encontro la solucion y 
se termina el programa
*/
void AlgoritmoGenetico()
{
    mutar2();
    Eliminar_Peores();
    cruzar();
    for (int i = 0; i < tamano_Poblacion; i++) {
        int choques = Calculo_Choques(Siguiente_Generacion[i]);
        Choques_Siguiente_Generacion[i] = choques;
    }
    organizar_Siguiente_Gen();
    comparar_Generaciones();
    for (int i = 0; i < tamano_Poblacion; i++) {
        cout << "Individuo: " << Gene_Final[i] << " Choques: " << Choques_Gene_Final[i] << endl;
        Choques_Generacion_Organizada[i] = Choques_Gene_Final[i];
        individuos_Organizados[i] = Gene_Final[i];
    }
    if(Choques_Gene_Final[0]==0)
    {
        cout<<"Encontre la solucion"<<endl;
        cout<<"Individuo: " << Gene_Final[0] << " Choques: " << Choques_Gene_Final[0] << endl;
        exit(0);
    }

}
/*
@main: funcion principal
como funciona:
se crea la semilla random, matrices, etc
for: recorre el tamaÃ±o de la poblacion y manda a llamar a la funcion de inicializarMatriz
para poder inicializar la matriz y despues se inicializa el individuo
se mandan a llamar las funciones de organizar, eliminar_peores, cruzar
for de generacion 1: recorre el tamaÃ±o de la poblacion y manda a mostrar el primer generado 
for de generacion 2: recorre el tamaÃ±o de la poblacion y ya comienza a cruzar, mutar y organizar
for 3: manda a llmar cuantas veces sea necesario a la funcion de algoritmo genetico
*/
int main() {
    //crear menu 
    int opciones, NumCorridas=0;
    int generacion = 1;
    srand(time(NULL));
    int matriz[filas][columnas] = {0};
    int sumaChoques = 0;
    //crear menu 
    do{
    cout<<"MENU DE OPCION"<<endl;
    cout<<"1. correr el algoritmo"<<endl;
    cout<<"2. salir"<<endl;
    cin>>opciones;
    switch (opciones)
    {
    case 1:
        //pedir el numero de corridas
        cout<<"Cuantas corridas quieres hacer, debe ser mayor a dos"<<endl;
        cin>>NumCorridas;

         for (int i = 0; i < tamano_Poblacion; i++) {
        string Individuo = inicializarMatriz(matriz);
        Individuo = "";
    }

    Organizar();
    Eliminar_Peores();
    cruzar();

    for (int i = 0; i < tamano_Poblacion; i++) {
        int choques = Calculo_Choques(Siguiente_Generacion[i]);
        Choques_Siguiente_Generacion[i] = choques;
        sumaChoques += choques;
    }

    organizar_Siguiente_Gen();
    comparar_Generaciones();


    cout << "Generacion 1" << endl;
    for (int i = 0; i < tamano_Poblacion; i++) {
        cout << "Individuo: " << individuos_Organizados[i] << " Choques: " << Choques_Generacion_Organizada[i] << endl;
    }

    cout << "Generacion 2" << endl;
    for (int i = 0; i < tamano_Poblacion; i++) {
        cout << "Individuo: " << Gene_Final[i] << " Choques: " << Choques_Gene_Final[i] << endl;
        Choques_Generacion_Organizada[i] = Choques_Gene_Final[i];
        individuos_Organizados[i] = Gene_Final[i];
    }

    for(int i=3;i<NumCorridas;i++)
    {
        cout << "Generacion " << i << endl;
        AlgoritmoGenetico();
    }
    
        break;
    case 2:
        exit(0);
        break;
    }
    }while(opciones!=2);
    return 0;
}