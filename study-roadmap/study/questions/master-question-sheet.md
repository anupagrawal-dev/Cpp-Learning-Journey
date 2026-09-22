# Master Question Bank

192 single-focus questions across 42 topics, in learning order. Each question asks one thing; the answer is hidden in a <details> block. (Topics 32–42 — Member Initializer List, Ternary Operator, Creating / Instantiating Objects, The new Keyword, Implicit Conversion & explicit, Operators & Operator Overloading, The this Keyword, Object Lifetime, Smart Pointers, Copying & Copy Constructors, The Arrow Operator — were added on 2026-09-13…20 and appear at the end until the next full regenerate re-sorts them into C++ Core.)

## C++ Core

### 01 — Control Flow  (4 Qs)
**Q1. What does this code print?**

```cpp
int x = 1;
switch (x) {
  case 1: cout << "A";
  case 2: cout << "B"; break;
  case 3: cout << "C";
}
```

<details><summary>Show answer</summary>

It prints **AB**. `x` is 1, so control enters `case 1` and prints `A`. There is **no `break`** after `case 1`, so execution *falls through* into `case 2`, prints `B`, and only then hits `break`. `case 3` never runs. To print only `A`, add a `break` after `case 1`.

</details>

**Q2. When should you use a `do-while` loop instead of a `while` loop?**

<details><summary>Show answer</summary>

Use a `do-while` when the body must run **at least once** before the condition is checked — because a `do-while` evaluates its condition *after* running the body, whereas a `while` checks *first* and may run zero times.
```cpp
do {
    x = readInput();
} while (!valid(x));   // ask once, then keep asking until valid
```

</details>

**Q3. Does this compile, and what is the value of `x` after the `if`?**

```cpp
int x = 0;
if (x = 5) {
    cout << "entered";
}
// what prints? what is x now?
```

<details><summary>Show answer</summary>

It **compiles and runs fine** — this is *not* a compiler error, and calling it a 'bug' would be wrong: it's valid C++. `=` is **assignment**, not comparison, so `x = 5` stores 5 in `x`, and the value of that expression is 5, which is truthy — the `if` body always runs and `x` is **5** afterward. It's usually a **typo for `==`** (comparison), so it's a logic pitfall rather than something the compiler rejects. Many compilers warn about it, and writing `if (5 == x)` would turn the typo into a real compile error.

</details>

**Q4. When is `switch` fall-through intentional rather than a mistake?**

<details><summary>Show answer</summary>

When several cases should share the same code — you deliberately leave out `break` so one case flows into the next:
```cpp
switch (grade) {
  case 'A':
  case 'B': cout << "Pass"; break;   // A and B both -> Pass
  case 'F': cout << "Fail"; break;
}
```

</details>

### 02 — Pointers  (5 Qs)
**Q5. What is the difference between `*p` and `&x`?**

<details><summary>Show answer</summary>

`&x` means **'address of x'** — it produces the memory address where `x` lives. `*p` means **'dereference p'** — go to the address stored in `p` and read/write the value there. They are inverses: `*(&x)` is just `x`.
```cpp
int x = 42;
int* p = &x;   // p holds x's address
int y = *p;    // y = 42 (value at that address)
*p = 99;       // x is now 99
```

</details>

**Q6. For a heap pointer `p`, what does printing `p` give you versus printing `&p`?**

```cpp
int* p = new int(5);
cout << p;    // the heap address
cout << &p;   // where p itself lives (stack)
```

<details><summary>Show answer</summary>

`p` is the value stored *in* the pointer — the **address it points to** (here, the heap block from `new`). `&p` is the address of the **pointer variable itself**, which sits on the stack. They are two different addresses. To inspect the heap allocation you print `p`; `&p` only tells you where the pointer lives.

</details>

**Q7. What is the difference between a null pointer and a dangling pointer?**

<details><summary>Show answer</summary>

A **null** pointer holds the address 0 — it deliberately points to nothing, and you can safely test for it (`if (p) ...`). A **dangling** pointer holds an address that *used to* be valid but whose memory has been freed or gone out of scope; it still looks like a normal non-zero address, so you **cannot** detect it by checking — using it is undefined behaviour.
```cpp
int* p = nullptr;   // null: safe to check
int* q = new int(3);
delete q;           // q now dangles (still non-null!)
```

</details>

**Q8. Can a pointer be changed to point somewhere else after it is created?**

<details><summary>Show answer</summary>

Yes. Unlike a reference, a pointer can be **reseated** any number of times, and can be set to `nullptr`.
```cpp
int a=1, b=2;
int* p = &a;   // points to a
p = &b;        // now points to b
p = nullptr;   // now points to nothing
```

</details>

**Q9. Where does a pointer variable itself live in memory?**

<details><summary>Show answer</summary>

The pointer **variable** — the 8 bytes holding the address on a 64-bit machine — lives wherever it's declared, typically on the **stack** as a local. That is separate from what it *points to*, which can live anywhere: the stack (`int* p = &local;`), the heap (`int* p = new int;`), or static storage.

</details>

### 03 — Stack & Heap Memory  (6 Qs)
**Q10. Why is stack allocation faster than heap allocation?**

<details><summary>Show answer</summary>

Stack memory is **already committed** to the process, so allocating a local is just moving the stack-pointer register down by the needed bytes; freeing is moving it back when the function returns — no searching, no bookkeeping. Heap allocation (`new`) must ask the allocator to **search a free list** for a suitable block, mark it used, and return it (and you must `delete` it later). That search + metadata make it slower.

</details>

**Q11. Which direction does the stack grow, and where is its 'top'?**

<details><summary>Show answer</summary>

On typical machines the stack grows **downward**, toward **lower** addresses — each call/`push` *decrements* the stack pointer. So the 'top of stack' (the most recent item) is actually at the **lowest** address currently in use, the opposite of the everyday picture of a stack growing up.

</details>

**Q12. What happens when the caller dereferences the pointer this function returns?**

```cpp
int* bad() {
    int x = 42;
    return &x;   // returning the address of a local
}
```

<details><summary>Show answer</summary>

It's a **dangling pointer**, so dereferencing it is **undefined behaviour**. `x` is a local — it lives on `bad()`'s stack frame; when `bad()` returns, that frame is reclaimed and `x` no longer exists, yet the returned pointer still holds its old address. Reading through it may give garbage, may seem to work, or may crash. To return something that outlives the call, allocate on the heap (`new`) or return by value.

</details>

**Q13. What happens if you free `new[]` memory with plain `delete` (instead of `delete[]`)?**

<details><summary>Show answer</summary>

**Undefined behaviour.** Array `new[]` and scalar `new` can use different bookkeeping, so they must be matched exactly: `new` ↔ `delete`, and `new[]` ↔ `delete[]`. Mismatching them can corrupt the heap or leak — even if it *seems* to work on one compiler.
```cpp
int* a = new int[10];
delete a;     // WRONG — must be delete[] a;
```

</details>

**Q14. Why does very deep recursion crash a program?**

<details><summary>Show answer</summary>

Each function call pushes a **stack frame** (return address, saved registers, locals). The stack is small — typically only **1–8 MB**. Deep or unbounded recursion keeps pushing frames until the stack is exhausted → **stack overflow** (a crash). This is one reason large data lives on the heap instead.

</details>

**Q15. Why do the heap addresses a program prints change on every run?**

<details><summary>Show answer</summary>

Because of **ASLR** (Address Space Layout Randomization): the OS deliberately randomizes where memory regions are placed each run, so attackers can't predict addresses. The structure is the same but the absolute base shifts, so `new int` prints a different address each time.

</details>

### 04 — References  (4 Qs)
**Q16. Name two things a reference cannot do that a pointer can.**

<details><summary>Show answer</summary>

A reference **cannot be null** and **cannot be reseated** (rebound to a different variable after initialization). It also has **no arithmetic** and must be initialized when declared. A pointer can be null, can point at different things over time, and supports pointer arithmetic.

</details>

**Q17. What does this print, and why?**

```cpp
void byVal(int x){ x = 99; }
void byRef(int& x){ x = 99; }
int n = 1;
byVal(n); byRef(n);
cout << n;
```

<details><summary>Show answer</summary>

It prints **99**. `byVal` gets a **copy**, so its `x = 99` changes only the local copy — `n` is untouched by it. `byRef` gets a **reference (alias)** to `n`, so its `x = 99` writes straight through to `n`. After both calls, `n` is 99.

</details>

**Q18. Why do we often pass large objects as `const T&` instead of by value?**

<details><summary>Show answer</summary>

Passing by value (`T`) **copies** the whole object, which is expensive for a big `std::string` or `std::vector`. A `const T&` binds an **alias** — no copy — while `const` guarantees the function won't modify the caller's object. So you get a reference's speed with read-only safety.
```cpp
void print(const std::string& s);  // no copy, cannot change s
```

</details>

**Q19. Why must a reference be initialized at the point where it is declared?**

<details><summary>Show answer</summary>

Because a reference is a permanent **alias** with no identity of its own — it must be bound to an existing object the moment it's created, and can never be re-bound afterward. `int& r;` is a compile error; `int& r = x;` is required. (That's exactly why a reference makes a good fixed alias but a poor 'optional' or reseatable handle — use a pointer for those.)

</details>

### 05 — Classes & Encapsulation  (3 Qs)
**Q20. If `private` gives no runtime security, what is the real point of making data private?**

<details><summary>Show answer</summary>

Two real benefits: (1) **Invariant safety** — every change must go through a public method that can *validate* it, so the object can never be put into an illegal state. (2) **Freedom to change internals** — since outside code can't touch the fields directly, you can later change how the data is stored without breaking any user of the class. `private` is a *design/compile-time* tool for controlled change, not a runtime guard against attackers.

