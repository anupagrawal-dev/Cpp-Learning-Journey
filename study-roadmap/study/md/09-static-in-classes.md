# 09 — Static (for Classes & Structs)

*Category: C++ Core*

> One shared copy for all objects; static methods have no `this`.

## Must-remember points

- Static **member variable** = **one shared copy for all objects**, lives in static storage → does NOT add to object `sizeof`. Classic use: instance counter.
- A non-inline static data member must be **defined once outside the class** (`int Entity::count = 0;`) or → 'undefined reference'. C++17 `inline static` avoids the separate definition.
- Static **member function** has **no `this`** → callable as `Class::fn()` without an object, and can only access static members.

## ⚠ Easily confused

- **static member vs instance member** — A static member is shared by all objects (one copy); an instance member exists per object.
- **static method vs normal method** — A static method has no `this`, so it can't touch per-object data — only static members. A normal method operates on a specific object.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 09).