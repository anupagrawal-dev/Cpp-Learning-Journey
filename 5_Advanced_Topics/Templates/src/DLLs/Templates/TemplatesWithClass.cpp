#include "TemplatesWithClass.h"

template<int N>

class Array {

private:
    int arr[N];

public:

    int getSize()
    {
        return N;
    }    
};

template<typename T,int N>

class GenericArray {

private:
    T arr[N];

public:

    int getSize()
    {
        return N;
    }    
};


void TemplatesWithClass()
{
    cout<<"TemplatesWithClass [START]"<<endl;
    Array<6> a;

    cout<<"\narray size is :: "<<a.getSize()<<endl;
    cout<<"size of object a for Array<6> a is :: "<<sizeof(a)<<endl;

    Array<2> b;

    cout<<"\narray size is :: "<<b.getSize()<<endl;
    cout<<"size of object b for Array<2> b is :: "<<sizeof(b)<<endl;

    GenericArray<string, 6> Gen_a;

    cout<<"\narray size is :: "<<Gen_a.getSize()<<endl;
    cout<<"size of object a for GenericArray<6> a is :: "<<sizeof(Gen_a)<<endl;

    GenericArray<float, 2> Gen_b;

    cout<<"\narray size is :: "<<Gen_b.getSize()<<endl;
    cout<<"size of object b for GenericArray<2> b is :: "<<sizeof(Gen_b)<<endl;

    cout<<"\nTemplatesWithClass [END]"<<endl;
}




