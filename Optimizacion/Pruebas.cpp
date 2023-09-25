#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

float funcion(int x1, int x2)
{
    int function;
    function = -(1+(cos(12*sqrt((x1*x1)+(x2*x2))))/(0.5*((x1*x1)+(x2*x2))+2));
    return function;
}
int main()
{
    float x1,x2;
    float function, resultado=1000000;
    x1=4;
    x2=0.122;
    function = funcion(x1,x2);
    cout<<function<<endl;
    int hola;
    hola = 12*sqrt((x1*x1)+(x2*x2));
    int eeee;
    eeee= cos(x1);
    cout<<eeee<<endl;
    cout<<hola<<endl;

}