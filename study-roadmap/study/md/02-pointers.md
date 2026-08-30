# 02 — Pointers

*Category: C++ Core*

> A variable that holds a memory address.

## Must-remember points

- A pointer holds an **address**. `*` dereferences (read/write the pointed-to value); `&` takes an address.
- The pointer variable itself lives on the **stack**; what it points to may be stack or heap.
- A pointer can be **reseated** (change which address it holds) and can be **null**.

## The two operators

`&x` = 'address of x'. `*p` = 'the value at the address p holds'. Inverses: `*(&x)` is `x`.
```cpp
int x=42; int* p=&x;
*p = 99;   // writes through p -> x is 99
```

## ⚠ Easily confused

- *** vs &** — In a declaration `int* p`, `*` means 'pointer'. In an expression, `*p` dereferences and `&x` takes an address.
- **p vs &p** — `p` = the address it points to (e.g. a heap block). `&p` = where the pointer itself lives (on the stack).
- **null vs dangling** — A **null** pointer points to nothing (0). A **dangling** pointer points to freed/out-of-scope memory — using it is UB.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 02).