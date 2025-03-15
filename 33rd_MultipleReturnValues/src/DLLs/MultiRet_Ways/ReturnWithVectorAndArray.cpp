#include "ReturnWithVectorAndArray.h"

array<int, 5>& getArrayValues()
{
    static array<int, 5> roll_nums = {101, 102, 103, 104, 105};

    return roll_nums;
}

vector<string>& getVectorValues()
{
    static vector<string> users = {"anup", "akash", "roshani", "yash"};
    
    return users;
}

void ReturnWithVectorAndArray()
{
    cout<<"returnWithVectorAndArray [START]"<<endl;

    vector<string>& users_list = getVectorValues();

    
    cout<<"\n[ Vector users_list : ( ";

    for(int i=0;i<(int)users_list.size(); i++)
    {
        cout<<users_list[i]<<", ";
    }
    
    cout<<") ]\n";


    array<int, 5>& roll_nums = getArrayValues();

    
    cout<<"\n[ Array roll_nums : ( ";

    for(int i=0;i<(int)roll_nums.size(); i++)
    {
        cout<<roll_nums[i]<<", ";
    }
    
    cout<<") ]\n\n";

    cout<<"returnWithVectorAndArray [END]"<<endl<<endl;
}
