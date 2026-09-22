# 36 — Implicit Conversion & explicit

*Category: C++ Core*

> A single-arg constructor lets the compiler auto-convert; explicit turns that off.

## Must-remember points

- A **single-argument constructor** is a *converting constructor*: the compiler can use it to auto-convert that arg type into your class (`Entity e = 22;`).
- Implicit conversion also fires in **function arguments** and **return values**, not just assignments.
- Rule: **at most one** user-defined conversion in a chain — so `Entity e = 22;` works (one), but `Entity e = "Anup";` fails (`char*` -> `string` -> `Entity` = two).
- `explicit` on a constructor **disables** implicit conversion through it; you must construct directly (`Entity e(22);`) or cast (`(Entity)22`).
- Why: implicit conversions can silently hide bugs. Guideline: mark single-arg constructors `explicit` unless you deliberately want the conversion.
- Direct init `Entity e(22);` always works; copy init `Entity e = 22;` is what `explicit` blocks. `explicit` also applies to conversion operators (C++11).

## Where it fires, and where explicit stops it

```cpp
class Entity {
public:
    Entity(int age) {}              // converting constructor (single arg)
    // explicit Entity(int age) {}  // add 'explicit' to block the (X) lines
    Entity(const std::string& n) {}
};

void print(Entity e) {}

Entity a(22);            // direct init — always OK
Entity b = 22;           // (X) implicit conversion  int -> Entity
print(22);               // (X) implicit conversion in a function argument
Entity c = "Anup";       // ERROR: needs TWO conversions (char* -> string -> Entity)
Entity d = std::string("Anup");  // OK: one conversion (string -> Entity)
```

## ⚠ Easily confused

- **implicit vs explicit conversion** — Implicit = compiler auto-converts via a single-arg ctor (`Entity e = 22;`). explicit = you must convert on purpose (`Entity e(22);` or a cast).
- **direct init vs copy init** — `Entity e(22);` = direct (works even with explicit). `Entity e = 22;` = copy init (blocked by explicit).
- **one vs two user conversions** — The compiler allows only ONE user-defined conversion. int->Entity = one (ok). char*->string->Entity = two (error).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 36).
