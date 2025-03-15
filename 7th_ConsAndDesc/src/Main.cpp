#include "Log.h"

class Entity{
    
    public:
        int x;
        int y;

    Entity() = delete;
    
   /* Entity()
    {
        x=0;
        y=0;
        cout<<"X = "<<x<<", Y = "<<y<<endl;
    }*/
};


int main()
{
    Entity e;
    e.x=0;
    cout<<"X = "<<e.x<<endl;
    
}
