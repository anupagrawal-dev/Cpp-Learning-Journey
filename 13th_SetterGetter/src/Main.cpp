#include "Main.h"

class Entity {
    
private:
    int X;
    int Y;

public:

    void setValues(int X, int Y)
    {
        this->X = X;
        this->Y = Y;
    }

    void getValues(int &X, int &Y)
    {
        X = this->X;
        Y = this->Y;
    }

    void print()
    {
        cout<<"X = "<<X<<", Y = "<<Y<<endl;
    }
};

int main()
{
    Entity *e1 = new Entity;
    int X,Y;

    e1->print();

    e1->setValues(4, 5);

    e1->print();

    e1->getValues(X,Y);

    cout<<"Local X = "<<X<<", Local Y = "<<Y<<endl;

    delete e1;
    
    return 0;
}
