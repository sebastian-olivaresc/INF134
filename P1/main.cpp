// main.cpp - File to test my different data structures
//


#include <iostream>
#include <fstream>
#include <string>
#include "file-reader.hpp"
#include "operaciones.hpp"

using namespace std;

int main()
{
    openFile("entradaPolinomio.txt");
    myList *array_poli = poliReader();
    int n_operaciones;
    float **array_op = op_reader(n_operaciones);
    closeFile();

    float *operacion;//puntero a array de los datos de las operaciones

    float a;//a : index poli
    float b;//b : coef. que se pide o x para evaluar
    fstream outFile;
    outFile.open("salidaPolinomio.txt", ios::out);

    /*
    myList test_poli = array_poli[3];
    test_poli.moveToStart();
    cout << "size: " << test_poli.length() << endl;

    Element test_mono;
    
    for (int h = 0; h < test_poli.length(); h++)
    {
        test_mono = test_poli.getValue(); 
        cout << test_mono.exp << ",";
        cout << test_mono.coef << endl;
        test_poli.next();
    }

        test_poli.moveToEnd();
        test_mono = test_poli.getValue(); 
        cout << "tail: ";
        cout << test_mono.exp ; 
        cout << test_mono.coef << endl;
   

    */
    for(int i = 0; i < n_operaciones; i++)
    {
        operacion = array_op[i];
        a = operacion[1];
        b = operacion[2];
        //operacion[0] == 0 COEFICIENTE; operacion[0] == 1 EVALUAR
        if(operacion[0] == 0)
            //cout << Coef(a, b, array_poli) << endl;
            outFile << Coef(a, b, array_poli) << endl;
        else if(operacion[0] == 1)
        {
            //cout << Eval(a, b, array_poli) << endl;
            outFile << Eval(a, b, array_poli) << endl;
        }
    }
    outFile.close();
    return 0;
}
