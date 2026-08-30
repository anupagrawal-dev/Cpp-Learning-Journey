# 14 — Virtual Functions

*Category: C++ Core*

> Dynamic dispatch via vtable/vptr; use override and final.

## Must-remember points

- Without `virtual`, `basePtr->fn()` uses **static dispatch** → picks by **pointer type** (base version). `virtual` → **dynamic dispatch** → picks by **actual object type** at runtime.
- **vtable** = per-class array of function pointers (one slot per virtual fn); overridden slots point to derived versions. **vptr** = hidden per-object pointer to its class's vtable.
- Only **virtual** functions are in the vtable; a class with zero virtuals has no vtable/vptr (no size cost).
- Cost: vptr (~8 bytes/object) + one indirection + usually no inlining.
- Use `override` (compiler verifies you match a base virtual) and `final` (stop further overriding).

## How a virtual call works

Each polymorphic object stores a hidden `vptr` to its class's vtable. `p->speak()` looks up the fixed slot for `speak` in that vtable and calls whatever is there — the derived override if the real object is derived.

## ⚠ Easily confused

- **static vs dynamic dispatch** — Static = chosen at compile time by the pointer/reference TYPE. Dynamic (virtual) = chosen at runtime by the ACTUAL object type.
- **vtable vs vptr** — vtable = one per class (array of function pointers). vptr = one per object (points to its class's vtable).
- **override vs overload** — `override` = redefine a base virtual with the same signature (runtime dispatch). Overload = same name, different parameters (compile-time choice).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 14).