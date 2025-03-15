#include "Main.h"
#include <string.h>

class Stringx {

public:
    char *m_Str;
    size_t m_Size;

    Stringx(const char *str)
    {
        m_Size = strlen(str)+1;
        m_Str = new char[m_Size];

        memcpy(m_Str, str, m_Size);
    }

    Stringx(const Stringx& other) : m_Size(other.m_Size)
    {
        cout<<"Copy Called"<<endl;
        m_Str = new char[m_Size];
        memcpy(m_Str, other.m_Str, m_Size);
    }

    Stringx& operator +=(const char *str)
    {
        size_t strSize = strlen(str)+1;

        char *temp = new char[m_Size];

        memcpy(temp, m_Str, m_Size);
//        cout<<"size of m_Str :: "<<m_Size<<", m_Str :: ["<<m_Str<<"]"<<endl;

        delete [] m_Str;

        m_Size += strlen(str);
        m_Str = new char[m_Size];

        memcpy(m_Str, temp, strlen(temp));

//        cout<<"value of char "<<*(m_Str+strlen(temp))<<endl;
  ///      cout<<"value of char "<<*(m_Str+strlen(temp)-1)<<endl;
     //   cout<<"size of str :: "<<strSize<<", str :: ["<<str<<"]"<<endl;
      //  cout<<"size of m_Str :: "<<m_Size<<", m_Str :: ["<<m_Str<<"]"<<endl;
        memcpy(m_Str+strlen(temp), str, strSize);
       // cout<<"size of m_Str :: "<<m_Size<<", m_Str :: ["<<m_Str<<"]"<<endl;

        delete [] temp;

        return *this;
    }

    Stringx& operator=(const Stringx& other)
    {
        cout<<"Assignment Called"<<endl;
        m_Size = other.m_Size;
        m_Str = new char[m_Size];
        memcpy(m_Str, other.m_Str, m_Size);

        return *this;
    }

 


    ~Stringx()
    {
        cout<<"destructor called !!"<<endl;
        delete [] m_Str;
    }

    friend Stringx operator+(const Stringx &lhs, const Stringx &rhs);
  //  friend Stringx operator+(const char *lhs, const char *rhs);
};


Stringx operator+(const Stringx& lhs, const Stringx& rhs) {
    size_t newSize = lhs.m_Size + rhs.m_Size - 1;
    char *newStr = new char[newSize];

    memcpy(newStr, lhs.m_Str, lhs.m_Size - 1);
    memcpy(newStr + lhs.m_Size - 1, rhs.m_Str, rhs.m_Size);

//    Stringx result(newStr);
  //  delete[] newStr; // Clean temporary memory

    return Stringx(newStr);
}


/*
Stringx operator+(const char *lhs, const char *rhs) {
    size_t newSize = strlen(lhs) + strlen(rhs) + 1;
    char *newStr = new char[newSize];

    memcpy(newStr, lhs, strlen(lhs));
    memcpy(newStr + strlen(lhs), rhs, strlen(rhs) + 1);  // Include null terminator

    Stringx result(newStr);
    delete[] newStr;  // Clean temporary memory

    return result;
}
*/

int main()
{
    Stringx abc = "Anup";

    cout<<"value of abc = "<<abc.m_Str<<endl;
//    Stringx abc2("! How r u?");
//    abc += "! How r u?";

    abc = Stringx("Abc") + Stringx("Def");
//    abc = "Abc" + "Def";

    cout<<"value of abc = "<<abc.m_Str<<endl;
}
