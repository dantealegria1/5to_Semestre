#include <iostream>
#include <vector>
using namespace std;
 
// Estructura de datos para almacenar un borde de graph
struct Edge {
    int src, dest, weight;
};
 
typedef pair<int, int> Pair;
 
// Una clase para representar un objeto graph
class Graph
{
public:
    // un vector de vectores de Pares para representar una lista de adyacencia
    vector<vector<Pair>> adjList;
 
    // Constructor de graph
    Graph(vector<Edge> const &edges, int n)
    {
        // cambiar el tamaño del vector para contener `n` elementos de tipo `vector<int>`
        adjList.resize(n);
 
        // agrega bordes al grafo dirigido
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
 
            // insertar al final
            adjList[src].push_back(make_pair(dest, weight));
 
            // elimine el comentario del siguiente código para el graph no dirigido
            // adjList[dest].push_back(make_pair(src, weight));
        }
    }
};
 
// Función para imprimir la representación de la lista de adyacencia de un graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Función para imprimir todos los vértices vecinos de un vértice dado
        for (Pair v: graph.adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }
}
 
// Implementación de graph usando STL
int main()
{
    // vector de los bordes del graph según el diagrama anterior.
    // Tenga en cuenta que el vector de inicialización en el siguiente formato
    // funciona bien en C++11, C++14, C++17 pero fallará en C++98.
    vector<Edge> edges =
    {
        // (x, y, w) —> arista de `x` a `y` con peso `w`
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };
 
    // número total de nodos en el graph (etiquetados de 0 a 5)
    int n = 6;
 
    // construir grafo
    Graph graph(edges, n);
 
    // imprime la representación de la lista de adyacencia de un graph
    printGraph(graph, n);
 
    return 0;
}