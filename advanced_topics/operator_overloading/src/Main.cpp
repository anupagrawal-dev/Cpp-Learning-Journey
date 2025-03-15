#include "Main.h"

class Vector{
public:
    float x, y;
    
    Vector(float x, float y) : x(x), y(y) {}

    Vector add(const Vector& Speed) const
    {
        return Vector(x + Speed.x, y + Speed.y);
    }
    
    Vector Multiply(const Vector& other) const
    {
        return Vector(x * other.x, y * other.y);
    }

    Vector operator+(const Vector& other) const
    {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator*(const Vector& other) const
    {
        return Vector(x * other.x, y * other.y);
    }

    bool operator==(const Vector& other) const
    {
        return (x == other.x && y == other.y);
    }
};

ostream& operator<<(ostream& stream, const Vector& v1)
{
    stream << "x = "<<v1.x <<", y = "<<v1.y<<endl;
    return stream;
}

int main()
{
    Vector speed(1.2f, 3.2f);
    Vector position(2.2f, 5.3f);
    Vector powerup(0.5f, 1.5f);

    Vector result = position.add(speed.Multiply(powerup));

    //Vector result1 = position + speed * powerup;
    Vector result1 = speed + position * powerup;

    cout<<"result x = "<<result.x<<", y = "<<result.y<<endl;

//    cout<<"result1 x = "<<result1.x<<", y = "<<result1.y<<endl;
    cout << "result1 :: "<< result1;

    cout<<((result == result1) ? "Yes, its equal" : "No, its not equal")<<endl;
#if 0
    if( result == result1 )
    {
        cout<<"Yes, its equal"<<endl;
    }
    else
    {
        cout<<"No, its not equal"<<endl;
    }
#endif

    return 0;
}