</details>

**Q21. What is a class invariant?**

<details><summary>Show answer</summary>

An **invariant** is a rule that must always be true for a valid object — e.g. a `BankAccount`'s balance must never be negative. By keeping `balance` private and only changing it through `deposit()`/`withdraw()`, each of which checks the rule, the invariant is guaranteed after every operation, so the object is never left inconsistent.

</details>

**Q22. Show how a method can protect an invariant that a public field could not.**

<details><summary>Show answer</summary>

A method can validate *before* writing; a public field can be set to anything:
```cpp
class Account {
    double balance = 0;
public:
    bool withdraw(double amt){
        if (amt < 0 || amt > balance) return false; // guard
        balance -= amt; return true;
    }
};
```
If `balance` were public, any code could do `a.balance = -500;` and break the invariant. The method is the single validated gate.

</details>

### 06 — Classes vs Structs  (3 Qs)
**Q23. What are the ONLY two language-level differences between a `class` and a `struct`?**

<details><summary>Show answer</summary>

(1) **Default member access**: `class` members are `private` by default, `struct` members are `public` by default. (2) **Default inheritance mode**: `class B : A` is private inheritance by default, `struct B : A` is public by default. Everything else — constructors, methods, virtual functions, templates, inheritance — is identical.

</details>

**Q24. Is `x` accessible from outside here?**

```cpp
class C { int x; };
int main(){ C c; c.x = 5; }
```

<details><summary>Show answer</summary>

**No.** In a `class`, members are `private` by default, and `x` has no access specifier, so it's private — `c.x = 5;` from outside is a compile error. Change `class` to `struct` and `x` becomes public, so it would compile. That default is the whole practical difference.

</details>

**Q25. By convention, when do you use a `struct` rather than a `class`?**

<details><summary>Show answer</summary>

Use a **`struct`** for a passive bundle of public data with little or no behaviour (a plain-old-data aggregate, e.g. `struct Point{int x,y;};`). Use a **`class`** for an encapsulated type that maintains invariants and exposes behaviour through methods while hiding its data. The compiler treats them the same — this is purely a readability convention.

</details>

### 07 — How to Write a Class  (4 Qs)
**Q26. Why does this compile but fail to link with 'undefined reference to Entity::GetX()'?**

```cpp
// entity.h
class Entity { int x; public: int GetX(); };
// entity.cpp
int GetX() { return x; }   // note: no Entity::
```

<details><summary>Show answer</summary>

The out-of-class definition is missing the `Entity::` qualifier, so `int GetX(){...}` defines an **unrelated free function** named `GetX`, not the member. The class's declared `GetX()` therefore has **no definition**, and the linker complains. Fix: `int Entity::GetX() { return x; }`.

</details>

**Q27. When should a member function be marked `const`?**

<details><summary>Show answer</summary>

Mark a method `const` whenever it **doesn't modify the object's state** — typically getters: `int GetX() const;`. The payoff: it can then be called on `const` objects and `const` references, and the compiler enforces the read-only promise (modifying a member inside a `const` method is an error unless the member is `mutable`). Missing `const` on getters is something interviewers notice.

</details>

**Q28. What happens if you put a non-inline function's full body in a header that multiple .cpp files include?**

<details><summary>Show answer</summary>

You get a **duplicate-symbol link error**, because of the **One Definition Rule (ODR)**: a non-inline function may be *defined* only once in the whole program. A header is textually pasted into every `.cpp` that `#include`s it, so a full body in the header becomes a definition in *each* including `.cpp` → multiple definitions. Fix: put the **declaration** in the header and the single **definition** in one `.cpp` (or mark it `inline`).

</details>

**Q29. What is the difference between a declaration and a definition?**

<details><summary>Show answer</summary>

A **declaration** tells the compiler something *exists* and its type/signature (`int GetX();`) — it can appear many times. A **definition** actually provides the body or storage (`int Entity::GetX(){return x;}`) — it must appear exactly once (ODR). Declarations live in headers; the single definition lives in a source file.

</details>

### 08 — Static (outside classes)  (4 Qs)
**Q30. What does calling `counter()` three times in a row print?**

```cpp
int counter(){ static int n = 0; return ++n; }
```

<details><summary>Show answer</summary>

It prints **1 2 3**. The `static` local `n` is initialized to 0 **once**, on the first call, then **retains its value between calls** (lifetime = the whole program, scope = the function). So each call increments the same `n`: 1, 2, 3. Without `static`, `n` would reset to 0 each call and print 1 1 1.

</details>

**Q31. What does `static` do to a variable declared at file/global scope?**

<details><summary>Show answer</summary>

It gives the variable **internal linkage** — the symbol is visible **only within that translation unit** (that `.cpp`). Other files can't see or link to it, and two files can each have their own `static int x;` with no clash. This is the opposite of `extern`, which shares one symbol across files.

</details>

**Q32. Why does a `static` local variable initialize safely regardless of other globals' init order?**

<details><summary>Show answer</summary>

Because a `static` local initializes **on first use** — the first time control reaches its declaration — not at program startup. This dodges the *static initialization order fiasco*: globals in **different** translation units are initialized in an **unspecified** order, so one global's constructor using another (from a different `.cpp`) may run before that other is initialized (a bug). A static local's init order is instead defined by *call order*, which is deterministic. (Basis of the Meyers singleton.)

</details>

**Q33. What does `extern int x;` declare?**

<details><summary>Show answer</summary>

It's a **declaration** (not a definition) saying: 'an `int x` with external linkage is defined in some *other* translation unit — share that one.' It reserves no storage itself. If no `.cpp` actually *defines* `int x;` anywhere, the linker can't find the symbol and reports **'undefined reference to x'**.

</details>

### 09 — Static (for Classes & Structs)  (3 Qs)
**Q34. Does a `static` data member increase each object's `sizeof`?**

<details><summary>Show answer</summary>

No. A `static` member is **shared by all objects** — there is exactly **one** copy in static storage, not one per object. So it doesn't live inside the object and doesn't count toward `sizeof(obj)`. (An ordinary non-static member does live in each object and adds to its size.) A classic use is a counter of how many instances exist.

</details>

**Q35. Why does this fail to link with 'undefined reference to Entity::count'?**

```cpp
struct Entity { static int count; };
// no definition anywhere
int main(){ Entity::count++; }
```

<details><summary>Show answer</summary>

A **non-inline static data member** is only *declared* inside the class — it still needs exactly one **definition** outside it. Without that, the linker can't find storage for `Entity::count`. Fix (pre-C++17): add `int Entity::count = 0;` in one `.cpp`. Fix (C++17+): declare it `inline static int count = 0;` inside the class, which provides the definition automatically.

</details>

**Q36. Why can't a `static` member function read a normal (non-static) data member?**

<details><summary>Show answer</summary>

A static member function has **no `this` pointer** — it isn't tied to any particular object, and you can call it as `Class::fn()` with no instance at all. Since per-object data lives *in an object* and there's no object in hand, there's nothing to read it from. A static function can only touch **static** members (or data passed in as arguments).

</details>

### 10 — Enums  (4 Qs)
**Q37. In `enum E { A = 3, B, C };`, what are the values of `B` and `C`?**

<details><summary>Show answer</summary>

`B == 4` and `C == 5`. Enumerators without an explicit value take the **previous value + 1**. `A` is set to 3, so `B` becomes 4 and `C` becomes 5. (If nothing were assigned at all, they would start at 0.)

</details>

**Q38. Give two problems with a plain `enum` that `enum class` fixes.**

<details><summary>Show answer</summary>

(1) **Name leakage**: a plain `enum`'s names go into the enclosing scope, so `enum Color{Red}` and `enum Fruit{Red}` collide. `enum class Color{Red}` scopes it as `Color::Red`. (2) **Implicit int conversion**: a plain enum converts to `int` silently, so you can accidentally compare unrelated enums or do arithmetic on them; `enum class` blocks that (you must `static_cast<int>(x)` deliberately).

</details>

**Q39. How do you make an enum occupy only 1 byte instead of the default 4?**

<details><summary>Show answer</summary>

Give it an explicit **underlying type**:
```cpp
enum class Color : uint8_t { Red, Green, Blue };
```
The `: uint8_t` fixes storage to 1 byte — useful when packing many enum values into structs or over the wire.

</details>

**Q40. How do you convert an `enum class` value to an `int`?**

<details><summary>Show answer</summary>

With an explicit cast: `int n = static_cast<int>(Color::Green);`. It's deliberately *not* automatic — `enum class` is type-safe and refuses implicit conversion to `int`, which prevents accidental mixing of unrelated enums and silent arithmetic bugs. You opt in with the cast only when you really mean it.

</details>

### 11 — Constructors  (4 Qs)
**Q41. Why does `Entity e;` stop compiling once you add a constructor that takes arguments?**

```cpp
class Entity {
public:
    Entity(int x) { /*...*/ }   // now Entity e; fails
};
```

<details><summary>Show answer</summary>

As soon as you **declare any constructor of your own**, the compiler stops providing the free **default (no-argument) constructor**. So `Entity e;` (which needs a no-arg ctor) no longer compiles. Fixes: add your own no-arg ctor, or explicitly request the compiler's with `Entity() = default;`.

</details>

**Q42. Name two cases where a member initializer list is *required*, not merely preferred.**

<details><summary>Show answer</summary>

The `: member(value), ...` list (which initializes members directly, before the body) is **required** for: (1) **`const` members** — they must be initialized, never assigned; and (2) **reference members** — same reason (a reference must bind at creation). It's also required for member objects whose type has **no default constructor**.
```cpp
class A { const int id; int& ref;
  A(int i, int& r) : id(i), ref(r) {}  // must use init list
};
```

