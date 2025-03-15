#include "Main.h"

class Entity {
    public:
    int a;
    Entity ()
    {
        cout<<"Constructor Called!!"<<endl;
    }

    ~Entity ()
    {
        cout<<"Destructor Called!!"<<endl;
    }
};


int main()
{
    Entity e;
    cout<<"Hello World"<<e.a<<endl;
}
