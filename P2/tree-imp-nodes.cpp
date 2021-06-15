// tree-imp-nodes.cpp - Implementing a list with BST(binary search tree)

#include <iostream>
#include "list-imp-nodes.hpp"
#include <math.h>

/*
struct Node 
{
    Element data ;//data saved in this node
    Node *prev;//pointer to previous node
    Node *next;//pointer to next node

};
*/

typedef int Element;

Node *make_node(Element value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->left= NULL;
    new_node->right= NULL;
    return new_node;
}

bool is_list_empty()
{
    if(size == 0)
        std::cerr << "ERROR\nList empty\n";
    return (size == 0);
}

void myList::insert(Element value)//inserts to the right of current node
{
    
    Node *new_node = make_node(value);
    if(head == NULL)
    {
        head = curr = new_node;    
    }
    else
    {
        
    }
    ++size;//updates the size of the list
}


void myList::clear()
{
    head = curr = NULL;
    Position = 0;
    size = 0;
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
        }
        else if(i > position)
        { 
            for(; i > position; i--)
                prev();
        }
        else
           std::cout << "Already in that position\n";

        return 0;
    }
    else
    {
        std::cerr << "ERROR\nPosition unreachable\n";
        return 1;
    }
}

void myList::append(Element value)
{
    unsigned int tmp = currPos();
    if(currPos() != (length() - 1))//if not at tail, move there
    {
        moveToEnd();
        insert(value);
        moveToPos(tmp);
    }
    else
        insert(value);
}

void myList::myRemove()
{
    if(!is_list_empty())
    {
        (curr->right)->left = curr->left;
        (curr->left)->right = curr->right;
        Node *tmp = curr;
        prev();
        delete tmp;
    }
}

void myList::change(Element value)
{
    if(!is_list_empty())
    {
        curr->data = value;         
    }
}

void myList::moveToStart()
{
   if(!is_list_empty()) 
   {
       if(currPos() != 0)
       {
           moveToPos(0);
       }
   }
}

void myList::moveToEnd()
{
    if(!is_list_empty())
        moveToPos(length() - 1);
}

Element myList::getValue()
{
    if(!is_list_empty())
        return curr->data;
}

void myList::prev()
{
    if(!is_list_empty())
    {
        curr = curr->left; 
        --Position;
    }
}

void myList::next()
{
    if(!is_list_empty())
    {
        curr = curr->right;
        ++Position;
    }
}

unsigned int myList::length()
{
    return size;
}

unsigned int myList::currPos()
{
    if(!is_list_empty())
        return Position;
}