</details>

**Q43. Why prefer an initializer list over assigning members inside the constructor body?**

<details><summary>Show answer</summary>

The init list **constructs each member once, directly** with the right value. Assigning in the body first **default-constructs** the member, then **overwrites** it — two steps, wasteful for non-trivial types, and outright illegal for `const`/reference members. So the init list is both faster and more capable.

</details>

**Q44. What does `Entity e();` actually declare?**

<details><summary>Show answer</summary>

A **function** named `e` that takes no parameters and returns an `Entity` — *not* an object. This is the **'most vexing parse'**: the compiler prefers to read it as a declaration. To create an object, write `Entity e;` or `Entity e{};` (the brace form avoids the ambiguity).

</details>

### 12 — Destructors & RAII  (4 Qs)
**Q45. `Base` has a non-virtual destructor — what happens when `delete b;` runs?**

```cpp
struct Base { ~Base(){} };            // non-virtual!
struct Derived : Base { /* owns memory */ };
Base* b = new Derived();
delete b;
```

<details><summary>Show answer</summary>

Only `~Base()` runs. `delete b` goes through a `Base*` whose destructor is non-virtual, so it uses static dispatch and `~Derived()` is **never called** — anything `Derived` owns is leaked (the standard calls this undefined behaviour). To make it correct, declare the base destructor **`virtual`** (`virtual ~Base();`); then `delete b` runs `~Derived()` first, then `~Base()`.

</details>

**Q46. Why does RAII make resource cleanup automatic and exception-safe?**

<details><summary>Show answer</summary>

**RAII** (Resource Acquisition Is Initialization) ties a resource's lifetime to an object: acquire it in the **constructor**, release it in the **destructor**. A local object's destructor runs automatically when it leaves scope — **including when an exception unwinds the stack** — so the resource is always released, with no manual `free`/`close`/`unlock` to forget. `std::unique_ptr`, `std::lock_guard`, and `std::fstream` all rely on this.

</details>

**Q47. What is the Rule of Three?**

<details><summary>Show answer</summary>

If a class needs a custom **destructor**, it almost certainly also needs a custom **copy constructor** and **copy assignment operator**. Why: a class that owns a raw resource and defines only a destructor gets a compiler-generated **shallow copy** — two objects end up owning the same pointer, and when both destruct, the memory is freed twice (**double-free**). Defining all three (deep copy) prevents it. (C++11 adds move ctor/assignment → Rule of Five.)

</details>

**Q48. In what order are members and base/derived subobjects destroyed?**

<details><summary>Show answer</summary>

**Members** are destroyed in the **reverse** order of their declaration. For an inheritance chain the **derived** destructor runs first, then the **base** destructor — the mirror image of construction (base→derived to construct, derived→base to destroy).

</details>

### 13 — Inheritance  (4 Qs)
**Q49. What is object slicing?**

<details><summary>Show answer</summary>

Slicing happens when you copy a **derived** object into a **base** object *by value* — only the base part is copied and the derived part is 'sliced off', so overrides and extra data are lost.
```cpp
Derived d;
Base b = d;    // SLICED: b holds only the Base part
Base& r = d;   // OK: alias, full object, polymorphism works
Base* p = &d;  // OK: pointer, full object
```
Avoid it by handling polymorphic objects through base **pointers or references**, never by value.

</details>

**Q50. Who can access a `protected` member?**

<details><summary>Show answer</summary>

A `protected` member is accessible to the class's **own methods** and to the methods of its **derived classes** ('the family') — but not to outside code. That's the key difference from `private`, which is accessible **only** to the class's own methods, not even derived classes. `protected` lets you share implementation down the inheritance chain while hiding it from the outside world.

</details>

**Q51. In what order are the base and derived parts constructed and destroyed?**

<details><summary>Show answer</summary>

**Construction:** base first, then derived — the base subobject must be fully built before the derived part relies on it. **Destruction:** the reverse — derived first, then base. A derived object physically contains the base subobject laid out first.

</details>

**Q52. What is the difference between an 'is-a' and a 'has-a' relationship?**

<details><summary>Show answer</summary>

**is-a** means one type is a kind of another (a `Car` **is a** `Vehicle`) — modelled with **inheritance**. **has-a** means one type contains another (a `Car` **has an** `Engine`) — modelled with **composition** (a member object). A common guideline is to prefer composition unless the relationship is genuinely is-a.

</details>

### 14 — Virtual Functions  (5 Qs)
**Q53. What does `a->speak()` print here, and why?**

```cpp
struct Animal { void speak(){cout<<"Animal";} };  // not virtual
struct Dog : Animal { void speak(){cout<<"Dog";} };
Animal* a = new Dog();
a->speak();
```

<details><summary>Show answer</summary>

It prints **"Animal"**. Because `speak()` is **not virtual**, the call uses **static dispatch** — the version is chosen at compile time from the **pointer's type** (`Animal*`), so `Animal::speak` runs regardless of the real object. If you mark `speak()` **`virtual`**, it switches to **dynamic dispatch** — resolved at runtime from the object's *actual* type via the vtable — and it would print "Dog" instead.

</details>

**Q54. How does a virtual call select the right function at runtime, using the vtable and vptr?**

<details><summary>Show answer</summary>

Each class with virtual functions has one **vtable** — an array of function pointers, one slot per virtual function (overrides point to the derived versions). Each **object** stores a hidden **vptr** pointing to its class's vtable. A call `p->speak()` follows the object's vptr to its vtable, indexes the fixed slot for `speak`, and calls whatever pointer is there — so a `Dog` object's vptr leads to `Dog::speak`. That runtime lookup is dynamic dispatch.

</details>

**Q55. What is the cost of using virtual functions?**

<details><summary>Show answer</summary>

Memory: every polymorphic object stores a hidden **vptr** (~8 bytes on 64-bit), plus one vtable per class. Speed: each virtual call adds **one indirection** (load vptr → load slot → call) and usually **can't be inlined**, since the target is chosen at runtime. A class with **no** virtual functions has no vtable/vptr and pays nothing.

</details>

**Q56. What does the `override` specifier do, and why is it worth adding?**

<details><summary>Show answer</summary>

`override` tells the compiler 'this function is meant to override a base `virtual` with a matching signature.' If it *doesn't* actually match (a typo, wrong `const`, wrong parameters), you get a **compile error** instead of silently creating a brand-new function that never gets called. So it catches a common, hard-to-spot bug and documents intent.

</details>

**Q57. What does `final` do in C++?**

<details><summary>Show answer</summary>

On a **virtual function**, `final` forbids any further overriding of it in subclasses. On a **class**, `final` forbids inheriting from that class at all. It's a way to lock down an inheritance hierarchy (and can help the compiler devirtualize calls for speed).

</details>

### 15 — Interfaces / Abstract Classes  (5 Qs)
**Q58. What makes a class abstract in C++?**

<details><summary>Show answer</summary>

A class becomes **abstract** as soon as it declares at least one **pure virtual** function (`virtual void f() = 0;`). An abstract class **cannot be instantiated** directly — `Shape s;` is a compile error.

</details>

**Q59. If you can't instantiate an abstract class, what CAN you do with it?**

<details><summary>Show answer</summary>

You use **pointers or references** to it — that's the whole point of an abstract base: `Shape* s = new Circle();`. As long as the derived class (`Circle`) overrides **every** pure virtual, it's concrete and can be created, and you manipulate it polymorphically through the abstract base pointer/reference.

</details>

**Q60. What is the difference between an abstract class and an interface in C++?**

<details><summary>Show answer</summary>

Both rely on pure virtuals, but: an **abstract class** has **at least one** pure virtual and may *also* have data members and implemented (normal virtual) methods. An **interface** is the special case where **every** function is pure virtual and there's **no data** — a pure contract. C++ has no `interface` keyword; it's a convention built from an all-pure-virtual abstract class.

</details>

**Q61. Why must an interface / polymorphic base declare a virtual destructor?**

<details><summary>Show answer</summary>

Because clients hold and delete derived objects **through base pointers** (`Base* p = new Derived; ... delete p;`). If the base destructor isn't virtual, `delete p` only runs `~Base()` and the derived part leaks (undefined behaviour). A `virtual ~Base() = default;` ensures the full derived destructor chain runs.

</details>

**Q62. Can an abstract class also contain normal (non-pure) methods with bodies?**

<details><summary>Show answer</summary>

Yes. An abstract class can mix **pure virtuals** (which every subclass must implement) with ordinary **virtual methods that have bodies** (shared default behaviour). This is the *Template Method* pattern: the base defines a skeleton, forcing subclasses to fill in the pure-virtual steps while reusing the implemented ones.

</details>

## C++ Language & Safety

### 16 — const, constexpr & volatile  (4 Qs)
**Q63. Which of these compile, and which is an error?**

```cpp
int n = getInput();
const int a = n;
constexpr int b = n;
constexpr int c = 42;
```

<details><summary>Show answer</summary>

`a` and `c` compile; `b` is an **error**. `const int a = n;` is fine — `const` only means 'won't change after init', and initializing it from a **runtime** value is legal. `constexpr int b = n;` fails because `constexpr` demands a value known at **compile time**, but `n` came from runtime input. `constexpr int c = 42;` is fine — 42 is a compile-time constant.

</details>

**Q64. What is the core difference between `const` and `constexpr`?**

<details><summary>Show answer</summary>

`const` means **read-only after initialization** — but the value may be computed at **runtime**. `constexpr` is stronger: the value (or function result) must be **computable at compile time**, so it can be used where the language *requires* a compile-time constant (array sizes, template arguments, `switch` cases). Every `constexpr` is implicitly `const`; not every `const` is `constexpr`.

