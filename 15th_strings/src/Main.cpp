#include "Main.h"
#include <string>

int main()
{
    string test = string("Hello") + " World";

    bool contains = test.find("rld") != string::npos;

    string test1 = "Cherno";

//    cout<<"test1.find no = "<<test1.find("no1")<<endl;
    bool con = test1.find("no1") != string::npos;
    cout<<"return true or false = "<<con<<endl;

    cout<<"contains = "<<(bool)contains<<endl;

    cout<<test<<endl;

    using namespace string_literals;

    string abc = "Hello"s + " World";

    cout<<"abc = "<<abc<<endl;
    cout<<"size of abc :: "<<sizeof(abc)<<endl;

    wstring def = L"Okies";

    wcout<<"def = "<<def<<endl;
    cout<<"size of def :: "<<sizeof(def)<<endl;

    string multi = R"(line1
line2
                    line3)";

    cout<<"multi line string = "<<multi<<endl;

}
