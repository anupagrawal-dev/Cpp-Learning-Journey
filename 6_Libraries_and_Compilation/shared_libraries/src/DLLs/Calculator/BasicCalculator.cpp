#include "BasicCalculator.h"


int addition(int a, int b)
{
    return a+b;
}

int subtraction(int a, int b)
{
    return a-b;
}

int multiplication(int a, int b)
{
    return a*b;
}

void BasicCalculator()
{
    cout<<"BasicCaculator [START]"<<endl<<endl;

    int a = 0, b = 0;
    cout<<"Enter 1st number :: ";
    cin>>a;
    cout<<"Enter 2nd number :: ";
    cin>>b;

    cout<<"addition is :: "<<addition(a,b)<<endl;
    cout<<"multiplication is :: "<<multiplication(a,b)<<endl;
    cout<<"subtraction is :: "<<subtraction(a,b)<<endl;

    cout<<"\nBasicCaculator [END]"<<endl;
}