</details>

**Q65. Is `volatile` a correct tool for synchronizing a variable between threads?**

<details><summary>Show answer</summary>

**No.** `volatile` only tells the compiler 'don't optimize away or cache accesses — re-read from memory each time', which is for memory-mapped hardware registers and signal handlers. It provides **no atomicity and no memory-ordering guarantees**, so it can't safely synchronize threads. Use **`std::atomic`** (or a mutex) for that — those give the real guarantees.

</details>

**Q66. When does a `constexpr` function run at runtime instead of compile time?**

<details><summary>Show answer</summary>

When you call it with **arguments that aren't known at compile time**. Given compile-time constant arguments in a constant context it runs at **compile time**; given a runtime value it simply runs at **runtime** like an ordinary function.
```cpp
constexpr int sq(int x){ return x*x; }
constexpr int a = sq(5);       // compile time
int y = read(); int b = sq(y); // runtime
```

</details>

### 17 — Compile-time Constants & VLAs  (5 Qs)
**Q67. Two of these are standard C++ and one is not — which one, and what is it called?**

```cpp
constexpr int s1 = 5*4; int a[s1];
const     int s2 = 5*4; int b[s2];
          int s3 = 5*4; int c[s3];
```

<details><summary>Show answer</summary>

The third — `int s = 5*4; int c[s];` — is **not standard C++**. Because `s` is a plain (non-const) `int`, it's a runtime value, so `c[s]` is a **VLA (Variable Length Array)**. The `constexpr` and `const` versions are standard, because both give a compile-time constant size.

</details>

**Q68. Your `int a[n]` (runtime `n`) compiled fine on g++ — how do you check whether it's actually standard C++?**

<details><summary>Show answer</summary>

Add **`-pedantic`**: `g++ -std=c++17 -pedantic t.cpp` warns 'ISO C++ forbids variable length array' — proving it's a non-standard **GNU extension**, not standard C++. Add **`-pedantic-errors`** to make it a hard error. (MSVC rejects it outright.) A clean default compile on g++ only means *g++ allows the extension*, not that the standard does.

</details>

**Q69. Does the VLA warning depend on which C++ version you pick (`-std=c++11` vs `c++20`)?**

<details><summary>Show answer</summary>

No. VLAs were never part of **any** C++ standard (proposed for C++14, then removed). So the `-Wvla` warning appears under `-pedantic` regardless of the `-std` — it depends on the **flag** (`-pedantic`), not the version. It vanishes only when you drop `-pedantic` (extensions on).

</details>

**Q70. Which array sizes ARE valid standard C++?**

<details><summary>Show answer</summary>

A size that is a **compile-time constant**: either a `constexpr` value, or a `const` integer initialized with a constant expression (e.g. `const int n = 4*5;`). A plain mutable `int` — even one obviously set to a fixed value — does **not** qualify and makes the array a (non-standard) VLA.

</details>

**Q71. What runtime clue reveals that an array is actually a VLA?**

<details><summary>Show answer</summary>

`sizeof`. For a normal array, `sizeof(arr)` is a **compile-time** constant. For a **VLA**, the size isn't known until the program runs, so `sizeof(arr)` is computed at **runtime**. If `sizeof` has to be evaluated at run time, you're looking at a VLA.

</details>

### 18 — Arrays & Memory Contiguity  (4 Qs)
**Q72. An array must be laid out contiguously — is that guaranteed in virtual memory or in physical RAM?**

<details><summary>Show answer</summary>

In the process's **virtual** address space. Indexing computes `base + i*sizeof(element)` and relies on elements sitting one after another *virtually*. In **physical** RAM the array's pages can be scattered across arbitrary frames — that's fine, because the **page table** maps the contiguous virtual pages onto those scattered frames, so the program only ever sees one clean contiguous block.

</details>

**Q73. How does the compiler compute the address of `arr[i]`?**

<details><summary>Show answer</summary>

As **`base_address + i * sizeof(element)`** — a single multiply-and-add, no lookup table (which is why indexing is O(1)). This formula is exactly why an array **must be contiguous**: element `i` has to sit precisely `i` element-widths after the start.

</details>

**Q74. An `int arr[100000]` is about 400 KB — should it live on the stack or the heap, and why?**

<details><summary>Show answer</summary>

On the **heap** — `new int[100000]` or, better, `std::vector<int>`. A **local** array that big can **overflow the stack**, which is typically only 1–8 MB and shared by all frames in the call chain. Small fixed arrays are fine on the stack; large ones belong on the heap.

</details>

**Q75. With demand paging, is the physical RAM for a big `new` array allocated immediately?**

<details><summary>Show answer</summary>

No. The **virtual** address range is reserved right away (so the array looks allocated and contiguous), but the **physical frames** are typically handed out **lazily**, on first touch of each page (via page faults). So memory you allocate but never write may never consume physical RAM.

</details>

### 19 — Endianness  (5 Qs)
**Q76. On a little-endian machine, how is the int `500` (`0x000001F4`) laid out byte by byte in memory?**

<details><summary>Show answer</summary>

As **`F4 01 00 00`** — least-significant byte first. The value's bytes are `00 00 01 F4` (most-significant first, the way we write it); little-endian stores them **reversed**, so to reconstruct the value you flip them back: `F4 01 00 00` → `0x000001F4` = 500. Small values hide this (5 is `05 00 00 00`, and the leading `05` *looks* right).

</details>

**Q77. If you `cout << somePointer;`, do you see the reversed little-endian bytes or the real address?**

<details><summary>Show answer</summary>

You see the **real, human-readable address** (most-significant-first, e.g. `0x7ffee3a4b5c8`) — **not** reversed. Printing shows the *value*, and the CPU has already read the bytes back in the correct order. You only see the reversed little-endian bytes if you deliberately inspect raw memory (walking `(unsigned char*)&p`, or a hex/debugger view).

</details>

**Q78. Is a pointer affected by endianness?**

<details><summary>Show answer</summary>

Yes. A pointer is just a **multi-byte integer** (8 bytes on 64-bit) that holds an address, so it's stored in the machine's endianness — little-endian on x86, meaning its bytes appear reversed in a raw memory dump, exactly like any `int`.

</details>

**Q79. How do you detect at runtime whether a machine is little- or big-endian?**

<details><summary>Show answer</summary>

Store 1 in an int and look at its first byte:
```cpp
int n = 1;
char* c = (char*)&n;
if (*c == 1) puts("little-endian");  // low byte holds the 1
else         puts("big-endian");     // low byte is 0
```
On little-endian the least-significant byte (the `01`) sits at the lowest address, so `*c == 1`.

</details>

**Q80. Which values are immune to endianness?**

<details><summary>Show answer</summary>

**Single-byte** types — `char`, `uint8_t`, `bool` — because one byte has no ordering to reverse. Endianness only concerns multi-byte values (`short`, `int`, `long`, pointers), and even then it's visible only when you look at the raw bytes (hex dump, `char*`, or data sent between machines).

</details>

### 20 — Undefined Behavior & Bounds Checking  (5 Qs)
**Q81. This program prints `4` and exits cleanly. Is it correct?**

```cpp
std::array<int,5> a;
a[10] = 4;
cout << a[10];
```

<details><summary>Show answer</summary>

**No — it is undefined behaviour.** `a` has valid indices 0–4, but you write to index 10. `std::array::operator[]` does **no bounds checking**, so it just computes an out-of-bounds address and writes there. It *happened* not to crash and printed `4`, but that's luck — the same code could crash, corrupt another variable, or behave differently on another compiler/run. 'It printed 4' is not proof of correctness.

</details>

**Q82. Which access is bounds-checked, and what does it do on a bad index?**

<details><summary>Show answer</summary>

`.at(i)` is bounds-checked. On an out-of-range index it **throws `std::out_of_range`** (with a descriptive message via `e.what()`), instead of silently corrupting memory like `[]`. So `a.at(10)` on a size-5 array throws rather than doing UB.
```cpp
a.at(10) = 4;  // throws std::out_of_range
```

</details>

**Q83. Why does C++ leave `operator[]` unchecked by default?**

<details><summary>Show answer</summary>

Because of the principle **'don't pay for what you don't use'** — a bounds check on *every* element access adds a comparison that's costly in tight numeric loops, so `[]` is fast and trusts the programmer. (Java/Python bounds-check *always*: safer, but you pay on every access with no opt-out.) C++ gives you both: fast `[]` when you've verified the index, and checked `.at()` when you want the safety net.

</details>

**Q84. Name three different things undefined behaviour is allowed to do.**

<details><summary>Show answer</summary>

It may: (1) **appear to work** (produce the expected output, as in the `a[10]` example), (2) **crash** (e.g. a segfault), or (3) **silently corrupt** other memory (overwrite a nearby variable, the return address, etc.). Because the behaviour is undefined it can also differ across compilers, optimization levels, and runs — which is what makes UB dangerous.

</details>

**Q85. Which compiler flag would have caught the out-of-bounds write at runtime during testing?**

<details><summary>Show answer</summary>

**`-fsanitize=address`** (AddressSanitizer) — it instruments the program and reports a `stack-buffer-overflow` when the bad access actually runs. Add **`,undefined`** (`-fsanitize=address,undefined`) to also catch other undefined behaviour with UBSan.

</details>

### 21 — std::array vs std::vector  (4 Qs)
**Q86. When should you choose `std::array` rather than `std::vector`?**

<details><summary>Show answer</summary>

