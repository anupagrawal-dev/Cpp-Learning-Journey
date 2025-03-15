#include "Main.h"
#include "Multi.h"
#include "ReturnWithPair.h"
#include "ReturnWithTuple.h"
#include "ReturnWithStructAndClass.h"
#include "ReturnWithVectorAndArray.h"
#include "ReturnWithPassByReference.h"
#include "ReturnWithOptional.h"

int main()
{
    actual_Func();

    /* Calling different functions for different ways of multiple return values example */

    cout<<"Multiple ways of returning multiple values from function by calling shared lib function"<<endl<<endl;

    cout<<"1. Return Multiple Values using std::pair from C++98. Header required <utitlity>"<<endl<<endl;
    returnWithPair();

    cout<<"2. Return Multiple Values using std::tuple from c++11. Header required <tuple>"<<endl<<endl;
    ReturnWithTuple();

    cout<<"3. Return Multiple Values using struct and class from c++98"<<endl<<endl;
    ReturnWithStructAndClass();

    cout<<"4. Return Multiple Values using std::vector and std::array from c++98. Header required <vector> for vector and <array> for array"<<endl<<endl;
    ReturnWithVectorAndArray();

    cout<<"5. Return multiple values using pass by reference from c++98"<<endl<<endl;
    ReturnWithPassByReference();

    cout<<"6. Return multiple values using std::optional from c++17. Header required <optional>"<<endl<<endl;
    ReturnWithOptional();
}
