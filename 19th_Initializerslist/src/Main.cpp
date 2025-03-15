#include "Main.h"


class base {
public:
	int m_BaseX;

	base()
	{
		cout<<"Default Constructor called!!"<<endl;
	}

	base(int X)
	{
		cout<<"Parameterized Constructor called!!"<<endl;
	}
};

class Derived {
public:
	base b1;

	Derived() : b1(base(5))
	{
		cout<<"Derived"<<endl;
		//b1 = base(5); 
	}
};

class Entity {

public:
	int m_X;
	int m_Y;
	int m_Z;

	Entity() : m_X (4), m_Y(5), m_Z(6){}  // This is intializer list. This will optimize code excution to not initialze
				      // class variables twice
	
	Entity(int X, int Y) : m_X(X), m_Y(Y)
	{

	}

};

int main()
{
	Entity e1;

	cout<<"X = "<<e1.m_X<<", Y = "<<e1.m_Y<<", Z = "<<e1.m_Z<<endl;

	Entity e2(10, 12);

	cout<<"X = "<<e2.m_X<<", Y = "<<e2.m_Y<<endl;

	Derived b1;


}
