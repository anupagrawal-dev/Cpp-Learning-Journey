#ifndef __RETURNWITHSTRUCTANDCLASS_H__
#define __RETURNWITHSTRUCTANDCLASS_H__

#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int    score;
    double cgpa;
};

struct Car
{
    string brand;
    int year;
    double price;
    bool isElectric;
};

struct Car& getCarValues();
class Student& getStudentValues();
void ReturnWithStructAndClass();
#endif
