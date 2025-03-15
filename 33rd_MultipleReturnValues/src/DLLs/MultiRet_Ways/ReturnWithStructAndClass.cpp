#include "ReturnWithStructAndClass.h"

struct Car& getCarValues()
{
    static struct Car c;

    c.brand = "bmw";
    c.year = 1997;
    c.price = 10000000;
    c.isElectric = false;

    return c;
}

class Student& getStudentValues()
{
    static class Student s;

    s.name = "yash";
    s.score = 85;
    s.cgpa = 8.9;

    return s;
}

void ReturnWithStructAndClass()
{
    cout<<"returnWithStructAndClass [START]"<<endl;

    class Student& yash = getStudentValues();

    cout<<"\n[Student  name:"<<yash.name<<", score:"<<yash.score<<", cgpa:"<<yash.cgpa<<" ]"<<endl<<endl;

    struct Car& bmw = getCarValues();

    cout<<"[Car  brand:"<<bmw.brand<<", year:"<<bmw.year<<", price:"<<bmw.price<<", isElectric:";
    cout<<(bmw.isElectric ? "Yes" : "No")<<" ]"<<endl<<endl;

    cout<<"returnWithStructAndClass [END]"<<endl<<endl;
}
