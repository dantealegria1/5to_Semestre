#include <iostream>
#include <vector>

using namespace std;

// Definición de un grafo no dirigido utilizando listas de adyacencia
class Grafo {
private:
    int V; // Número de vértices
    vector<vector<int>> adyacencia; // Lista de adyacencia

public:
    Grafo(int vertices) : V(vertices) {
        adyacencia.resize(V);
    }

    // Agregar una arista entre los vértices u y v
    void agregarArista(int u, int v) {
        adyacencia[u].push_back(v);
        adyacencia[v].push_back(u); // Si el grafo es no dirigido, se agrega la arista en ambos sentidos
    }

    // Mostrar la lista de adyacencia del grafo
    void mostrarGrafo() {
        for (int i = 0; i < V; ++i) {
            cout << "Vértice " << i << " está conectado a:";
            for (int j = 0; j < adyacencia[i].size(); ++j) {
                cout << " " << adyacencia[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5; // Número de vértices del grafo

    Grafo miGrafo(numVertices);

    // Agregar aristas al grafo
    miGrafo.agregarArista(0, 1);
    miGrafo.agregarArista(0, 4);
    miGrafo.agregarArista(1, 2);
    miGrafo.agregarArista(1, 3);
    miGrafo.agregarArista(1, 4);
    miGrafo.agregarArista(2, 3);
    miGrafo.agregarArista(3, 4);

    // Mostrar el grafo (lista de adyacencia)
    miGrafo.mostrarGrafo();

    return 0;
}
