#include "Log.h"

class Car{
    public:
    int x;
    int y;
    static int m_noOfWheels;

    void print()
    {
        cout<<" x = "<<x<<", y = "<<y<<endl;
    }
};

int Car::m_noOfWheels;

int main()
{
    Car swift;

    swift.x = 5;
    swift.y = 6;

    swift.print();
    
    Car BMW = {7, 8};

    BMW.print();

    cout<<"swift.m_noOfWheels = "<<swift.m_noOfWheels<<endl;
    cout<<"BMW.m_noOfWheels = "<<BMW.m_noOfWheels<<endl;

    swift.m_noOfWheels = 6;

    cout<<"swift.m_noOfWheels = "<<swift.m_noOfWheels<<endl;
    cout<<"BMW.m_noOfWheels = "<<BMW.m_noOfWheels<<endl;
}
