// tree-imp-nodes.hpp - Implementation of a list using BST(binary search tree) 


#include <iostream>

typedef int Element;

struct Node
{
    Element data;
    Node *prev;
    Node *next;
};

class myList
{
    public:
        Node *head;
        Node *curr;
        unsigned int size;
        unsigned int Position; 
        void init()
        {
            head = curr = NULL;
            size = Position = 0;
        }
        void removeAll()
        {
            while(head != NULL)
            {
                curr = head;
                head = head->next;
                delete curr;
            }
        }
        myList(){init();};//constructor
        ~myList(){removeAll();};//destructor

        //Removes the current element
        void myRemove();

        //Changes the value of the current element
        void change(Element value);

        //Moves cursor to the start of the list
        void moveToStart();

        //Moves cursosr to the end of the list
        void moveToEnd();

        //Returns the value of the current element 
        Element getValue();

        //Moves the cursor to the previous element
        void prev();

        //Moves the cursor to the next element
        void next();

        //Returns current position of the cursos
        unsigned int currPos();

        //Inserts value on current position, creating a new node
        void insert(Element value);
        
        //Empties the list
        void clear();

        //Changes the cursor to a position, returns position if unreachable
        int moveToPos(unsigned int position);

        //Adds element with value to the end of the list
        void append(Element value);

        //Returns the size of the list
        unsigned int length();
        
        //Returns value of every element in sequence
        void iterateList(float &total);
};
