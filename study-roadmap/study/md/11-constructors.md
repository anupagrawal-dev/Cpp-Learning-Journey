# 11 — Constructors

*Category: C++ Core*

> Special member that sets up a valid object; watch the free default and init lists.

## Must-remember points

- Special member, **same name as class, no return type**, runs automatically on creation; job = valid initial state / acquire resources / enforce invariants.
- Compiler supplies a free **default (no-arg) ctor ONLY if you write zero ctors**. Write any ctor → free default is gone unless you add `Entity() = default;`.
- **Member initializer list** (`: m_X(0)`) inits before the body; **required** for `const` members, references, and member objects with no default ctor.
- **Most vexing parse**: `Entity e;` = object, but `Entity e();` = a function declaration.

## ⚠ Easily confused

- **init list vs assignment in body** — The init list constructs members directly (once). Assigning in the body default-constructs first, then reassigns — wasteful, and impossible for const/reference members.
- **Entity e; vs Entity e();** — `Entity e;` creates an object. `Entity e();` DECLARES a function returning Entity (the 'most vexing parse'). Use `{}` to be safe.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 11).