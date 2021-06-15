
//devuelve un array de punteros a listas

#include <cmath>
#include "file-reader.hpp"

#define MAX_SIZE 100//maximo de operacionesa evaluar

fstream file;

void openFile(string filename)
{
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        cerr << "Error\nNo se pudo abrir el archivo " << filename << "\n";
        exit(1);
    }
}

void closeFile()
{
    file.close();
}


//va guardando los monomios en orden
void guardaInOrder(myList &polinomio, int E, int C)
{
    if (polinomio.head == NULL)
    {
        polinomio.append(E, C);
        return;
    }
    //exp con el que se compara el valor a agregar
    int exp_curr = (polinomio.getValue()).exp;
    /*
    Node *nextExists = polinomio.next();
    if (nextExists)//guarda el valor del monomio siguiente
    {
        exp_next = (polinomio.getValue()).exp;
        polinomio.prev();
    }
    */

    if (exp_curr > E)
        if (polinomio.prev())
            guardaInOrder(polinomio, E, C);
        else
            polinomio.left_insert(E, C);
    else
        if (polinomio.next())
        {
            exp_curr = (polinomio.getValue()).exp;
            if(E < exp_curr)
                polinomio.left_insert(E, C);
            else
                guardaInOrder(polinomio, E, C);
        }
        else
            polinomio.append(E, C);
    /*
    if (exp_curr < E && E < exp_next)
        polinomio.insert(E, C);
    else if (E < exp_curr)
    {
        if (polinomio.prev())
            guardaInOrder(polinomio, E, C);
        else
            polinomio.left_insert(E, C);
    }
    else if (exp_curr < E)
    {
        if (polinomio.next())
            guardaInOrder(polinomio, E, C);
        else 
            polinomio.insert(E, C);
    }
    */
}

myList *poliReader()
{
    string L;
    getline(file, L);
    int n_poli = stoi(L);//guarda el numero de polinomios a guardar
    int n_mono;//guarda numero de monomios del polinomio actual
    int E, C;//exponente y coeficiente del monomio 
    
    myList *array_poli = new myList[n_poli];//array de puntero a myList
    for (int i = 0; i < n_poli; i++)
    {
        getline(file, L);//lee n de monomios
        n_mono = stoi(L);
        myList polinomio;//crea una lista 
        for(int j = 0; j < n_mono; j++)
        {
            getline(file, L, ' ');//lee exp
            E = stoi(L);
            getline(file, L);//lee coef
            C = stoi(L);
            guardaInOrder(polinomio, E, C);
            //cout << "E: " << E << " C: " << C << endl;
            //polinomio.append(E, C);
        }
        array_poli[i] = polinomio;
    }

    return array_poli;

}

//guarda las operaciones en un array de array de float
float **op_reader(int &operaciones)
{
    string L;
    float i;//variable para indexar polinomio
    float x;//variable para op. EVALUAR
    float j;//variable para op. COEFICIENTE
    float **array_oper = new float*[MAX_SIZE];
    int count = 0;//contador de operaciones
    while(getline(file, L, ' '))
    {
        float *oper_data = new float[3];
        if(L == "COEFICIENTE")
        {
            oper_data[0] = 0.0;//0 = COEFICIENTE
            getline(file, L, ' ');
            i = stof(L);
            getline(file, L);
            j = stof(L);
            oper_data[1] = i;
            oper_data[2] = j;
        }
        else if(L == "EVALUAR")
        {
            oper_data[0] = 1;//1 = EVALUAR 
            getline(file, L, ' ');
            i = stof(L); 
            getline(file, L);
            x = stof(L);
            oper_data[1] = i;
            oper_data[2] = x;
        }
        array_oper[count++] = oper_data;
    }
    //retorna la cantidad de operaciones que se van a evaluar
    operaciones = count;
    return array_oper;
}

