#include "ReturnWithTuple.h"

tuple <int, string, double> getValues()
{
    string name = "Akash";
    int score = 45;
    double cgpa = 6.9;

    return {score, name, cgpa};
}




void ReturnWithTuple()
{
    cout<<"returnWithTuple [START]"<<endl;

    /* Tuple can't be used directly like how pair does. Will have to either unpack tuple using tie or use auto in C++17 */
    {
        string name;
        int score;
        double cgpa;
    
        tuple<int, string, double> result = getValues();


        cout<<"\n1st by unpacking tuple using tie"<<endl;

        tie(score, name, cgpa) = result;

        cout<<"[ score:"<<score<<", name:"<<name<<", cgpa:"<<cgpa<<" ]"<<endl;
    }
    
    {
        cout<<"\n2nd by using auto to unpack for temporary purpose"<<endl;
        auto [score, name, cgpa] = getValues();

        cout<<"[ score:"<<score<<", name:"<<name<<", cgpa:"<<cgpa<<" ]"<<endl<<endl;
    }
    cout<<"returnWithTuple [END]"<<endl<<endl;
}
