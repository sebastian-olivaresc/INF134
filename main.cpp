/* main file para la tarea*/
#include <stdio.h>
#include <iostream>
#include "class_def_array.cpp"

using namespace std;

int main()
{
    int size_array;
    cout << "Ingrese un numero para el tamanno del array, si lo desea: \n";
    cin >> size_array;
    arr_extensible a(size_array);
    unsigned long i = 0;
    int n, salida;
    while(true)
    {
        cout << "Ingrese la posicion a cambiar, -1 para salir: \n";
        cin >> salida;
        if (salida == -1)
            break;
        salida = i;
        cout << "Ingrese el valor a guardar: \n";
        cin >> n;
        a.setValue(i,n);
    }
    for (int s = 0; s < a.size(); s++)
    {
        cout << "A[" << s <<"] es: " << a.getValue(s) << "\n";
    }
    return 0;
}
