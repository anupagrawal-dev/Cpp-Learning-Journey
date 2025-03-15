#include "Main.h"


int *func()
{
    int *a = new int;
    *a = 5;

    return a;
}

int main()
{

    {
        Entity e1;  // Constructor get triggered memory of 1 byte got allocated from stack

        cout<<"at the end of block"<<endl;

    } // Destructor get triggered and memory of 1 byte got destroyed or freed from stack

    cout<<"after block completion "<<endl;


    Entity *e2;

    {
        Entity *e1;  

        e1 = new Entity; // Constructor get triggered memory of 1 byte got allocated from stack

        e2 = e1;

        cout<<"at the end of block"<<endl;

    } 

    delete e2; // Destructor get triggered and memory of 1 byte got destroyed or freed from stack

    cout<<"return value = "<<*(func())<<endl;

    scopePointer();

    return 0;
}
