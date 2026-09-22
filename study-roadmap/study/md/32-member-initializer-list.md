# 32 — Member Initializer List

*Category: C++ Core*

> Initialize class members directly, once — and the only way to reach a base ctor.

## Must-remember points

- Written after the constructor's `:` and before `{}`; initializes members **directly, once** (vs default-then-assign in the body).
- Mandatory for `const` members, reference members, and members whose type has no default constructor.
- The only way to pass arguments to a **base class** constructor — even inside a default constructor.
- Members initialize in **declaration order**, NOT the order written in the list.
- Delegating constructor (C++11): one ctor calls another; it must be the **only** item in the list.
- Default member initializer (C++11, `int a = 0;`) is a fallback; the list **takes precedence** over it (default simply not used, not overridden). Body can assign later, but never to const/reference members.

## One example that shows every point

```cpp
class Base {
public:
    Base(int x) {}                 // no default ctor -> base MUST be in the list
};

class Entity : public Base {
    int a = 0;                     // default member initializer (fallback)
    const int id;                  // const     -> must use the list
    int& ref;                      // reference -> must use the list
public:
    // members init in DECLARATION order (a, id, ref), not list order
    Entity(int x, int& r)
        : Base(x), a(x), id(x), ref(r)   // base first, then members, all once
    {
        a = 5;                     // body can ASSIGN a (never id/ref)
    }
    Entity(int& r) : Entity(1, r) {}     // delegating ctor: only item in the list
};
```

## ⚠ Easily confused

- **initialize (list) vs assign (body)** — List initializes the member directly, once. Body assigns after it already exists (default-then-overwrite for class types).
- **declaration order vs list order** — Members init in the order they are DECLARED, not the order written in the list.
- **default member initializer vs MIL** — Default init = fixed fallback. When a member is also in the list, the list takes precedence — the default isn't used (not overridden or reassigned). MIL is also the only way to init a base class.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 32).
