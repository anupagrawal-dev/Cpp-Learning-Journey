# 42 — The Arrow Operator

*Category: C++ Core*

> ptr->member is shorthand for (*ptr).member — and you can overload it.

## Must-remember points

- `ptr->member` is shorthand for `(*ptr).member` — **dereference** the pointer, then apply the dot.
- `.` is used on an **object** (or reference); `->` on a **pointer** (raw or smart).
- For a **raw pointer**, `->` is **built-in**. For your own class you can **overload `operator->`** — that's how smart pointers and iterators work.
- An overloaded `operator->` returns a **pointer**; the compiler then applies the real `->` to it (and keeps chaining until it reaches a raw pointer).
- That's why `unique_ptr`/`shared_ptr` let you write `p->method()` even though `p` is an object, not a raw pointer.
- (Curiosity: `->` through a null-cast pointer is the trick behind `offsetof` for a member's byte offset — don't use it in real code.)

## Raw pointer, and a custom operator->

```cpp
struct Entity {
    int a;
    void print() const { std::cout << a; }
};

// raw pointer
Entity* e = new Entity{5};
(*e).a = 10;    // the long way
e->a   = 10;    // shorthand — identical
e->print();
delete e;

// custom operator-> (a mini smart pointer)
class Wrapper {
    Entity* ptr;
public:
    Wrapper(Entity* p) : ptr(p) {}
    Entity* operator->() { return ptr; }   // overloaded arrow returns a pointer
};
Wrapper w(new Entity{5});
w->print();     // w.operator->()->print()
```

## ⚠ Easily confused

- **. vs ->** — `.` on an object/reference. `->` on a pointer (raw or smart); `p->m` == `(*p).m`.
- **built-in -> vs overloaded ->** — Raw pointer: `->` is built-in. Custom class (smart pointer / iterator): you overload `operator->`, which returns a pointer.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 42).
