// Nodes.cpp - Funciones sobre structs tipo Node

#include <cstddef>
#include "Nodes.hpp"

Node *make_node(int val1, int val2)
{
    Node *new_node = new Node;
    new_node->data.exp = val1;
    new_node->data.coef = val2; 
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


