# 37 — Operators & Operator Overloading

*Category: C++ Core*

> Define what operators mean for your own type — chosen by operand types at compile time.

## Must-remember points

- An operator is a **function with a special name** (`operator+`, `operator==`, `operator<<`); overloading = defining what it does for your type. It's **compile-time polymorphism** (the compiler picks the function from the operand types).
- Two forms: **member** (left operand is `this`) and **free function** (both operands are params). Use a free function when the left operand isn't your class (`cout << e`, `2 * v`).
- `operator<<` must be a **free** function (left operand is the stream, which you don't own) and returns `std::ostream&` so calls **chain** (`cout << a << b`).
- Params as `const T&` (reference = no copy, const = don't modify the argument); trailing `const` on a member = doesn't modify `this`.
- Return **by value** for arithmetic (`+` makes a NEW object); return `*this` **by reference** for assignment/compound (`=`, `+=`) so `a = b = c` chains.
- Limits: can't invent operators or change precedence/arity; at least one operand must be **user-defined** (`int+int` can't be redefined); can't overload `::`, `.`, `.*`, `?:`, `sizeof`.

## Examples: + (by value), = (by reference), << (free)

```cpp
class Entity {
    int a;
public:
    Entity(int a = 0) : a(a) {}

    // arithmetic: makes a NEW object -> return BY VALUE
    Entity operator+(const Entity& rhs) const {
        return Entity(a + rhs.a);
    }

    // assignment: modifies THIS object -> return *this BY REFERENCE (chains a = b = c)
    Entity& operator=(const Entity& rhs) {
        a = rhs.a;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Entity& e);
};

// stream: FREE function, returns the stream so << can chain
std::ostream& operator<<(std::ostream& os, const Entity& e) {
    os << e.a;
    return os;
}

Entity x(4), y(5), z;
z = x + y;                     // operator+ (new object) then operator= (into z)
std::cout << z << std::endl;   // operator<< -> prints 9
```

## ⚠ Easily confused

- **member vs free operator** — Member: left operand is `this`. Free: both operands are params — required when the left operand isn't your type (`cout << e`, `2 * v`).
- **+ returns by value vs = returns by reference** — `+` makes a NEW object -> return by value. `=` modifies the existing object -> `return *this;` by reference (enables a = b = c).
- **overloadable vs not** — Can't redefine `int+int` (both built-in), can't invent new operators or change precedence; can't overload `::` `.` `.*` `?:` `sizeof`.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 37).
