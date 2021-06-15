// list-imp-nodes.hpp - Definicion de una lista enlazada 


#include <iostream>

#ifndef LISTIMPNODES_H
#define LISTIMPNODES_H

#include "Nodes.hpp"
class myList
{

    private:

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
        void removeAll();
        //bool is_list_empty();

    public:
        Node *head;
        Node *curr;
        Node *tail; 
       

        unsigned int Size;//tamnno de la lista
        unsigned int Position;//posicion actual en la lista 

        myList()
        {
            head = tail = curr = NULL;
            Size = Position = 0;
        };//constructor
        //~myList(){removeAll();};//destructor

        /*****
         * void insert(Element value); 
         *****
         * Agrega un nodo en la posicion actual con el valor ingresado 
         *****
         * Input:
         *  Element value: Valor a guardar 
         *****
         * Returns:
         *  void
         *****/
        Node *insert(int val1, int val2);

        /*****
         * void insert(Element value); 
         *****
         * Agrega un nodo a la izquierda de posicion actual con el valor ingresado 
         *****
         * Input:
         *  Element value: Valor a guardar 
         *****
         * Returns:
         *  void
         *****/
        void left_insert(int val1, int val2);

        /*****
         * void clear(); 
         *****
         * Vacia la lista 
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  void
         *****/
        void clear();

        /*****
         * int moveToPos(unsigned int position) 
         *****
         * Mueve el cursor a la posicion ingresada 
         *****
         * Input:
         *  unsigned int poisition: Posicion a la cual se mueve el cursor 
         *****
         * Returns:
         *  int , retorna 0 si se movio sin problemas
         *        retorna 1 si ya se estaba en esa posicion
         *        retorna 2 si se quiere mover a una posicion fuera de la lista
         *                  lo cual es un error
         *****/
        int moveToPos(unsigned int position);

        /*****
         * Node *append(int val1, int val2); 
         *****
         * Agrega un nodo con el valor ingresado al final de la lista 
         *****
         * Input:
         *  Element value: Valor a agregar 
         *****
         * Returns:
         *  Node*,  retorna el nodo agregado si se pudo 
         *          retorna NULL si hubo un error 
         *****/
        void append(int val1, int val2);

        /*****
         * void myRemove(); 
         *****
         * Remueve el nodo actual
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  void
         *****/
        void myRemove();

        /*****
         * void change(Element value); 
         *****
         * Cambia el valor del elemento actual 
         *****
         * Input:
         *  Element value : Valor nuevo 
         *****
         * Returns:
         *  void
         *****/
        void change(int val1, int val2);

        /*****
         * void moveToStart(); 
         *****
         * Mueve el cursor al principio de la lista
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  void
         *****/
        void moveToStart();

        /*****
         * void moveToEnd(); 
         *****
         * Mueve el cursor al final de la lista
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  void
         *****/
        void moveToEnd();

        /*****
         * Element getValue(); 
         *****
         * Retorna el valor guardado del nodo actual 
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  Element , el valor guardado
         *****/
        Element getValue();

        /*****
         * Node *prev(); 
         *****
         * Mueve el cursor al nodo anterior
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  Node*,  retorna el nodo actual, a cual retrocedio 
         *          retorna NULL si no puede retroceder mas
         *****/
        Node *prev();

        /*****
         * Node *next(); 
         *****
         * Mueve el cursor al nodo siguiente 
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  Node*,  retorna el nodo actual, a cual avanzo 
         *          retorna NULL si no puede avanzar mas
         *****/
        Node *next();

        /*****
         * unsigned int length(); 
         *****
         * Retorna el tamanno de la lista 
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  unsigned int, Tamanno de la lista 
         *****/
        unsigned int length();

        /*****
         * unsigned int currPos(); 
         *****
         * Retorna la posicion actual del cursor 
         *****
         * Input:
         *  Ninguno 
         *****
         * Returns:
         *  unsigned int , posicion actual del cursor, siempre positiva < Size 
         *****/
        unsigned int currPos();
};

#endif /* LISTIMPNODES_H */
