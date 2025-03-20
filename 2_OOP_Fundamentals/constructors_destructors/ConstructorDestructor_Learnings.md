**Constructor and Destructor** in cpp :-

- Constructor is a function which present inside class with same name as class name and which is used to initialize data.
- Constructor is used to initialize data of class mainly. By default, default constructor will be called when we create instance of a class.
And, you can remove default constructor from a class 
like below,

```
Class abc{

	abc() = delete;
	
};
```

Example of User defined constructor for a class as below,

Main.cpp
```
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
};

int main()
{
    Entity e;
    e.x=0;
    cout<<"X = "<<e.x<<endl;
}
```

Constructor is called whenever object of a class is declared/initialized
```
Entity e;
```

Depends on object declaration, different types of constructor will be called.
Types of constructor :-

1. Default constructors       - without any parameters
2. Parameterized constructors - with parameters
3. Copy Constructors          - with another Class object parameter. 

E.g. Parameterized constructor 

```
class Entity{
public:
    int x;
    int y;

    Entity(int a, int b)
    {
        cout<<"Parameterized Constructor Called !!"<<endl;
        x = a;
        y = b;
        cout<<"X = "<<x<<", Y = "<<y<<endl;
    }
};

int main()
{
    Entity e(4, 5);
    cout<<"X = "<<e.x<<endl;
}
```

Here, object is created with parameter values which triggers parameterized constructor.


E.g. Copy constructor 

```
class Entity{
public:
    int x;
    int y;

    Entity(const Entity &other)
    {
        cout<<"Copy Constructor Called !!"<<endl;
        x = other.x;
        y = other.y;
        cout<<"X = "<<x<<", Y = "<<y<<endl;
    }
};

int main()
{
    Entity e;
    e.x=1;
    e.y=2;

    Entity e2(e1);
    cout<<"X = "<<e.x<<endl;
}
```

Here, when you pass second object as parameter of declaring object for a class then copy constructor gets triggered.

Here, object is created with parameter values which triggers parameterized constructor.


**Destructor** :-

Destructor is a function which present inside class with same name as class name with tilda as prefix .
This is used to deallocate dynamically allocated memory. And this function will be called after object of class will get destroyed.

E.g. Destructor

```
class Entity{
public:
    int x;
    int y;

    ~Entity()
    {
        cout<<"Destructor Called !!"<<endl;
    }
};

int main()
{
    Entity e;
    e.x=1;
    e.y=2;

    Entity e2(e1);
    cout<<"X = "<<e.x<<endl;
}
```
Destructor gets triggered at the end of Main function block.


