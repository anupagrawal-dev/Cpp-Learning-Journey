# 13 — Inheritance

*Category: C++ Core*

> is-a reuse; base subobject first; watch object slicing.

## Must-remember points

- Derived class takes on base members; **code reuse** + models **is-a** (Audi is-a Car). Contrast **has-a** = composition.
- A derived object contains a base subobject (**base part laid out first**); construction base→derived, destruction derived→base.
- Modes: `public` (true is-a), `protected`, `private` (default for `class`).
- `protected` member = accessible to the class's own methods AND derived classes, not outside.
- **Object slicing**: assigning derived → base **by value** copies only the base part → use base pointers/references for polymorphism.

## ⚠ Easily confused

- **is-a vs has-a** — is-a = inheritance (Car is-a Vehicle). has-a = composition (Car has-an Engine as a member). Prefer composition unless it's truly is-a.
- **protected vs private** — `private` = only this class. `protected` = this class and its derived classes ('family').
- **slicing vs polymorphism** — Copy a derived into a base BY VALUE → derived part sliced off. Use a base POINTER/REFERENCE to keep the full object and get polymorphism.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 13).