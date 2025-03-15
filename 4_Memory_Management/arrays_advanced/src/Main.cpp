#include "Main.h"
#include <array>

class Entity {
    public:


};


int main()
{
    //Entity e1;
    Entity *e2 = new Entity;
    int *p = NULL;

    int arr[5];

    cout<<"arr address = "<<arr<<endl;
    
    for(int i=0; i<5; i++)
    {
        arr[i] = i+1;
    }


    for(int num: arr)
    {
        cout<<num<<", ";
    }

    cout<<endl;

    p = arr;

    *(p+2) = 5;

    cout<<"arr[2] = "<<arr[2]<<endl;


    int *arr1 = new int[5];

    size_t size = sizeof(arr)/sizeof(arr[0]);

    cout<<"size = "<<size<<endl;


    delete [] arr1;


    delete e2;


    array<int, 3> a1;

    cout<<"a1.size = "<<a1.size()<<endl;

    for(int i=0; i<a1.size();i++)
    {
        a1[i]= i+2;
    }

    for(int num : a1)
    {
        cout<<num<<", ";
    }

    cout<<endl;

    return 0;
}