Choose **`std::array<T,N>`** when the element count is **fixed and known at compile time** — it lives on the stack, has zero heap overhead, and never resizes. Choose **`std::vector<T>`** instead when the count is **unknown or changes at runtime** — it lives on the heap and grows via `push_back`/`resize`. Rule of thumb: fixed → array, growable → vector.

</details>

**Q87. How does a `std::vector` grow when you keep adding elements?**

<details><summary>Show answer</summary>

You add with **`push_back`** (or `resize`/`insert`); when it runs out of room it allocates a **bigger block on the heap**, moves/copies the existing elements into it, and frees the old block. Its element data always lives on the **heap** (the small `vector` object itself — pointer, size, capacity — may sit on the stack).

</details>

**Q88. What is the difference between a vector's `size()` and its `capacity()`?**

<details><summary>Show answer</summary>

`size()` is the number of elements **currently in use**. `capacity()` is how many elements the currently-allocated block can hold **before it must reallocate**. Capacity is usually ≥ size and grows in chunks (often doubling), so not every `push_back` triggers a reallocation. `std::array` has only a fixed size — no separate capacity.

</details>

**Q89. Do both `array` and `vector` offer a bounds-checked access?**

<details><summary>Show answer</summary>

Yes — both provide `.at(i)` (bounds-checked, throws `std::out_of_range`) and `operator[]` (unchecked, fast). The choice between checked and unchecked access is the same for both containers.

</details>

### 22 — Exceptions & try/catch  (4 Qs)
**Q90. Calling `a.at(10)` on a size-5 array printed 'Aborted (core dumped)'. Whose fault is the crash?**

<details><summary>Show answer</summary>

The **caller's** — for not handling the exception. `.at()` did its job: it detected the out-of-range index and **threw** `std::out_of_range`. Because nothing **caught** it, the exception propagated up to `std::terminate`, which aborts the program. The crash means 'an error was reported and nobody handled it', not that `.at()` is broken. (Contrast `[]`, which wouldn't even tell you.)

</details>

**Q91. Rewrite the call so the program reports the error and keeps running.**

<details><summary>Show answer</summary>

Wrap it in `try`/`catch`:
```cpp
try {
    a.at(10) = 4;
} catch (const std::out_of_range& e) {
    std::cout << "Bad index: " << e.what() << '\n';
}
std::cout << "still running\n";   // reached
```
Now the exception is caught and handled, and execution continues past the `try/catch` instead of aborting.

</details>

**Q92. Should you catch an exception by value or by `const` reference, and why?**

<details><summary>Show answer</summary>

By **`const` reference** (`catch (const std::exception& e)`). Catching **by value** copies the exception object and can **slice** it — if the real exception is a derived type, the copy keeps only the base part, losing information (and its overridden `what()`). A `const&` binds to the actual object with no copy and no slicing.

</details>

**Q93. What does `e.what()` return?**

<details><summary>Show answer</summary>

A C-style string (`const char*`) describing the error — the exception's message. For `std::out_of_range` from `.at()`, it includes details such as the bad index and the container size.

</details>

### 23 — AddressSanitizer & Debugging Tools  (4 Qs)
**Q94. You built with `-fsanitize=address` and compiling produced no error — why hasn't AddressSanitizer reported anything yet?**

<details><summary>Show answer</summary>

Because AddressSanitizer is a **runtime** detector, not a compile-time one. Compiling only *instruments* the code; the error is reported when the **bad access actually executes**. You must **run** the program (`./prog`) and reach the offending line for ASan to print its report. A clean compile — or a run that never hits the bug — shows nothing.

</details>

**Q95. How does AddressSanitizer detect an out-of-bounds access?**

<details><summary>Show answer</summary>

It surrounds each variable/allocation with poisoned **redzones** (guard bytes with no real data) and keeps 'shadow memory' marking which bytes are valid. The instant your program reads or writes into a redzone (or freed memory), ASan detects the poisoned access and reports it — with the file/line, the variable, and byte offsets. They're essentially tripwires around your memory.

</details>

**Q96. Does AddressSanitizer report every error in a run, or stop at the first one?**

<details><summary>Show answer</summary>

By default it **aborts on the first error** (you'll see `==pid==ABORTING`). To make it report the error and keep going, set the environment option **`ASAN_OPTIONS=halt_on_error=0`** before running.

</details>

**Q97. Name two other tools or flags for finding C++ memory / undefined-behaviour bugs.**

<details><summary>Show answer</summary>

**UBSan** (`-fsanitize=undefined`) for undefined behaviour like signed overflow or bad shifts; **valgrind** (memcheck) for leaks and invalid accesses; and **gdb** for interactive debugging / core-dump inspection. ASan + UBSan together (`-fsanitize=address,undefined -g`) catch a large class of bugs during testing.

</details>

## OS Memory & Systems

### 24 — Paging & Virtual Memory  (5 Qs)
**Q98. Why is a process divided into pages in the first place?**

<details><summary>Show answer</summary>

So it **doesn't need one big contiguous block of physical RAM**. Once the process is cut into equal-size **pages**, each page can be placed into **any free frame anywhere** in RAM — no contiguous run required. This eliminates **external fragmentation** (enough total memory free, but scattered in gaps too small to use) and unlocks virtual memory, isolation, and sharing.

</details>

**Q99. What is the difference between a page and a frame?**

<details><summary>Show answer</summary>

A **page** is a fixed-size chunk of the **program's content** (a slice of code/heap/stack) — think of a chapter torn from a book. A **frame** is a fixed-size **slot in physical RAM** — a shelf slot that holds one page. They're the **same size**, and exactly **one page fits in one frame**. 'Page 3 is in frame 47' means page 3's actual bytes are stored in that physical frame.

</details>

**Q100. Does virtual address space itself store any data or hold any RAM?**

<details><summary>Show answer</summary>

No. A virtual address is a **per-process, imaginary label** — it holds nothing itself and consumes no RAM. The real bytes live in physical **frames**; the **page table** translates each virtual address to the frame that actually stores the data. (Two different processes can even print the *same* virtual address mapping to completely different physical memory.)

</details>

**Q101. If a program's pages are scattered all over physical RAM, how does it still behave as if memory were one contiguous block?**

<details><summary>Show answer</summary>

The **page table** maps each contiguous **virtual** page to whatever physical **frame** holds it, and the **MMU** performs that translation on **every** memory access. So the program always sees a clean, ordered, contiguous virtual layout, while the hardware quietly redirects each access to the scattered real location. Non-contiguous in RAM, contiguous to the program.

</details>

**Q102. Beyond avoiding fragmentation, what benefits does paging unlock?**

<details><summary>Show answer</summary>

(1) **Virtual memory** — a process can use more memory than physically exists (unused pages live on disk). (2) **Isolation/protection** — each process has its own page table, so it can't see another process's memory, and pages carry permission bits. (3) **Sharing** — one physical frame (e.g. a shared library like libc) can be mapped into many processes at once.

</details>

### 25 — MMU, TLB & Multi-level Paging  (5 Qs)
**Q103. What does the MMU do on every memory access?**

<details><summary>Show answer</summary>

The **MMU (Memory Management Unit)** is dedicated **hardware in the CPU** that translates a **virtual address into a physical address** on *every* memory access — by walking the page table (or hitting the TLB) — and simultaneously **checks the permission bits** (present? writable? executable?), raising a page fault or protection fault if something is wrong. Software sets up the page tables; the MMU reads them and translates automatically.

</details>

**Q104. A virtual address splits into two parts for translation — what are they, and what does each select?**

<details><summary>Show answer</summary>

**Page number** and **offset**. The **page number** selects *which* page — looked up in the page table to get the physical **frame** number. The **offset** selects *where inside* that page/frame the byte is. Physical address = (frame base) + offset.
```
12290 with 4KB pages -> page 3 (12290/4096), offset 2
page 3 -> frame 47 ; physical = frame47_base + 2
```

</details>

**Q105. Why don't OSes use a single flat page table (on x86-64)?**

<details><summary>Show answer</summary>

Because it would be enormous. With a 48-bit address and 4 KB pages there are 2^36 pages; a flat table of 8-byte entries is 2^36 × 8 = **~512 GB per process** — impossible, and almost all empty since a process uses a tiny slice of its address space. **Multi-level paging** uses a **sparse tree** of small (512-entry) tables and creates only the sub-tables for regions actually in use, shrinking it to a few KB.

</details>

**Q106. How many levels does x86-64 paging use, and how is the address split?**

<details><summary>Show answer</summary>

**Four levels.** The 48-bit virtual address splits into four **9-bit** indexes (one per level, each into a 512-entry table) plus a **12-bit offset** (4 KB pages): `9 + 9 + 9 + 9 + 12 = 48`. The MMU walks Table1→Table2→Table3→Table4 to reach the frame. (Newer CPUs offer a 5-level mode for a larger 57-bit space.)

</details>

**Q107. A multi-level walk costs several memory accesses per translation — what hides that cost?**

<details><summary>Show answer</summary>

The **TLB (Translation Lookaside Buffer)** — a small, fast cache in the MMU that stores recent **page→frame** translations. On a TLB **hit**, the translation is instant and the multi-level walk is skipped. Thanks to locality, most accesses hit the TLB, so the expensive 4-level walk happens only on a miss.

</details>

### 26 — Allocation Methods & Fragmentation  (5 Qs)
**Q108. Where is the wasted space in internal fragmentation versus external fragmentation?**

<details><summary>Show answer</summary>

**External** fragmentation wastes memory in the **gaps between** allocations: enough total memory is free, but it's scattered in pieces too small (or separated by live allocations) to satisfy a large contiguous request. **Internal** fragmentation wastes memory **inside** an allocated block — the unused tail of the last page of a region. The names say it: *between* blocks (external) vs *inside* a block (internal).

</details>

**Q109. Why does paging cause internal fragmentation but eliminate external fragmentation?**

<details><summary>Show answer</summary>

Paging places each page into any free frame, so there are **no unusable gaps between allocations** → external fragmentation is gone. But a region rarely fills a whole number of pages, so the **last page** of each region is usually only partly used — the remainder is wasted **inside** that frame → internal fragmentation (bounded by page size − 1). It trades a large, scattered waste for a small, predictable one.

</details>

**Q110. Why does internal fragmentation only affect the *last* page of a region?**

<details><summary>Show answer</summary>

Because all the **earlier** pages are **completely full** of the region's data — they flow continuously with no gaps. Only when you reach the end do you run out of data mid-page, leaving the tail of the **final** page unused. Every page before it is 100% packed, so there's nothing to waste there.

</details>

**Q111. Is external fragmentation a memory-management method you can choose, like paging?**

<details><summary>Show answer</summary>

No — it's a **problem / side effect**, not a method. The methods are **contiguous allocation**, **paging**, and **segmentation**. Contiguous allocation and segmentation *suffer from* external fragmentation (variable-size, must-be-contiguous placement); **paging is the method that cures it**. You never 'choose external fragmentation' — it happens to you when you use a contiguous scheme.

</details>

**Q112. What does each entry in a segment table store?**

<details><summary>Show answer</summary>

A **base** (the segment's start address in physical memory) and a **limit** (its length). An address is `(segment number, offset)`. The **limit** provides **protection**: if the offset is ≥ the limit, the access is past the segment's end and is rejected — so a program can't read/write outside its segment. Segmentation is good for logical protection/sharing but reintroduces external fragmentation.

</details>

### 27 — Demand Paging, Page Faults & Swapping  (6 Qs)
**Q113. Walk through exactly what happens on a page fault.**

<details><summary>Show answer</summary>

1) The program touches a virtual page whose page-table entry is marked **not present**. 2) The CPU raises a **page fault** — a trap into the OS. 3) The OS finds a **free frame** (evicting a cold page to disk first if needed), 4) **loads the page's bytes from disk** into that frame, 5) **updates the page table** to mark it present and point at the frame, and 6) **restarts the faulting instruction**. The program resumes as if nothing happened — it just felt a small pause.

