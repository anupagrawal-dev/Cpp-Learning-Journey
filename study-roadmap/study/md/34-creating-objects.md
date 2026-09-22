# 34 — Creating / Instantiating Objects

*Category: C++ Core*

> An object lives on the stack or the heap — and that choice sets its lifetime.

## Must-remember points

- An object lives on the **stack** or the **heap**; that choice decides its lifetime.
- Stack: `Entity e;` — **automatic** lifetime (destroyed at end of scope, dtor runs), fast, small; access with `.`.
- Heap: `Entity* e = new Entity;` — `new` returns a **pointer**; the object lives until you `delete` it (else **memory leak**); access with `->`.
- Use the heap when the object must **outlive its scope**, is too big for the stack, is sized at runtime, or needs polymorphism (`Base* b = new Derived;`).
- Traps: **dangling** pointer (points to a destroyed/freed object), **leak** (never deleted), **double-delete**. Set the pointer to `nullptr` after delete (`delete nullptr;` is safe).
- `Entity e();` is a function declaration (most vexing parse) — use `Entity e;` or `Entity e{};`.

## One example: stack, heap, and a dangling pointer

```cpp
class Entity { public: int x; Entity(){} };

void f() {
    Entity a;                 // STACK: auto lifetime, access with .
    a.x = 1;

    Entity* p = new Entity;   // HEAP: pointer on stack, object on heap
    p->x = 2;                 // access with ->  (same as (*p).x)
    delete p;                 // manual free — or it leaks
    p = nullptr;              // habit: avoids dangling / double-delete

    Entity* bad;
    {
        Entity local;         // stack object
        bad = &local;         // bad points to local
    }                         // local destroyed here -> bad now DANGLES (UB to use)
}                             // a destroyed here automatically
```

## ⚠ Easily confused

- **stack object vs heap object** — Stack: `Entity e;` auto lifetime, `.` access. Heap: `new Entity` returns a pointer, manual `delete`, `->` access.
- **. vs ->** — `.` on an actual object; `->` on a pointer to an object (`p->x` == `(*p).x`).
- **dangling vs leak** — Dangling = pointer to memory already freed / out of scope (UB to use). Leak = heap memory never deleted (lost until the program ends).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 34).
