# 38 — The this Keyword

*Category: C++ Core*

> A pointer to the current object, available inside non-static member functions.

## Must-remember points

- `this` is a pointer available in every **non-static** member function, holding the **address of the object** the function was called on.
- Type: non-const method -> `Entity* const` (can change the object, can't reseat the pointer); const method -> `const Entity* const` (can't change the object either).
- `this` = the pointer (address); `*this` = the object. Use `this->m` or `(*this).m`; return `*this` **by reference** (`Entity&`) for chaining — returning it by value copies.
- Main uses: disambiguate a member from a same-named parameter (`this->a = a;`), return `*this` for chaining, and self-comparison (`this == &other`).
- `this->` is **optional** for member access — needed only to disambiguate a same-named parameter (or dependent names in templates).
- **Static** member functions have no `this` (not tied to an object). The compiler passes `this` as a hidden first argument to each non-static call.

## The three main uses of this

```cpp
class Entity {
    int a;
public:
    Entity(int a) { this->a = a; }              // (a) disambiguate member vs parameter

    Entity& setA(int a) { this->a = a; return *this; }   // (b) chain: e.setA(1).setA(2);

    Entity& operator=(const Entity& rhs) {
        if (this == &rhs) return *this;         // (c) self-assignment guard
        a = rhs.a;
        return *this;
    }

    int getA() const { return a; }              // const member: this is const Entity* const
};
```

## ⚠ Easily confused

- **this vs *this** — `this` = the pointer (address of the object). `*this` = the object itself. Return `*this` by reference to chain.
- **non-const vs const member this** — non-const method: `Entity* const` (can change the object). const method: `const Entity* const` (can't change it).
- **this-> optional vs required** — Member access usually needs no `this->`. Required only to disambiguate a same-named parameter (or dependent names in templates).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 38).
