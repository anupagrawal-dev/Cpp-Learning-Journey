#include "Main.h"

class Entity{
public:
    int age;
    string name;

    Entity(int Age) : age(Age), name("Unknown") {}

    explicit Entity(string Name): age(-1), name(Name) {} 


};

int main()
{
    Entity e1 = 4;
//    Entity e2 = string("Anup"); //invalid as corresponding constructor is explicit
    Entity e2("Anup");
    Entity e3 = Entity("Akash");

    cout<<"e1 Age = "<<e1.age<<", Name = "<<e1.name<<endl;
    cout<<"e2 Age = "<<e2.age<<", Name = "<<e2.name<<endl;
    cout<<"e3 Age = "<<e3.age<<", Name = "<<e3.name<<endl;

    

}
