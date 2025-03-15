#include "Main.h"


class Entity {

public:
    int x;
    int y;

    Entity(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Entity2 {

public:
    int x;
    int y;

    Entity2(int x, int y)
    {
        this->x = x; // invalid
        this->y = y; // invalid
    }

    void setXy(int x, int y) const
    {
//        this->x = x; //invalid
  //      this->y = y; //invalid
    }

};

int main()
{
    Entity e1(5,5);

    cout<<"x = "<<e1.x<<", y = "<<e1.y<<endl;

}
