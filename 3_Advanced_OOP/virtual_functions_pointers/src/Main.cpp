#include "Main.h"

class Entity {
    public:

    string getName()
    {
        return "Entity";    
    }

};

class Player : public Entity {
    public:
        string memberName;

        Player(const string &Name)
        : memberName(Name) {}

        string getName()
        {
            return memberName;    
        }
};

void PrintName(Entity *e)
{
    cout<<e->getName()<<endl;
}


int main()
{
    Entity *e = new Entity;
    //cout<<e->getName()<<endl;
    PrintName(e);

    Player *p = new Player("Akash");
    PrintName(p);
    //cout<<p->getName()<<endl;

    //Entity *e1 = p;
    //cout<<e1->getName()<<endl;
    
    return 0;
}
