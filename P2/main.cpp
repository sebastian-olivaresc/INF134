// main.cpp - File to test my different data structures
//


#include <iostream>
#include "list-imp-nodes.hpp"

using namespace std;
int main()
{
    //To make a list
    myList a;
    a.append(3);
    a.append(5);
    a.append(8);
    float total;
    a.iterateList(total);
    cout << "\n" << total << "\n";
    return 0;
}
