#include "Main.h"

class Printable
{
    public:
    virtual string getClassName() = 0;
};

class Entity: public Printable{
    public:
    virtual string getName()
    {
        return "Entity";
    }

    string getClassName() override
    {
        return "Entity";
    }
};

class Player : public Entity {
    public:
    string getName() override 
    {
        return "Player";
    }

    string getClassName() override
    {
        return "Player";
    }
};

void print(Entity *e1)
{
    cout<<e1->getName()<<endl;
}

void printable(Printable *p1)
{
    cout<<p1->getClassName()<<endl;
}

int main()
{
    Entity *e = new Entity;
    print(e);

    Player *p = new Player;

    printable(e);
    printable(p);

    return 0;
}
