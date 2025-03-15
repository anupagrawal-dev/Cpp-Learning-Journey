#include "Main.h"

int main()
{
    int a = 5;

    const int *b = new int;

    b = &a;  // valid
    
//    *b = 3; // invalid 

    int const *c = new int;

    c = &a; //valid

  //  *c = 3; //invalid
    
    cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;

    int *const d = new int;

//    d = &a;  // invalid

    *d = 4;  // valie

    cout<<"d = "<<*d<<endl;

    const int *const e = new int;

    // e = &a; //invalid

    // *e = 5; //invalid

    cout<<"e = "<<e<<endl;

    return 0;
}
