#include "Main.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i=0,j=0;

        for(;i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[j]=nums[i];
                j++;
            }
        }

        for(i=j; i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> test;
    int n=0;
    int value=0;

    cout<<"Enter number of elements::";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"enter "<<i+1<<" : ";
        cin>>value;
        test.push_back(value);
    }
    

    sol.moveZeroes(test);

    cout<<"array = [ ";
    for(int i=0;i<n;i++)
    {
        cout<<test[i]<<", ";
    }
    
    cout<<"]"<<endl;
}