</details>

**Q114. A page fault can be ~1000× slower than a RAM access — why is demand paging still a net win?**

<details><summary>Show answer</summary>

Because the cost is **paid once per page**, then that page sits in RAM for many fast reuses. Thanks to **locality of reference**, a program hammers a small **working set** of pages, so faults are rare relative to total accesses. Demand paging also avoids loading (and wasting RAM on) the large parts of a program you never touch, and speeds startup. Many faults are also 'minor' (no disk I/O). It only loses when the working set doesn't fit in RAM.

</details>

**Q115. What is thrashing, and what causes it?**

<details><summary>Show answer</summary>

**Thrashing** is when the working set is **larger than available RAM**, so the OS is forced to constantly evict a page and almost immediately fault it back in. The machine spends most of its time doing disk I/O for paging instead of real work, and performance collapses. The fix is more RAM or a smaller working set (fewer concurrent processes).

</details>

**Q116. What is the difference between a minor and a major page fault?**

<details><summary>Show answer</summary>

A **minor** fault is resolved **without disk I/O** — the page is already in RAM (in the page cache, shared by another process, or a fresh zero-filled page); the OS just fixes the mapping. A **major** fault requires **reading the page from disk**, which is the slow, expensive kind. Most faults after warm-up are minor.

</details>

**Q117. How is a page fault different from a segmentation fault?**

<details><summary>Show answer</summary>

A **page fault** is a *normal* event: the address is valid, the page just isn't in RAM yet, so the OS transparently loads it and continues. A **segmentation fault** is an *error*: the program accessed memory it isn't allowed to (unmapped or wrong permission), so the OS refuses and usually kills the process. Same hardware mechanism (a trap), opposite outcomes.

</details>

**Q118. What is swapping, and which capability does it provide?**

<details><summary>Show answer</summary>

**Swapping** is evicting **cold** (rarely used) pages from RAM out to a reserved area on **disk** (the swap/page file) when RAM is full, freeing frames for pages needed now. It's what makes **virtual memory** possible: total memory in use across processes can **exceed physical RAM**, because RAM acts as a fast window over a larger space that overflows to disk.

</details>

## Linux

### 28 — Filesystem & Navigation  (4 Qs)
**Q119. Your program does `open("config.txt")`; it works from one directory but fails with 'file not found' from another. Why?**

<details><summary>Show answer</summary>

`"config.txt"` is a **relative** path — it's resolved against the **process's current working directory**, not the location of the executable. Run the program from a directory that doesn't contain `config.txt` and the open fails. Fixes: use an **absolute** path, compute the path relative to the executable, or `chdir` to the expected directory. Very common bug.

</details>

**Q120. What is the difference between an absolute and a relative path?**

<details><summary>Show answer</summary>

An **absolute** path starts at the root `/` (e.g. `/home/anup/config.txt`) and means the same thing no matter your current directory. A **relative** path (e.g. `config.txt`, `../data/x`) is resolved from the **current working directory**, so its meaning changes with where you run the program. Absolute is the location-independent one.

</details>

**Q121. What do `.` and `..` refer to in a path?**

<details><summary>Show answer</summary>

`.` is the **current** directory; `..` is its **parent** directory. So `./x` is `x` here, and `../x` is `x` one level up. They're used constantly in relative paths and in `cd ..`.

</details>

**Q122. What does `ls -la` show that a plain `ls` does not?**

<details><summary>Show answer</summary>

Two things: **`-l`** gives the **long format** (permissions, owner, group, size, timestamp per entry), and **`-a`** shows **all** entries **including hidden dotfiles** (names starting with `.`, plus the `.` and `..` entries). Plain `ls` lists only the visible names.

</details>

### 29 — Permissions (rwx)  (4 Qs)
**Q123. What numeric permission mode does `-rwxr-xr-x` correspond to?**

<details><summary>Show answer</summary>

**755.** Ignore the leading `-` (it just marks a regular file; `d` would be a directory). Read the three triplets with r=4, w=2, x=1: owner `rwx` = 4+2+1 = **7**, group `r-x` = 4+0+1 = **5**, others `r-x` = **5** → **755**.

</details>

**Q124. You compiled a program but `./prog` says 'Permission denied' — what's the most likely cause?**

<details><summary>Show answer</summary>

The binary is missing its **execute (`x`) bit**, so the kernel won't run it. Fix it with **`chmod +x prog`** (or `chmod 755 prog`). This is the #1 cause of 'Permission denied' for a script or a freshly created binary. (A compiled binary is usually 755; a source `.cpp` is 644 — no `x`, which is correct since you don't execute source.)

</details>

**Q125. When you access a file, how does the kernel decide which of the three rwx triplets to apply?**

<details><summary>Show answer</summary>

The three triplets are for the file's **owner**, its **group**, and **others**. On each access the kernel checks your process's **UID/GID**: if you're the owner it uses the *owner* triplet; else if you're in the file's group, the *group* triplet; else the *others* triplet. Exactly one triplet applies — chosen most-specific-first — and it decides whether your requested r/w/x is allowed.

</details>

**Q126. On a *directory*, what do r, w, and x each mean (they differ from a file)?**

<details><summary>Show answer</summary>

On a directory: **`r`** = list the names inside it; **`w`** = add/remove/rename entries (create or delete files in it); **`x`** = enter/traverse it (cd into it and reach files by name). Notably you need `x` on a directory just to reach files inside it, even if you already know their paths.

</details>

### 30 — chmod  (3 Qs)
**Q127. What is the difference between `chmod 755 f` and `chmod +x f`?**

<details><summary>Show answer</summary>

`chmod 755 f` sets **all three triplets explicitly and absolutely** — owner `rwx`, group `r-x`, others `r-x` — overwriting whatever was there. `chmod +x f` is **relative**: it only **adds** the execute bit (for all three categories) and leaves the read/write bits untouched. Use numeric for an exact mode; symbolic to nudge one bit.

</details>

**Q128. In symbolic `chmod`, how do you give execute permission to ONLY the owner?**

<details><summary>Show answer</summary>

**`chmod u+x file`** — `u` targets the owner (user) and `+x` adds execute, leaving group and others untouched. The target letters are `u`=owner, `g`=group, `o`=others, `a`=all. (`chmod +x file` with no letter behaves like `a+x` — execute for everyone.)

</details>

**Q129. Which permission bit is the usual culprit behind 'Permission denied' when running `./script.sh`?**

<details><summary>Show answer</summary>

The **execute (`x`)** bit. Without it, the shell won't run the file even if it's readable. Fix with `chmod +x script.sh`. (For a script you also need a readable interpreter, but the missing `x` is the classic cause.)

</details>

### 31 — chown & Ownership  (4 Qs)
**Q130. Why can't a normal (non-root) user give their own file to another user with `chown`?**

<details><summary>Show answer</summary>

Changing a file's **owner** requires **root**. If ordinary users could hand files away, they could dodge disk **quotas** (dump big files onto someone else) or plant files as another user — a security hole. So only root can change ownership. A regular user *can* change a file's **group** to one they belong to (`chgrp`), but not its owner.

</details>

**Q131. Give the chown syntax for: owner+group, owner only, group only, and recursive.**

<details><summary>Show answer</summary>

```bash
chown user:group file   # owner AND group
chown user file         # owner only
chown :group file       # group only (or: chgrp group file)
chown -R user:group dir # recursive: dir and everything inside
```

</details>

**Q132. How do ownership and the rwx bits work together to decide access?**

