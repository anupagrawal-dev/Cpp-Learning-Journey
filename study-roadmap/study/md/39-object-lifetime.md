# 39 — Object Lifetime

*Category: C++ Core*

> Automatic, dynamic, or static — how long an object lives, and RAII.

## Must-remember points

- Three storage durations: **automatic** (stack — lives to the end of its `{}` scope, dtor runs automatically), **dynamic** (heap — from `new` until `delete`, else leak), **static/global** (whole program).
- 'Lifetime = scope' applies only to **automatic** objects; within a scope they're destroyed in **reverse** order of creation.
- Returning `&x` / a reference to a local = **dangling** (its stack frame is gone). Fixes: return by value, heap + transfer ownership, or a caller-supplied buffer.
- **RAII**: acquire a resource in the constructor, release it in the destructor -> cleanup is automatic and **exception-safe** (destructors run during stack unwinding). Basis of smart pointers, `lock_guard`, `fstream`.
- C++ gives **deterministic** cleanup — objects die at predictable scope-exit points (unlike garbage-collected languages).
- A temporary lives to the end of the full expression (`;`); a temporary bound to a `const` reference has its lifetime **extended** to the reference.

## Dangling vs valid, RAII, and a static local

```cpp
int* bad()  { int x = 5; return &x; }   // dangling: x dies at }
int  good() { int x = 5; return x;  }   // fine: value copied out

void demo() {
    std::lock_guard<std::mutex> lock(m); // RAII: lock acquired here
    // ... even if the code below throws ...
}                                        // dtor runs at scope exit -> lock released

int next() { static int n = 0; return ++n; }  // 1, 2, 3... kept across calls
```

## ⚠ Easily confused

- **automatic vs dynamic vs static lifetime** — Automatic (stack): to the end of scope. Dynamic (heap): until you `delete`. Static/global: the whole program.
- **dangling vs valid return** — Return `&local` = dangling (frame gone). Return by value, or heap + ownership, or a caller-supplied buffer = valid.
- **RAII vs manual cleanup** — RAII: the destructor releases automatically at scope exit (even on exceptions). Manual: you must remember to free/close/unlock — easy to forget.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 39).
