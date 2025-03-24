#include "FunctionPointers.h"

void HelloWorld()
{
    cout<<"void returnType Function"<<endl;
}

int addition(int a, int b)
{
    cout<<"int returnType function with 2 parameters"<<endl;

    return a+b;
}


void FunctionPointers()
{
	cout<<"FunctionPointers [START]"<<endl;

    // Create void Function Pointer to point void returnType function
    {
        void (*func)() = HelloWorld;

        func(); //Fun
    }


	cout<<"FunctionPointers [END]"<<endl;
}
