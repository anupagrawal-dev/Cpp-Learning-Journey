#include "ReturnWithPassByReference.h"

void getPassByRefValues(string &name, int &score, double &cgpa)
{
    name = "Roshani";
    score = 97;
    cgpa = 9.9;
}


void ReturnWithPassByReference()
{
    cout<<"returnWithPassByReference [START]"<<endl;

    string name;
    int score;
    double cgpa;

    getPassByRefValues(name, score, cgpa);

    cout<<"\n[ PassByRefValues name:"<<name<<", score:"<<score<<", cgpa:"<<cgpa<<" ]"<<endl<<endl;


    cout<<"returnWithPassByReference [END]"<<endl<<endl;
}
