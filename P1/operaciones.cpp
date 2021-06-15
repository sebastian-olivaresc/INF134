// operaciones.cpp - Archivo donde se implementan las operaciones
// COEFICIENTE y EVALUAR
#include <iostream>
#include "operaciones.hpp"
using namespace std;
// a : index del polinomio
// b : coeficiente a retornar
int Coef(float a, float b, myList *array_poli)
{
    //castea "a" a int porque es el index de un array
    myList curr_poli = array_poli[int(a)];//polinomio en que se busca el coef
    curr_poli.moveToStart();//para asegurarse que empieza desde head
    Element curr_mono = curr_poli.getValue();
    while(curr_mono.exp != b)
    {
        curr_poli.next();
        curr_mono = curr_poli.getValue();
    }    
    return int(curr_mono.coef); 
}

// a : index del polinomio
// b : numero a evaluar
float Eval(float a, float b, myList *array_poli)
{
    //castea "a" a int porque es el index de un array
    myList curr_poli = array_poli[int(a)];//polinomio en que se evalua
    curr_poli.moveToEnd();//para poder realizar metodo de Horner
    Element curr_mono = curr_poli.getValue();
    float total = curr_mono.coef; 
    while(curr_poli.prev())
    {
        curr_mono = curr_poli.getValue();
        total = curr_mono.coef + b*(total);
    }
    return total;
}
