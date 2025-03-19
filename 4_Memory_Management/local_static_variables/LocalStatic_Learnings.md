**Local Static in c++** :-

Static keyword related variables are like global variables. But, scope of static variable is limited to that cpp file.

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
```

`Main.cpp`
```
extern int a;
```

Lifetime for global/local static :- Yes it is lifetime till program is running for both global/local static

scope for global static :- scope is limited to that .cpp file. It will not known by other .cpp files

scope for local static :- scope is global for the function where we declared static locally.

`Main.cpp`
```
void Function()
{
	int i=0;
	i++;
	cout<<"i = "<<i<<endl;
}

int main()
{
	for(int i=0;i<5; i++)
		Function();
}
```

`o/p`:-
```
i = 1
i = 1
i = 1
i = 1
i = 1
```
But, when you use static keyword before int i=0;

Updated `Main.cpp`
```
void Function()
{
	static int i=0;
	i++;
	cout<<"i = "<<i<<endl;
}

int main()
{
	for(int i=0;i<5; i++)
		Function();
}
```

o/p will be :-
```
i = 1
i = 2
i = 3
i = 4
i = 5
```
Why, because static forces int to be declared only once and allow it to be declared globally to that function And skips declaration and initilazation each time when function called except first time.
