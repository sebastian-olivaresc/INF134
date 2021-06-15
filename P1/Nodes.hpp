// Nodes.hpp - Definicion de Node



struct Element
{
    int coef;
    int exp;
};


struct Node
{
    Element data;
    Node *prev;
    Node *next;
};

Node *make_node(int val1, int val2);
