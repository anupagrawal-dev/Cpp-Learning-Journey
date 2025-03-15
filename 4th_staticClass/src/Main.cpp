#include "Log.h"

class Car{

    public:
        static int m_noOfWheels;

};

int Car::m_noOfWheels;
    static void print()
    {
        cout<<"static noOF Wheels = "<<Car::m_noOfWheels<<endl;
    }


int main()
{
    Car c1;

    c1.m_noOfWheels = 5;

    print();

}
