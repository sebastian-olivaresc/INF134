//file-reader.hpp - header funciones file-reader.cpp

#include <string>
#include <fstream>
#include <iostream>

#include "list-imp-nodes.hpp"

using namespace std;

#ifndef FILEREADER_H
#define FILEREADER_H


void openFile(string filename);
void closeFile();

myList *poliReader();

float **op_reader(int &operaciones);

#endif /*FILEREADER_H*/
