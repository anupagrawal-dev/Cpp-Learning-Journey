# 12 — Destructors & RAII

*Category: C++ Core*

> Automatic cleanup; virtual for polymorphic bases; Rule of 3/5.

## Must-remember points

- `~ClassName()`, no params/return, exactly one. Runs at end of scope (stack) or on `delete` (heap). Members destroyed in **reverse** order; derived dtor before base.
- **RAII**: tie a resource's lifetime to an object's lifetime → cleanup is automatic and exception-safe.
- **Virtual destructor** required on any polymorphic base: `delete` a derived object via a base pointer with a non-virtual dtor = **UB / leak**.
- **Rule of 3/5**: custom dtor ⇒ likely need custom copy ctor + copy assignment (+ move ops in C++11), else shallow copy → double-free.

## Why RAII is the C++ way

Wrap a resource in an object whose destructor releases it. On scope exit — even via an exception — cleanup runs automatically. `std::unique_ptr`, `std::lock_guard`, `std::fstream` all use this.

## ⚠ Easily confused

- **virtual vs non-virtual destructor** — Delete a derived via base pointer: virtual dtor → full cleanup; non-virtual → only the base part destroyed = UB/leak.
- **shallow vs deep copy** — Shallow copy duplicates the pointer (two owners → double-free). Deep copy duplicates the pointed-to data. Rule of 3/5 handles this.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 12).