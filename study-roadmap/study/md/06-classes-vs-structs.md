# 06 — Classes vs Structs

*Category: C++ Core*

> Only two real differences; the rest is convention.

## Must-remember points

- Only **two** real language differences: (1) default access — `struct` public, `class` private; (2) default inheritance — `struct` public, `class` private.
- Everything else is identical (both can have ctors, methods, virtuals, inheritance, templates).
- `template<class T>`/`template<typename T>` allowed; `template<struct T>` is not.
- Convention: struct = passive data bundles; class = encapsulated types with behavior/invariants.

## ⚠ Easily confused

- **class default vs struct default** — Members are `private` by default in a `class`, `public` by default in a `struct` (same for default inheritance mode).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 06).