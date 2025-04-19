#include "FunctionPointers.h"
#include <vector>

void HelloWorld()
{
    cout<<"void returnType Function"<<endl;
}

/*
void funcWithParams(int a)
{
    cout<<"void returnType Function"<<endl;
}*/

int addition(int a, int b)
{
    cout<<"int returnType function with 2 parameters"<<endl;

    return a+b;
}

/*void callback_function(string test, int (*func)(int, int))
{

}*/

void PrintValue(int value)
{
    cout<< "Value :: "<<value<<endl;
}

void callback_function(const vector<int>& Values, void (*func)(int))
{
    for( int value: Values)
    {
        func(value);
    }
}

int Add(int a, int b)
{
    return a+b;
}

int Subtract(int a, int b)
{
    return a-b;
}

int Multiply(int a, int b)
{
    return a*b;
}

void FunctionPointers()
{
	cout<<"FunctionPointers [START]"<<endl;

    // Create void Function Pointer to point void returnType function
    {
        void (*func)() = HelloWorld;

        func(); //Fun

        // We can also create alias for each type of function pointer. E.g. for this case creating alias for void func pointer with no parameters.
        cout<<endl;

        typedef void (*VoidFuncPtr)();

        VoidFuncPtr newPtr = HelloWorld;

        newPtr();

        //newPtr = funcWithParams; 

    }

    // Create int Function Pointer to point int returnType function with parameters
    {
        cout<<endl;

        int (*func)(int,int) = addition;

        int result = func(4,5);

        cout<<endl;

        cout<<"addition of 4 and 5 is :: "<<result<<endl;
    }

    // Callback Mechanism : means call function as parameter of another function
    {
//        callback_func(string test, addition);
        vector<int> values = { 1, 2, 4, 2, 3};

        callback_function(values, PrintValue);
          

    }

    // Function Tables
    {
        int (*Func[])(int, int) = {Add, Subtract, Multiply};

        cout<<"Addition of 1 and 2 is :: "<<Func[0](1,2)<<endl;
        cout<<"Subtraction of 1 and 2 is :: "<<Func[1](1,2)<<endl;
        cout<<"Multiplication of 1 and 2 is :: "<<Func[2](1,2)<<endl;
    }


	cout<<"FunctionPointers [END]"<<endl;
}
