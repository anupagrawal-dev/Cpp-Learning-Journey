**Static Keyword** :-

Static keyword  related variables are like global variables. But, scope of static variable is limited to that cpp file. 

In compilation process, linker will not look for defination of this variable outside of that file.

If you define a static global variable then you can define same global variable name in other files as it doesn't effect on other files and it is restricted to be used in same file.
E.g.

`test.cpp`
```
static int a=6;

Main.cpp

int a=7;
```
Mainly it means that linker will not check static variable in global scope.



If you are using same global variable in 2 cpp files. Then you have to extern keyword in one of file as a declaration.
E.g.

`test.cpp`
```
int a=5;

Main.cpp

extern int a;

```

static keyword inside Class


Use static variables instead of using global variables if you want to have connection between translation units means in cpp file

Static keyword methods or variables will be global for a class or we can say it will be `common between all objects of that class`.
    If you change value of that static variable from 1 object.
    Then that gets updated for each object as it is not object specific. Static is class specific.

`**IMP Notes**` :- 
1. If you declared variable using static keyword inside a class, then you have to initialize that variable outside of that class as it is not specific for an single object of the class.
2. If you define static keyword function then it can only allow static keyword variables inside that function.