<details><summary>Show answer</summary>

They're checked **together** on every open/read/write/execute. The kernel compares the process's **UID/GID** to the file's **owner and group** to pick which rwx triplet applies (owner, group, or others), then checks whether that triplet grants the requested operation. So 'who owns it' selects *which* permissions, and the rwx bits say *what* those permissions are.

</details>

**Q133. What does `id` show that `whoami` does not?**

<details><summary>Show answer</summary>

`whoami` prints just your **username**. `id` prints your numeric **UID**, primary **GID**, and **all group memberships**. That extra detail is what matters for permissions, because the kernel checks those numeric IDs (not the name) against a file's owner/group to decide which rwx triplet applies to you.

</details>

## C++ Core (continued)

### 32 — Member Initializer List  (6 Qs)
**Q134. What is the difference between initialization (in the list) and assignment (in the body)?**

<details><summary>Show answer</summary>

The list **initializes** a member directly, once, as the object is built. In the body the member already exists (default-constructed / indeterminate), so `a = x;` only **assigns** — for class members that's default-construct + reassign (two steps) vs one.

</details>

**Q135. Which members MUST be initialized in the list (won't compile otherwise)?**

<details><summary>Show answer</summary>

`const` members, **reference** members, member objects whose type has **no default constructor**, and a **base class** with no default constructor.

</details>

**Q136. How do you pass an argument to a base class constructor?**

<details><summary>Show answer</summary>

In the derived class's initializer list: `Derived(int x) : Base(x) {}`. It's the only place you can — omit it and the base's default ctor is called (error if none). Needed even inside a default constructor.

</details>

**Q137. In what order are members initialized?**

<details><summary>Show answer</summary>

In the order they are **declared** in the class, not the order written in the list (bases first, then members). So don't initialize one member from another that's declared after it.

</details>

**Q138. What is a delegating constructor, and its one rule?**

<details><summary>Show answer</summary>

One constructor calls another of the same class through the list (`Entity() : Entity(0) {}`) to reuse setup. Rule: the delegation must be the **only** item in the list.

</details>

**Q139. If C++11 lets you write `int a = 0;` at the declaration, why is the init list still needed?**

<details><summary>Show answer</summary>

A default member initializer is a **fixed** fallback, same for every object, and can't use constructor arguments or initialize a base class. The list is needed for **argument-driven** values and for **base class** initialization.

</details>

### 33 — Ternary Operator  (6 Qs)
**Q140. Is the ternary a statement or an expression, and why does that matter?**

<details><summary>Show answer</summary>

An **expression** — it produces a value. That's why it can be used inline where a value is needed (initializing a variable or a `const`, a `return`, a function argument), which an `if/else` statement can't do.

</details>

**Q141. Why can a ternary initialize a `const` when if/else can't?**

<details><summary>Show answer</summary>

A `const` must get its value at the moment of declaration, in one shot. The ternary is a single expression that yields that value. `if/else` runs *after* the variable exists, forcing declare-then-assign — which `const` forbids.

</details>

**Q142. In `cond ? 1 : 2.5`, what is the result type and why?**

<details><summary>Show answer</summary>

**double**. The two branches must have a common type; `int` and `double` convert to the common type `double`, so `1` becomes `1.0` and the whole expression is `double` — regardless of which branch is chosen.

</details>

**Q143. When do the two branches make a ternary fail to compile?**

<details><summary>Show answer</summary>

When they have **no common type** to convert to — e.g. `cond ? 5 : "hi"` (an `int` and a `const char*`). Same type isn't required; a common/convertible type is.

</details>

**Q144. Why does `cout << c ? "a" : "b";` need parentheses?**

<details><summary>Show answer</summary>

Because `<<` has **higher precedence** than `?:`, so it parses as `(cout << c) ? "a" : "b"` — it prints `c`, then applies `?:` to the stream (broken). `cout << (c ? "a" : "b")` forces the ternary first.

</details>

**Q145. Is the branch that isn't chosen evaluated?**

<details><summary>Show answer</summary>

No — only the chosen branch is evaluated. That's what makes `p ? *p : 0` safe: `*p` runs only when `p` is non-null.

</details>

### 34 — Creating / Instantiating Objects  (6 Qs)
**Q146. What are the two places an object can live, and how does each affect its lifetime?**

<details><summary>Show answer</summary>

The **stack** and the **heap**. A stack object (`Entity e;`) has **automatic** lifetime — destroyed when it leaves scope, with its destructor called for you. A heap object (`new Entity`) has **manual** lifetime — it lives until you `delete` it, so it can outlive the scope (but leaks if you forget).

</details>

**Q147. Why do you access a heap object with `->` but a stack object with `.`?**

<details><summary>Show answer</summary>

`new` gives you a **pointer**, not the object itself, so you must go through the pointer: `p->x`, which is shorthand for `(*p).x` (dereference, then dot). A stack variable *is* the object, so you use `.` directly.

</details>

**Q148. What is a memory leak and what causes it?**

<details><summary>Show answer</summary>

Heap memory that was allocated with `new` but never `delete`d. The program still owns the address but nothing uses it and nothing else can reuse it, so memory is wasted until the program exits.

</details>

**Q149. What is a dangling pointer? Give two ways to create one.**

<details><summary>Show answer</summary>

A pointer holding an address whose object no longer exists — using it is undefined behaviour. Two ways: (1) point at a **stack object** and let it go out of scope; (2) `delete` a heap object but keep using the pointer (**use-after-delete**).

</details>

**Q150. Why set a pointer to `nullptr` after `delete`?**

<details><summary>Show answer</summary>

After `delete` the pointer still holds the freed address (dangling). Setting it to `nullptr` marks it as 'points to nothing' so you can test it, and because `delete nullptr;` is a safe no-op, it also protects against an accidental **double-delete**.

</details>

**Q151. What does `Entity e();` actually declare?**

<details><summary>Show answer</summary>

A **function** named `e` taking no arguments and returning an `Entity` — not an object (the 'most vexing parse'). To make an object use `Entity e;` or `Entity e{};`.

</details>

### 35 — The new Keyword  (6 Qs)
**Q152. What two things does `new` do?**

<details><summary>Show answer</summary>

It (1) **allocates** memory on the heap (via `operator new`, usually `malloc` underneath) and (2) **calls the constructor** on that memory. It returns a typed pointer. (`delete` does the reverse: destructor, then free.)

</details>

**Q153. How does `new` differ from `malloc`? (three ways)**

<details><summary>Show answer</summary>

`new` **calls the constructor** (and `delete` the destructor); `new` returns a **typed pointer** (no cast) while `malloc` returns `void*`; and `new` **throws `std::bad_alloc`** on failure while `malloc` returns `nullptr`.

</details>

**Q154. Why must `new[]` be paired with `delete[]` and not plain `delete`?**

<details><summary>Show answer</summary>

`new[]` stores a **count** of the elements; `delete[]` reads it and runs the destructor for **every** element before freeing. Plain `delete` runs at most one destructor and mismatches the allocation bookkeeping → undefined behaviour.

</details>

**Q155. What is the difference between `delete` and `free`?**

<details><summary>Show answer</summary>

`delete` first **calls the destructor**, then frees the memory (via `operator delete`, usually `free`). `free` only frees the raw memory — no destructor. So `delete` = destructor + free; `free` = free only.

</details>

**Q156. `free`/`delete` are given only `p` — how do they know where the header is and how big the block is?**

<details><summary>Show answer</summary>

The **header offset** is a fixed constant compiled into the allocator, so it computes `p - headerSize` to reach the header from just `p`. The **block size** is stored *inside* that header, so it reads it once the header is found.

</details>

**Q157. What is the difference between `new int;` and `new int();`?**

<details><summary>Show answer</summary>

`new int` allocates the memory but leaves the value **indeterminate** (garbage). `new int()` **value-initializes** it to 0. (For a class with a default constructor, both forms run it — the difference only matters for plain types.)

</details>

### 36 — Implicit Conversion & explicit  (5 Qs)
**Q158. What makes a constructor a 'converting constructor'?**

<details><summary>Show answer</summary>

A constructor callable with a **single argument** (and not marked `explicit`). The compiler can use it to implicitly convert that argument's type into the class — e.g. `Entity(int)` lets `Entity e = 22;` work.

</details>

**Q159. Exactly why does `Entity e = "Anup";` fail?**

<details><summary>Show answer</summary>

Because it would need **two** user-defined conversions: `const char*` -> `std::string` -> `Entity`. The compiler allows **at most one** user-defined conversion in a chain. `Entity e = std::string("Anup");` works because that's only one.

</details>

**Q160. What does the `explicit` keyword do?**

<details><summary>Show answer</summary>

It marks a constructor (or conversion operator) as usable only for **direct/explicit** construction, disabling **implicit** conversion through it. So `Entity e = 22;` becomes an error while `Entity e(22);` still works.

</details>

**Q161. With an `explicit` constructor, which works: `Entity e = 22;` or `Entity e(22);`? Why?**

<details><summary>Show answer</summary>

`Entity e(22);` works — that's **direct initialization**, which `explicit` allows. `Entity e = 22;` is **copy initialization**, which relies on implicit conversion, and that's exactly what `explicit` blocks.

</details>

**Q162. Why is marking single-argument constructors `explicit` often a good idea?**

<details><summary>Show answer</summary>

To stop **accidental/surprising** implicit conversions that hide bugs (e.g. `String s = 65;` silently building a 65-char string). `explicit` forces the caller to state intent; you drop it only when you truly want the implicit conversion.

</details>

### 37 — Operators & Operator Overloading  (5 Qs)
**Q163. What is operator overloading, and why is it called compile-time polymorphism?**

<details><summary>Show answer</summary>

It defines what an operator (`+`, `==`, `<<`...) does for your own type — an operator is just a function with a special name. It's **compile-time** polymorphism because the compiler chooses which `operator` function to call from the **operand types** while compiling (unlike virtual functions, chosen at runtime).

</details>

**Q164. When must you use a free (non-member) operator instead of a member?**

<details><summary>Show answer</summary>

When the **left operand is not your class**. A member operator's left operand is always `this`, so for `cout << e` (left operand is `std::ostream`) or `2 * v` (left operand is `int`) you can't use a member — you write a free function taking both operands as parameters.

</details>

**Q165. Why must `operator<<` be a free function and return `std::ostream&`?**

<details><summary>Show answer</summary>

**Free** because its left operand is the stream (`std::ostream`), which you don't own and can't add members to. It **returns the stream by reference** so `<<` calls **chain**: `cout << a << b` groups as `(cout << a) << b`, and each `<<` must hand back the stream for the next one.

</details>

**Q166. Why does `operator+` return by value but `operator=` returns `*this` by reference?**

<details><summary>Show answer</summary>

`a + b` produces a **brand-new object**, so you return it **by value** (returning a reference to that local would dangle). `a = b` modifies the **existing** left object (which is `*this`), so you `return *this;` **by reference** — no copy, and it lets `a = b = c` chain.

</details>

**Q167. Give two limits on operator overloading.**

<details><summary>Show answer</summary>

Any two of: you can't invent new operators or change their precedence/arity; at least one operand must be a **user-defined type** (`int+int` can't be redefined); and `::`, `.`, `.*`, `?:`, `sizeof` can't be overloaded at all.

