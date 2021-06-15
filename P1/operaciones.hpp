// operaciones.hpp - Header de operaciones
#include "list-imp-nodes.hpp"
/*****
* int Coef(int a, float b);
*****
* Retorna el coeficiente del monomio de grado b del polinomio a
*****
* Input:
*   int a: polinomio a buscar
*   float b: monomio a buscar 
*****
* Returns:
*  int, coeficiente del monomio b
*****/
int Coef(float a, float b, myList *array_poli);

/*****
* float Eval(int a, int b);
*****
* Retorna el polinomio a con el valor b 
*****
* Input:
*   int a: polinomio a buscar
*   float b: valor a evaluar
*****
* Returns:
*  float, valor del polinomio evaluado 
*****/
float Eval(float a, float b, myList *array_poli);
