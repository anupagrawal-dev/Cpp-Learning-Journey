# 41 — Copying & Copy Constructors

*Category: C++ Core*

> Deep-copy a class that owns a resource, or two objects share it and double-free.

## Must-remember points

- Copy constructor `T(const T& other)` runs when a **new** object is built from an existing one: `T b = a;`, `T b(a);`, pass-by-value, return-by-value.
- The compiler's default copy ctor does a **shallow** (member-wise) copy — for a pointer member it copies the **address**, so both objects end up sharing one buffer.
- Shared buffer -> both destructors `delete` it -> **double-free** (and editing one secretly edits the other). A **deep copy** (allocate your own buffer + copy the contents) fixes it.
- **Rule of Three**: if you need a custom destructor, you also need a custom **copy constructor** and **copy assignment** (C++11 adds move ctor + move assignment = **Rule of Five**).
- Copy **constructor** builds a new object from an existing one; copy **assignment** (`operator=`) is for two objects that already exist (free the old buffer, deep-copy, self-assign guard, `return *this`).
- Pass by `const&` to avoid triggering a copy; `= default` (ask for the compiler's version) / `= delete` (forbid copying, like `unique_ptr`).

## Deep-copy String (the corrected version)

```cpp
#include <cstring>

class String {
    char*  m_str;
    size_t m_size;              // logical length (strlen), NOT counting the null
public:
    String(const char* s) {
        m_size = strlen(s);
        m_str  = new char[m_size + 1];   // +1 for the null terminator
        strcpy(m_str, s);
    }
    String(const String& o) : m_size(o.m_size) {   // deep copy: own buffer
        m_str = new char[m_size + 1];
        strcpy(m_str, o.m_str);
    }
    ~String() { delete[] m_str; }        // Rule of Three: dtor + copy ctor (+ copy assign)
};
```

## ⚠ Easily confused

- **shallow vs deep copy** — Shallow (default): copies the pointer -> two objects share one buffer -> double-free. Deep (custom): allocate your own buffer + copy the contents.
- **copy constructor vs copy assignment** — Copy ctor: `T b = a;` builds a NEW object. Copy assignment `b = a;`: both already exist — free old, deep-copy, self-assign guard, return *this.
- **Rule of Three vs Rule of Five** — Three: destructor + copy ctor + copy assignment (manage a resource). Five adds move ctor + move assignment (C++11, for efficiency).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 41).