</details>

### 38 — The this Keyword  (5 Qs)
**Q168. What is `this`, and where is it available?**

<details><summary>Show answer</summary>

`this` is a pointer holding the **address of the current object** — the object a member function was called on. It exists inside every **non-static** member function (static functions don't have it).

</details>

**Q169. What is the type of `this` in a non-const vs a const member function?**

<details><summary>Show answer</summary>

Non-const method: `Entity* const` — a const pointer to a non-const object (you can modify the object, not reseat the pointer). Const method: `const Entity* const` — you can't modify the object either. The trailing `const` after the parameter list makes it a const member function.

</details>

**Q170. What is the difference between `this` and `*this`?**

<details><summary>Show answer</summary>

`this` is the **pointer** (the object's address); `*this` is the **object** itself (dereferenced). You return `*this` **by reference** (`Entity&`) to hand back the same object for chaining; returning `this` would return the address (`Entity*`).

</details>

**Q171. When do you actually need to write `this->`?**

<details><summary>Show answer</summary>

Only to **disambiguate** a member from a **same-named parameter** (e.g. `this->a = a;`), or in some template code (dependent base-class names). Otherwise you can access members directly and `this->` is optional.

</details>

**Q172. Why does a `static` member function have no `this`?**

<details><summary>Show answer</summary>

Because it isn't tied to any particular object — you call it as `Class::fn()` with no instance. With no object, there's no address to put in `this`, which is also why a static function can only touch static members.

</details>

### 39 — Object Lifetime  (5 Qs)
**Q173. Name the three storage durations and what determines each object's lifetime.**

<details><summary>Show answer</summary>

**Automatic** (stack): local variables, alive until the end of their scope. **Dynamic** (heap): created with `new`, alive until you `delete` it. **Static/global**: `static` locals, globals, static members — alive for the whole program.

</details>

**Q174. Why is returning the address of a local variable a bug?**

<details><summary>Show answer</summary>

The local lives in the function's stack frame, which is reclaimed when the function returns. The returned address then points to memory that's no longer valid — a **dangling** pointer — so using it is undefined behaviour.

</details>

**Q175. Give two correct ways to return data that outlives a function.**

<details><summary>Show answer</summary>

Any two of: **return by value** (the caller gets its own copy); allocate on the **heap** and transfer ownership (return the pointer / a smart pointer); or have the **caller pass in a buffer** (by reference/pointer) that the function fills.

</details>

**Q176. What is RAII, and why is it exception-safe?**

<details><summary>Show answer</summary>

RAII (Resource Acquisition Is Initialization): acquire a resource in the constructor and release it in the destructor. It's exception-safe because when an exception propagates, the **stack unwinds** and the destructors of all fully-constructed automatic objects run — so the resource is always released, even on an error path.

</details>

**Q177. Why does a `static` local variable keep its value between calls?**

<details><summary>Show answer</summary>

Because it has **static storage duration** (program lifetime) rather than automatic: it's created and initialized **once**, on first reach, and persists across calls. Only its *scope* is local; its *lifetime* is the whole program.

</details>

### 40 — Smart Pointers  (6 Qs)
**Q178. What problem do smart pointers solve, and which mechanism makes them work?**

<details><summary>Show answer</summary>

They remove manual `new`/`delete` — no leaks, double-frees, or dangling. They work via **RAII**: the smart pointer's destructor `delete`s the owned object automatically when the smart pointer goes out of scope.

</details>

**Q179. What is the difference between `unique_ptr` and `shared_ptr`, and how does `shared_ptr` know when to delete?**

<details><summary>Show answer</summary>

`unique_ptr` has a **single** owner (can't be copied, only moved). `shared_ptr` allows **many** owners via a **reference count**: copying bumps it up, destruction bumps it down, and the object is deleted when the count reaches **0**.

</details>

**Q180. What is `weak_ptr` for, and why doesn't it affect the reference count?**

<details><summary>Show answer</summary>

It's a **non-owning** observer of a `shared_ptr`, used to **break circular references** (a cycle of shared_ptrs never reaches count 0 -> leak) and to safely check/access the object via `.lock()`. It doesn't count because it doesn't own the object — it only watches it.

</details>

**Q181. Why prefer `make_unique`/`make_shared` over raw `new`?**

<details><summary>Show answer</summary>

They're **exception-safe** and keep raw `new` out of your code. `make_shared` also does a **single allocation** for the object and its control block (vs two with `shared_ptr<T>(new T)`).

</details>

**Q182. What's the difference between `release()`, `reset()`, and `std::move` on a `unique_ptr`?**

<details><summary>Show answer</summary>

`release()` gives up ownership **without deleting** and returns the raw pointer (you must delete it). `reset()` **deletes** the owned object now. `std::move` **transfers** ownership to another `unique_ptr` (which will delete it); the source becomes null.

</details>

**Q183. When is a raw pointer the right choice over a smart pointer?**

<details><summary>Show answer</summary>

For **non-owning** references — 'borrowing' an object whose lifetime is managed elsewhere. You use it to read/call but never `delete` through it, and it's valid only while the real owner keeps the object alive (a reference is often even better when it can't be null).

</details>

### 41 — Copying & Copy Constructors  (5 Qs)
**Q184. Name two situations where the copy constructor is called.**

<details><summary>Show answer</summary>

Any two of: initializing a new object from another (`T b = a;` or `T b(a);`), passing an object to a function **by value**, or returning an object **by value** (though that copy is often elided).

</details>

**Q185. What does the default copy constructor do, and why is that dangerous for a class with a pointer member?**

<details><summary>Show answer</summary>

It does a **shallow, member-wise copy** — copying each member's value. For a pointer that copies the **address**, so both objects point at the **same** heap buffer. Then both destructors `delete` it -> **double-free**, and changing one affects the other.

</details>

**Q186. What is a deep copy and how does it fix the double-free?**

<details><summary>Show answer</summary>

A deep copy allocates a **separate** buffer for the new object and copies the **contents** into it, so each object owns independent memory. Now each destructor deletes its own buffer — no shared pointer, no double-free.

</details>

**Q187. What is the Rule of Three (and Five)?**

<details><summary>Show answer</summary>

Rule of Three: if a class needs a custom **destructor**, it almost certainly also needs a custom **copy constructor** and **copy assignment operator** (all manage the same resource). Rule of Five (C++11) adds a **move constructor** and **move assignment** for efficiency.

</details>

**Q188. What is the difference between the copy constructor and copy assignment?**

<details><summary>Show answer</summary>

The copy **constructor** builds a **brand-new** object from an existing one (`T b = a;`). Copy **assignment** (`operator=`) is used when **both objects already exist** (`b = a;`): it must free its own old resource, deep-copy, guard against self-assignment, and `return *this`.

</details>

### 42 — The Arrow Operator  (4 Qs)
**Q189. What is `e->a` equivalent to, written the long way?**

<details><summary>Show answer</summary>

`(*e).a` — dereference the pointer `e` with `*`, then use the dot to access the member. `->` just combines those two steps.

</details>

**Q190. For a raw pointer, is `->` built-in or overloaded — and when does overloading come in?**

<details><summary>Show answer</summary>

For a **raw pointer** it's **built-in**. Overloading `operator->` comes in for your **own classes** — smart pointers (`unique_ptr`/`shared_ptr`), iterators, and custom wrapper types define it so they can be used like pointers.

</details>

**Q191. What does an overloaded `operator->` return, and what does the compiler do with it?**

<details><summary>Show answer</summary>

It returns a **pointer**. The compiler then applies the real `->` to that returned pointer to reach the member — so `w->print()` becomes `w.operator->()->print()`. (If it returned another wrapper, `->` keeps chaining until it hits a raw pointer.)

</details>

**Q192. Why can you use `->` on a smart pointer even though it's an object, not a raw pointer?**

<details><summary>Show answer</summary>

Because the smart pointer **overloads `operator->`** (and `operator*`). So `p->method()` calls `p.operator->()` to get the raw pointer, then applies `->` to that — letting an object behave like a pointer.

</details>
