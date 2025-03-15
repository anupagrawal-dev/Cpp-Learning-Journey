#include "Main.h"

enum Example : char{
    A=97,
    B,
    C
};


int main()
{
    Example value = B;

    cout<<"value = "<<value<<endl;
    cout<<"value = "<<A<<endl;

    return 0;
}
