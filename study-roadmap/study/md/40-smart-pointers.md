# 40 — Smart Pointers

*Category: C++ Core*

> RAII wrappers that own a heap object and delete it automatically.

## Must-remember points

- Smart pointers (in `<memory>`) are **RAII wrappers** around a raw pointer: they own the heap object and auto-`delete` it when they go out of scope — no manual delete, leaks, or dangling.
- **`unique_ptr`** = **sole** owner; can't be copied, only **moved** (`std::move`); near-zero overhead. Your default. Create with `make_unique`.
- **`shared_ptr`** = **shared** ownership via a **reference count**; the object is deleted when the count hits 0 (`use_count()`). Create with `make_shared` (one allocation). Has a control-block overhead.
- **`weak_ptr`** = **non-owning** observer of a `shared_ptr`; does NOT change the count. Used to **break circular references** and to check/access via `.lock()` (or `.expired()`). (See `study/html/shared-ptr-cycle.html`.)
- Prefer `make_unique`/`make_shared` over raw `new` (exception-safe, no raw `new`). Smart pointers overload `*` and `->`, so you use them like raw pointers.
- Members: `.get()` (raw pointer — don't delete), `.reset()` (delete now), `unique_ptr::release()` (give up ownership WITHOUT deleting — you must delete). Use raw pointers/references only for non-owning **borrowing**.

## Creating, moving, sharing, observing

```cpp
#include <memory>

auto u = std::make_unique<Entity>();   // sole owner
auto v = std::move(u);                 // ownership moved; u is now nullptr

auto s  = std::make_shared<Entity>();  // use_count() == 1
auto s2 = s;                           // use_count() == 2 (shared)
std::weak_ptr<Entity> w = s;           // observes, does NOT bump the count
if (auto sp = w.lock()) { /* alive -> use sp */ }

v->method();   // smart pointers use -> and * like raw pointers
```

## ⚠ Easily confused

- **unique_ptr vs shared_ptr** — unique = one owner, move-only, no overhead. shared = many owners, ref-counted, deleted at count 0 (has a control block).
- **weak_ptr vs shared_ptr** — shared owns and counts. weak observes without counting — breaks cycles; use `.lock()` to access safely.
- **release() vs reset() vs move** — release() = give up ownership, NO delete (you must delete). reset() = delete now. move = transfer to another smart pointer.
- **owning vs non-owning** — Smart pointers express ownership. Raw pointers/references are for borrowing — never delete through them.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 40).
