#include "Main.h"

class Entity
{
private:
    int m_X;
    int m_Y;
    mutable int var;

public:

    int GetX() const // Adding const keyword after function number which restricts changing any class member variable
    {
        var = 7;
        //m_X = 6;  // invalid
        //m_Y = 7;  // invalid
        return m_X;
    }

    void SetX(int X)
    {
        m_X = X;
    }

};

class Test
{
private:
    int m_X;

public:

    int GetX() const  // picks printEntity function as t1 is constant reference
    {
        return 1;
    }

    int GetX()
    {
        return 2;
    }
};

void printEntity(const Test &t1)
{
    cout<<"X = "<<t1.GetX()<<endl;
}

void printEntity1(Test &t2)
{
    cout<<"X = "<<t2.GetX()<<endl;
}


int main()
{
    Entity e1;
    Test x1;

    e1.SetX(4);

    cout<<"X = "<<e1.GetX()<<endl;

    printEntity(x1);
    printEntity1(x1);

    return 0;
}
