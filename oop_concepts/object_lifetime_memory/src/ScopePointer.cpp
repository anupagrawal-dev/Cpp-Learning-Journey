#include "Main.h"



class ScopePointer
{
private:
    Entity *mPtr;

public:
    ScopePointer(Entity *ptr) : mPtr(ptr) {}

    ~ScopePointer()
    {
        delete mPtr;
    }
};


void scopePointer()
{
    cout<<"\n\n START of Scope Pointer"<<endl;

    {
        ScopePointer e = new Entity();
    }

    cout<<"after block completetion"<<endl;

}
