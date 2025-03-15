#include "ReturnWithOptional.h"

optional<int> findValue(bool found)
{
    if(found) return 42;
    return nullopt;
}


void ReturnWithOptional()
{
    cout<<"returnWithOptional [START]"<<endl;

    {
        auto result = findValue(true);

        cout<<"\n[ Optional ";
        if (result)
        {
            cout << "Value found:" << *result;
        }
        else
        {
            cout << "No value found:";
        }
        cout<<" ]\n";
    }

    {
        auto result = findValue(false);

        cout<<"\n[ Optional ";
        if (result)
        {
            cout << "Value found:" << *result;
        }
        else
        {
            cout << "No value found:";
        }
        cout<<" ]\n\n";
    }
    cout<<"returnWithOptional [END]"<<endl;
}
