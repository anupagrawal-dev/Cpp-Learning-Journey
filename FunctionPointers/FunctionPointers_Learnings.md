
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

Callback function is a function passed as an argument to another function, allowing asynchronous execution.

```
void PrintValue(int value)
{
    cout<< "Value :: "<<value<<endl;
}

void callback_function(const vector<int>& Values, void (*func)(int))
{
    for( int value: Values)
    {
        func(value);
    }
}

int main()
{
    vector<int> values = { 1, 2, 4, 2, 3};
    callback_function(values, PrintValue);

}
```

Here, PrintValue is `callback` function, `func` is void function pointer with int parameter pointing to PrintValue function.


1. **Fuction Tables** :-

Function tables allow dynamic selection of functions at runtime.


