#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const int filas = 8;
const int columnas = 8;
const int tamano_Poblacion = 10;
const int num_cruces = 3;

vector<string> poblacion(tamano_Poblacion);
vector<int> choques(tamano_Poblacion);

int Calculo_Choques(const string& individuo) {
    // Función para calcular los choques de un individuo
    // ... (tu implementación actual)
}

void InicializarPoblacion() {
    srand(time(NULL));
    for (int i = 0; i < tamano_Poblacion; i++) {
        string individuo = "";
        for (int j = 0; j < columnas; j++) {
            int fila = rand() % 8;
            individuo += to_string(fila);
        }
        poblacion[i] = individuo;
        choques[i] = Calculo_Choques(individuo);
    }
}

void Seleccion(vector<string>& seleccionados) {
    // Selecciona individuos para cruce y mutación.
    // Aquí se puede implementar diferentes estrategias de selección.
    // Por simplicidad, seleccionamos al azar.
    for (int i = 0; i < num_cruces; i++) {
        int index = rand() % tamano_Poblacion;
        seleccionados.push_back(poblacion[index]);
    }
}

void CruzarMutar(vector<string>& hijos) {
    for (int i = 0; i < num_cruces; i++) {
        string hijo1 = poblacion[i];
        string hijo2 = poblacion[num_cruces - i - 1];

        // Aplicamos mutación en 3 posiciones aleatorias para los primeros 3 individuos.
        for (int j = 0; j < 3; j++) {
            int pos = rand() % columnas;
            int nuevo_valor = rand() % filas;  // Nuevo valor aleatorio entre 0 y 7 (filas)
            hijo1[pos] = (char)(nuevo_valor + '0');
        }

        // Agregamos los hijos a la lista de hijos
        hijos.push_back(hijo1);
        hijos.push_back(hijo2);
    }
}

void ReemplazoElitista(vector<string>& hijos) {
    // Reemplazo elitista: conservamos los mejores individuos de la generación anterior.
    for (int i = 0; i < tamano_Poblacion - num_cruces; i++) {
        int idx = tamano_Poblacion - 1 - i;
        poblacion[idx] = hijos[i];
        choques[idx] = Calculo_Choques(hijos[i]);
    }
}

int main() {
    srand(time(NULL));

    InicializarPoblacion();

    int generacion = 1;
    while (choques[0] != 0 && generacion <= 100) {
        vector<string> seleccionados;
        Seleccion(seleccionados);

        vector<string> hijos;
        CruzarMutar(hijos);

        ReemplazoElitista(hijos);

        // Incrementar el número de generación
        generacion++;
    }

    // Imprimir los mejores individuos de la última generación
    cout << "Mejores individuos de la última generación:" << endl;
    for (int i = 0; i < tamano_Poblacion; i++) {
        cout << "Individuo: " << poblacion[i] << " Choques: " << choques[i] << endl;
    }

    return 0;
}
