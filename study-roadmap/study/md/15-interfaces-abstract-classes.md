# 15 — Interfaces / Abstract Classes

*Category: C++ Core*

> Pure virtuals make a class abstract; all-pure = an interface.

## Must-remember points

- A class with **≥1 pure virtual** (`virtual void f() = 0;`) is **abstract** → cannot be instantiated. All functions pure + no data = an **interface** (convention).
- You CAN use base pointers/refs to an abstract class — that's the point: `Base* p = new Derived();` works if Derived overrides every pure virtual.
- An abstract base can still provide implemented (normal virtual) methods → shared behavior; pure virtuals force each derived to supply its own.
- An interface needs a **virtual destructor**.

## ⚠ Easily confused

- **abstract class vs interface** — Abstract = has ≥1 pure virtual (may still have data/implemented methods). Interface = ALL pure virtual, no data (a pure contract) — convention, not a keyword.
- **pure virtual vs virtual** — `= 0` (pure) forces derived classes to implement it and makes the class abstract. A plain `virtual` has a body and can be overridden optionally.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 15).