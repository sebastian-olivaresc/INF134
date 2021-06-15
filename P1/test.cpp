

#include <iostream>
#include "list-imp-nodes.hpp"
using namespace std;
int main()
{
    myList a;
    a.append(3,9);
    Element b = a.getValue();
    cout << b.coef << endl;
    cout << &(a.head) << endl;
    cout << &(a.tail) << endl;
    a.append(8,3);
    cout << &(a.head) << endl;
    cout << &(a.tail) << endl;
    return 0;
}
