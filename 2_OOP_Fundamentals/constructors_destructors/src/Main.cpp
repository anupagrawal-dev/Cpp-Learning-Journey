#include "Log.h"

class Entity{
    
public:
    int x;
    int y;

    Entity()
    {
        cout<<"Constructor Called !!"<<endl;
        x = 0;
        y = 0;
        cout<<"X = "<<x<<", Y = "<<y<<endl;
    }

    ~Entity()
    {
        cout<<"Destructor Called !!"<<endl;
    }

    /*
        To delete constructor or destructor,
        Entity() = delete;

    */
        Entity(int) = delete; // Delete Parameterized constructor


};


int main()
{
    Entity e;
    e.x=0;
    cout<<"X = "<<e.x<<endl;
    
}
