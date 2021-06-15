// list-imp-nodes.cpp - Implementacion de una lista enlazada 

#include <iostream>
#include "list-imp-nodes.hpp"

/*****
* bool is_list_empty(); 
*****
* Comprueba si la lista esta vacia 
*****
* Input:
*  Ninguno 
*****
* Returns:
*  bool, retorna true si esta vacia, false en otro caso
*****/
/*
bool myList::is_list_empty()
{
    if(Size == 0)
        std::cerr << "ERROR\nLista vacia\n";
    return (Size == 0);
}
*/
/*****
* void removeAll(); 
*****
* Elimina todos los nodos un por uno 
*****
* Input:
*  Ninguno 
*****
* Returns:
*  void
****/
void myList::removeAll()
{
    while(head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

Node *myList::insert(int val1, int val2)//agrega a la derecha sin mover curr
{
    
    Node *new_node = make_node(val1, val2);
    if(head == NULL)
    {
        head = curr = tail = new_node;    
    }
    else
    {

        new_node->prev = curr;
        new_node->next = curr->next;
        if(curr->next != NULL)
            (curr->next)->prev = new_node;
        else
        {
            tail = new_node;//actualiza tail si se agrega al final
        }
        (curr->next) = new_node;
    }
    ++Size;//actualiza el tamanno de Size
    return new_node;
}

void myList::left_insert(int val1, int val2)
{
    Element tmp_curr = getValue();//guarda los datos del node curr 
    insert(tmp_curr.exp, tmp_curr.coef);
    change(val1, val2);
}


void myList::clear()
{
    //removeAll();
    head = curr = tail= NULL;
    Position = 0;
    Size = 0;
}

int myList::moveToPos(unsigned int position)
{
    int i = currPos();
    if(0 <= position && position < length())
    {
        if(i < position)
        {
            for(; i < position; i++)
                next();
            return 0;
        }
        else if(i > position)
        { 
            for(; i > position; i--)
                prev();
            return 0;
        }
        else
           std::cout << "Already in that position\n";

        return 1;
    }
    else
    {
        std::cerr << "ERROR\nPosition unreachable\n";
        return 2;
    }
}

void myList::append(int val1, int val2)
{
    if(curr != tail)//if not at tail, move there
    {
        moveToEnd();
    }
    tail = insert(val1, val2);

}

void myList::myRemove()
{
    if(curr == head)
        head = head->next;
    else if(curr == tail)
        tail = tail->prev;

    (curr->next)->prev = curr->prev;
    (curr->prev)->next = curr->next;
    Node *tmp = curr;
    prev();
    delete tmp;
}

void myList::change(int val1, int val2)
{
    (curr->data).exp = val1;         
    (curr->data).coef = val2;         
}

void myList::moveToStart()
{
   if(currPos() != 0)
   {
       curr = head;
       Position = 0;
   }
}

void myList::moveToEnd()
{
    curr = tail;
    Position = length() - 1;
}

Element myList::getValue()
{
    return curr->data;
}

Node *myList::prev()
{
    if(curr->prev != NULL)
    {
        curr = curr->prev; 
        --Position;
        return curr;
    }
    return NULL;
}

Node *myList::next()
{
    if (curr->next != NULL)
    {
        curr = curr->next;
        ++Position;
        return curr;
    }
    return NULL;
}

unsigned int myList::length()
{
    return Size;
}

unsigned int myList::currPos()
{
    return Position;
}
