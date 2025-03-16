#include "Macros.h"

#define LOG(x) cout<<__FILE__<<":"<<__LINE__<<" "<<__func__<<"() "<<x<<endl<<endl

/*
Or can be written in this way which is more understandable,

#define LOG(x)           \
{                        \
    cout<<x<<endl<<endl; \
}

But, need to add backward slash to add each new line
*/

int calculate(int a, int b, int c)
{
    return a + b * c;  // BODMAS is naturally followed
}

#define CALCULATE(a, b, c) a + b * c  // Macro with BODMAS applied

void Macros()
{
    // cout<<"Macros [START]"<<endl<<endl;
    LOG("[START]");

    int x=2;
    int y=3;
    int z=5;

    cout<<" return type stack Function Result :: "<< calculate(x+1, y+2, z) <<endl;
    cout<<"{Risky While using Arthimetic operations} Macro Function Result :: "<< CALCULATE(x+1, y+2, z) <<endl;


    //cout<<"Macros [END]"<<endl<<endl;
    LOG("[END]");
}
