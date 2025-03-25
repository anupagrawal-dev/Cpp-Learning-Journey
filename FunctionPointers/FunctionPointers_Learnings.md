
**Function Pointers** :-

Function pointers are pointers which allows us to store address of functions and call them dynamically.

Function Pointers enable callback mechanisms, function tables and dynamic function invocation.

`Syntax` :-

```
returnType (*pointerName)(parameter Types);
```

E.g. :-

```
void HelloWorld()
{
    cout<<"Hello World"<<endl;
}

int main()
{
    void (*func)() = HelloWorld;
}
```

1. **Enabling Callback Mechanisms** :-



