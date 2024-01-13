#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm> // Necesario para std::shuffle
/*
Nombre de la instituciÃ³n: Universidad autonoma de aguascalientes
Nombre del centro al que pertenece la carrera: centro de ciencias de bÃ¡sicas
Nombre del departamento al que pertence la carrera: ciencias de la computaciÃ³n 
Nombre de la materia: OptimizaciÃ³n inteligente
Nombre(s) de quien(es) realiza(n) la prÃ¡ctica: Dante Alejandro Alegria Romero

Breve descripciÃ³n de lo que realiza el programa: 

Obtiene una combinacion optima  

*/
using namespace std;

const int MAX_MACHINES = 3;
const int MAX_JOBS = 4;
const int MAX_ITERATIONS = 500;
const double TEMPERATURA_INICIAL = 1000.0;
const double TEMPERATURA_FINAL = 20.0;
const double RATIO_ENFRIAMIENTO = 0.95;

vector<vector<int>> jobTimes = {
    {2, 7, 3, 6},
    {4, 8, 1, 5},
    {6, 2, 9, 7}
};

int calcularMakespan(const vector<vector<int>>& secuencia) {
    vector<int> tiemposMaquinas(MAX_MACHINES, 0);

    for (int trabajo = 0; trabajo < MAX_JOBS; trabajo++) {
        for (int maquina = 0; maquina < MAX_MACHINES; maquina++) {
            tiemposMaquinas[maquina] += jobTimes[maquina][secuencia[trabajo][maquina]];
            if (maquina > 0) {
                tiemposMaquinas[maquina] = max(tiemposMaquinas[maquina], tiemposMaquinas[maquina - 1]);
            }
        }
    }

    return tiemposMaquinas[MAX_MACHINES - 1];
}

void generarSecuenciaAleatoria(vector<vector<int>>& secuencia) {
    for (int trabajo = 0; trabajo < MAX_JOBS; trabajo++) {
        for (int maquina = 0; maquina < MAX_MACHINES; maquina++) {
            secuencia[trabajo][maquina] = maquina;
        }
        // Aleatorizar el orden de las máquinas en cada trabajo
        for (int maquina = MAX_MACHINES - 1; maquina > 0; maquina--) {
            int j = rand() % (maquina + 1);
            swap(secuencia[trabajo][maquina], secuencia[trabajo][j]);
        }
    }
}

void recocidoSimulado(vector<vector<int>>& secuenciaActual) {
    vector<vector<int>> mejorSecuencia = secuenciaActual;
    int makespanActual = calcularMakespan(secuenciaActual);
    int mejorMakespan = makespanActual;
    double temperatura = TEMPERATURA_INICIAL;

    for (int iteracion = 0; iteracion < MAX_ITERATIONS; iteracion++) {
        int trabajo1 = rand() % MAX_JOBS;
        int trabajo2 = rand() % MAX_JOBS;

        vector<vector<int>> nuevaSecuencia = secuenciaActual;
        swap(nuevaSecuencia[trabajo1], nuevaSecuencia[trabajo2]);

        int nuevoMakespan = calcularMakespan(nuevaSecuencia);

        int deltaMakespan = nuevoMakespan - makespanActual;
        if (deltaMakespan < 0 || (rand() / double(RAND_MAX) < exp(-deltaMakespan / temperatura))) {
            secuenciaActual = nuevaSecuencia;
            makespanActual = nuevoMakespan;
            if (makespanActual < mejorMakespan) {
                mejorSecuencia = secuenciaActual;
                mejorMakespan = makespanActual;
            }
        }

        temperatura *= RATIO_ENFRIAMIENTO;
    }

    cout << "Mejor Secuencia: ";
    for (int trabajo = 0; trabajo < MAX_JOBS; trabajo++) {
        for (int maquina = 0; maquina < MAX_MACHINES/2; maquina++) {
            cout << mejorSecuencia[trabajo][maquina] << " ";
        }
    }
    cout << "\nMejor Makespan: " << mejorMakespan << endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<vector<int>> secuenciaInicial(MAX_JOBS, vector<int>(MAX_MACHINES));
    generarSecuenciaAleatoria(secuenciaInicial);

    recocidoSimulado(secuenciaInicial);

    return 0;
}
