#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int filas = 8;
const int columnas = 8;

string crearMatriz(int matriz[filas][columnas])
{
    string Individuo = "";
    string IndividuoString = "";
    for (int i = 0; i < columnas; i++)
    {
        int fila = rand() % filas;
        matriz[fila][i] = 1;
        string FilaString = to_string(fila);

    }
    cout<<IndividuoString<<endl;
    return Individuo;

}

//funcion para evaluar choques 
int choques()
{
    //identifique las posicion de las reinas

}

int main()
{
    srand(time(NULL));
    int matriz[filas][columnas] = {0};

    crearMatriz(matriz);

    // Imprimir la matriz
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
