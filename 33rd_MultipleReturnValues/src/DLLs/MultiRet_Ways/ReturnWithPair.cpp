#include "ReturnWithPair.h"


pair<string, int> GetValues()
{
    int val = 5;
    string name = "Anup";

    return {name, val};
}


void returnWithPair()
{
    cout<<"returnWithPair [START]"<<endl;


    pair<string, int> result = GetValues();

    cout<<"\n[ val:"<<result.first<<", name:"<<result.second<<" ]"<<endl<<endl;

    cout<<"returnWithPair [END]"<<endl<<endl;
}
