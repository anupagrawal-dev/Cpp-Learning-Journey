#include "Main.h"
#include "BasicCalculator.h"
#include "AdvancedCalculator.h"

int main()
{
    int calc = 0;

    cout<<"Which Calculator you want to execute?\n1.Basic Calculator\n2.Advanced Calculator\n\n";
    cin>>calc;

    calc == 1 ? BasicCalculator() : calc == 2 ? AdvancedCalculator() : BasicCalculator(); 

    /* 
        Alternative of above ternary operator is
        if(calc == 1)
        {
            BasicCalculator();
        }
        else
        {
            if(calc == 2)
            {
                AdvancedCalculator();
            }
            else
            {
                BasicCalculator();
            }
        }
    */
}
