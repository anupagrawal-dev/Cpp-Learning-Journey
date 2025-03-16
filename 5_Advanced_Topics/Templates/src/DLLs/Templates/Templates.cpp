#include "Templates.h"

template<typename T>


void printVal(T value)
{
    cout<<"[ Template Selected dataType:"<<typeid(decltype(value)).name()<<", value:"<<value<<" ]"<<endl;
}

void templates()
{
    cout<<"Calling templates [START]"<<endl;

    cout<<endl;

    printVal<int>(3);
    printVal<string>("Hello World");
    /* f is given to mention it as float specifically. If f is not written then compiler things it as double and then convert it into float which may do precision loss  */    
    printVal<float>(6.7f);
    
    cout<<endl;

    cout<<"templates [END]"<<endl;
}
