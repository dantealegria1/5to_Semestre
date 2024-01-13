/*
Nombre de la instituciÃ³n: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de bÃ¡sicas
Nombre del departamento al que pertence la carrera: ciencias de la computaciÃ³n 
Nombre de la materia: OptimizaciÃ³n inteligente
Nombre(s) de quien(es) realiza(n) la prÃ¡ctica: Dante Alejandro Alegria Romero

Breve descripciÃ³n de lo que realiza el programa: 

Verifica la posicion de las torres 

*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

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
string Siguiente_Generacion_Organizada[tamano_Poblacion];
int Choques_Siguiente_Generacion[tamano_Poblacion];
int Choques_Siguiente_Generacion_Organizada[tamano_Poblacion];
string Gene_Final[tamano_Poblacion];
int Choques_Gene_Final[tamano_Poblacion];



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


    return choques;
}

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

void Eliminar_Peores() {
    for (int i = 0; i < tamano_Poblacion/2; i++) {
        Choques_Generacion_Cortada[i] = Choques_Generacion_Organizada[i];
        individuos_Organizados_Cortados[i] = individuos_Organizados[i];
    }
}

string mutar_Padre(string padre)
{
  //muta un numero al azar
    int posicion = rand() % 8;
    int numero = rand() % 8;
    string numeroString = to_string(numero);
    padre[posicion] = numeroString[0];
    return padre;  
}


void cruzar() {
    for (int i = 0; i < tamano_Poblacion; i++) {
        int cruce = 4;
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