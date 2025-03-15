#include "Main.h"

class Entity {
    public:
        int x;
        int y;

    void Move(int xa, int ya)
    {
        x += xa;
        y += ya;
    }
};

class Player : public Entity {
    public:
        string abc;

    void print(string data)
    {
        cout<<abc<<"x = "<<x<<", y = "<<y<<endl;
    }
};


int main()
{
    Player p = {4,5};

    p.print("Before ");

    p.Move(5, 6);

    p.print("After ");

}
