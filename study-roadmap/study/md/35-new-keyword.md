# 35 — The new Keyword

*Category: C++ Core*

> new = allocate on the heap + run the constructor; delete = destructor + free.

## Must-remember points

- `new` is an **operator** that does two things: allocates heap memory (via `operator new`, usually `malloc`) **and calls the constructor**. Returns a **typed pointer**. `delete` = destructor + free.
- Sizes: `new int` (4B, garbage), `new int()` (4B, zero-init), `new int[n]` (n can be a **runtime** value — dynamic array).
- Pairing (mismatch = UB): `new`↔`delete`, `new[]`↔`delete[]`, `malloc`↔`free`. Never cross them.
- `new` vs `malloc`: new calls ctor/dtor, returns a **typed** pointer (no cast), and **throws `std::bad_alloc`** on failure; malloc = raw bytes, `void*`, returns `nullptr`, no ctor.
- Heap layout: a **fixed-size header** sits *before* `p` (stores the block size); `free`/`delete` do `p - headerSize` (offset is a compile-time constant) to find it. `new[]` also stores a **count cookie** so `delete[]` runs every destructor. (See `study/html/heap-layout-new-malloc.html`.)
- Modern C++: prefer smart pointers (`make_unique`/`make_shared`) over raw `new`/`delete`.

## Syntax and matching delete

```cpp
int*    a   = new int;       // 4 bytes, uninitialized (garbage)
int*    b   = new int();     // 4 bytes, zero-initialized
int*    arr = new int[n];     // runtime-sized array (n from a variable)
Entity* e   = new Entity();   // allocate + run constructor

delete a;        // matches new
delete b;
delete[] arr;    // matches new[]  (runs each destructor)
delete e;        // destructor + free
```

## ⚠ Easily confused

- **new vs malloc** — new calls the ctor + returns a typed pointer + throws bad_alloc on failure. malloc = raw bytes only, void*, returns nullptr, no ctor.
- **delete vs free** — delete = destructor THEN free. free = free only (no destructor).
- **delete vs delete[]** — delete = one object. delete[] reads the stored element count and runs the destructor for every element.
- **header offset vs block size** — Header offset = fixed constant known by the allocator (so `p - headerSize` works). Block size = variable, stored in the header and read at free time.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 35).
