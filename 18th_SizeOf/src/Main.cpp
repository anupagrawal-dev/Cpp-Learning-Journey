#include "Main.h"

class EmptyClass {

};

class ClassWithOneFunc {

public:
    void test_func()
    {
        cout<<"test_func"<<endl;
    }
};

class ClassWithOneData {
public:
    int x;

};

class ClassWithOneDataAndOneFunc {
public:
    int x;
    void test_func()
    {
        cout<<"test_func"<<endl;
    }
};

class ClassWithStaticData {
public:
    static int data;

};

class ClassWithStaticFunc {
public:
    static void func()
    {
        cout<<"calling static func"<<endl;
    }
};

class ClassWithVirtualFunc {
public:
    virtual void func()
    {
        cout<<"calling static func"<<endl;
    }
};

class ClassWithVirtualFuncAndOneChar {
public:
    char a;

    virtual void func()
    {
        cout<<"calling static func"<<endl;
    }
}__attribute__((packed));

int ClassWithStaticData::data = 5;

int main()
{
    cout<<"Print Sizeof Of All Classess"<<endl<<endl;

    cout<<"EmptyClass :: "<<sizeof(EmptyClass)<<endl;

    cout<<"ClassWithOneFunc :: "<<sizeof(ClassWithOneFunc)<<endl;

    cout<<"ClassWithOneData :: "<<sizeof(ClassWithOneData)<<endl;
    cout<<"ClassWithOneDataAndOneFunc :: "<<sizeof(ClassWithOneDataAndOneFunc)<<endl;

    cout<<"ClassWithStaticFunc :: "<<sizeof(ClassWithStaticFunc)<<endl;

    cout<<"ClassWithStaticData :: "<<sizeof(ClassWithStaticData)<<endl;

    cout<<"ClassWithVirtualFunc :: "<<sizeof(ClassWithVirtualFunc)<<endl;
    cout<<"ClassWithVirtualFuncAndOneChar :: "<<sizeof(ClassWithVirtualFuncAndOneChar)<<endl;

    cout<<"\n--------------------****--------------------\n\n";

    cout<<"Print Sizeof Of object All Classess"<<endl<<endl;

    EmptyClass e1;
    ClassWithOneFunc c1;
    ClassWithOneData d1;
    ClassWithOneDataAndOneFunc f1;
    ClassWithStaticFunc s1;
    ClassWithStaticData s2;
    ClassWithVirtualFunc v1;
    ClassWithVirtualFuncAndOneChar one1;

    cout<<"EmptyClass :: "<<sizeof(e1)<<endl;

    cout<<"ClassWithOneFunc :: "<<sizeof(c1)<<endl;

    cout<<"ClassWithOneData :: "<<sizeof(d1)<<endl;
    cout<<"ClassWithOneDataAndOneFunc :: "<<sizeof(f1)<<endl;

    cout<<"ClassWithStaticFunc :: "<<sizeof(s1)<<endl;

    cout<<"ClassWithStaticData :: "<<sizeof(s2)<<endl;
    cout<<"ClassWithVirtualFunc :: "<<sizeof(v1)<<endl;
    cout<<"ClassWithVirtualFuncAndOneChar :: "<<sizeof(one1)<<endl;

}
