#include "Main.h"
#include <string.h>

class String
{
private:
    char *m_Str;
    size_t m_Size;

public:
    String(const char *p_Str)
    {
        m_Size = strlen(p_Str)+1;
        m_Str = new char[m_Size];
        memcpy(m_Str, p_Str, m_Size);
    }

    String& operator=(const String& string)
    {
        cout<<"called "<<endl;
        m_Size = string.m_Size;
        m_Str = new char[string.m_Size];
        memcpy(m_Str, string.m_Str, m_Size);

        return *this;
    }

    String(const String& string) : m_Size(string.m_Size)
    {
        cout<<"Copy called "<<endl;
        m_Str = new char[string.m_Size];
        memcpy(m_Str, string.m_Str, m_Size);
    }

    char & operator[](const int index)
    {
        return m_Str[index];
    }


    ~String()
    {
        delete [] m_Str;
    }

    friend ostream& operator<<(ostream& stream, const String& string);
};


ostream& operator<<(ostream& stream, const String& string)
{
    stream<<string.m_Str;

    return stream;
}

int main()
{
    String abc = "Anup";
    String second = abc;

    cout<<"value of abc is :: ["<<abc<<"]"<<endl;    
    cout<<"value of second is :: ["<<second<<"]"<<endl;    

    abc[1] = 'k';

    cout<<"value of abc is :: ["<<abc<<"]"<<endl;    
}
