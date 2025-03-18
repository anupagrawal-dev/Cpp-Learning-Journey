#include "AdvancedCalculator.h"

class Calc {

private:
    double firstNum;
    double secondNum;
    double result;
    bool   IsReserve;

public:

    Calc() : firstNum(0), secondNum(0), result(0), IsReserve(false)
    {
    }

    Calc(int a, int b, int res, bool reserve)
        : firstNum(a), secondNum(b), result(res), IsReserve(reserve)
    {
    }

    void addition()
    {
        result = firstNum + secondNum;
    }

    void subtraction()
    {
        result = firstNum - secondNum;
    }

    void multiplication()
    {
        result = firstNum * secondNum;
    }

    void devision()
    {
        result = firstNum / secondNum;
    }

    void checkAndResetResult()
    {
        char ch;

        cin>>ch;
        
        if(ch == 'Y' || ch == 'y')
        {
            firstNum = result;
            IsReserve = true;
        }
        else
        {
            firstNum = 0;
            secondNum = 0;
            result = 0;
            IsReserve = false;
        }
    }

    void readNumbers()
    {
        if(IsReserve)
        {
            cout<<"Enter 2nd Number :: ";
            cin>>secondNum;
        }
        else
        {
            cout<<"Enter 1st Number :: ";
            cin>>firstNum;
            cout<<"Enter 2nd Number :: ";
            cin>>secondNum;
        }
    }

    double getResult()
    {
        return result;
    }
};



void AdvancedCalculator()
{
    cout<<"Calculator [START]"<<endl<<endl;
    Calc c1;
    char ch;
    int Operation=0;

    do
    {
        cout<<"***CALCULATOR***"<<endl;
        //c1.readNumbers();
        //cout<<"\nEnter 2 numbers :: "<<endl;
        c1.readNumbers();

        cout<<"\n\n** Operations **\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Devision\n\n";
        cin>>Operation;

        switch(Operation)
        {
            case 1:
                c1.addition();
                break;
            case 2:
                c1.subtraction();
                break;
            case 3:
                c1.multiplication();
                break;
            case 4:
                c1.devision();
                break;
            default:
                cout<<"Invalid useCase please enter number between 1 to 4";
                break;
        }


        if(Operation >= 1 && Operation <= 4)
        {
            cout<<"Result :: ["<<c1.getResult()<<"]"<<endl<<endl;

            cout<<"Do you want to reserve this result as firstNum?(y/n|Y/N) :: ";
            c1.checkAndResetResult();

            cout<<"Do you want to continue?(Y/N|y/n) :: ";
            cin>>ch;
        }
        else
        {
            ch = 'Y';
        }
        cout<<endl<<endl;

    }while(ch == 'y' || ch == 'Y');


    cout<<"\nCalculator [END]"<<endl;
}
