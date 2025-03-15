#include "Main.h"

class Entity {
public:
    int a;
    int b;

    Entity() : a(4), b(5)
    {
        cout<<"Constructor Called !!"<<endl;
    }

    ~Entity()
    {
        cout<<"Destructor Called !!"<<endl;
    }

    void print() const
    {
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
};

class ScopePointer {
public:
    Entity *m_Ptr;

    ScopePointer(Entity *other) : m_Ptr(other)
    {
    }

    ~ScopePointer()
    {
        delete m_Ptr;
    }

    Entity* operator->()
    {
        return m_Ptr;
    }

    const Entity* operator->() const
    {
        return m_Ptr;
    }
};

struct Abc{

    int a;
    int b;
};

int main()
{
    Entity e1;

    Entity *ptr = &e1;
    
    Entity &ref = (*ptr);  // creating reference object which has copy of value of ptr 
    
    /* Now we can call print function in 3 different ways */

    /* By dereferencing pointer and calling print function*/
    (*ptr).print();

    /* call print function using ref object */
    ref.print();

    /* call print function using ptr and arrow operator */
    ptr->print();

    ptr->a = 10;

    ptr->print();

    ScopePointer entity = new Entity();

    entity.m_Ptr->print();

    entity->print();
#if 0 
    int offset_a = (&((struct Abc*)NULL)->a);
    int offset_b = (&((struct Abc*)NULL)->b);
    cout<<"offset of a ::"<<offset_a<<endl;
    cout<<"offset of b ::"<<offset_b<<endl;
#endif
    cout<<"offset of struct Abc a ::"<<&((struct Abc*)NULL)->a<<endl;
    cout<<"offset of b ::"<<&((struct Abc*)NULL)->b<<endl;


    cout<<"offset of Class Entity a ::"<<&((Entity*)NULL)->a<<endl;
    cout<<"offset of b ::"<<&((Entity*)NULL)->b<<endl;
    return 0;
}
