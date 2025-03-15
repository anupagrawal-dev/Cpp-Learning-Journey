#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>

using namespace std;

class Entity{
public:
    Entity()
    {
        cout<<"Construct Called !!"<<endl;
    }

    ~Entity()
    {
        cout<<"Destructor Called !!"<<endl;
    }

};



void scopePointer();

#endif
