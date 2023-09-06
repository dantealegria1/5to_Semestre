#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // valores
    float funcion, d1, d2, resultado;
    float error = 0.001;
    
    // muestra de sus funciones y derivadas
    cout << "su función es: 2x^2 + 16/x " << endl;
    cout << "la primera derivada es: 4x - 16/x^2" << endl;
    cout << "la segunda derivada es: 32/x^3 + 4" << endl;
    cout << "------ RESOLVER LA FUNCIÓN ------" << endl;
    cout << "Ingrese su valor x0: " << endl;
    cin >> resultado; // Use resultado instead of inicio

    while (true) // Run indefinitely, break when condition met
    {
        // función
        funcion = 2 * (resultado * resultado) + 16 / resultado;
        
        // derivada
        d1 = 4 * resultado - 16 / (resultado * resultado);
        // avoid division by zero
        if (abs(d1) < 0.0001)
            break;
        // derivada 2
        d2 = 32 / (resultado * resultado * resultado) + 4;
        resultado = resultado - (d1 / d2);
    }

    resultado = 2*(resultado*resultado) + 16/resultado;
    cout << "El resultado es: " << resultado << endl;
    
    return 0;
}
