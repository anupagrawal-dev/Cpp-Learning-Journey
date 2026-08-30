# 05 — Classes & Encapsulation

*Category: C++ Core*

> Private data + public methods = one validated gate for every change.

## Must-remember points

- Private data + public methods = every change forced through a **single gate** that validates it → the object can never reach an invalid state (invariant safety).
- `private` isn't about security/attackers — it's about **controlled change** + freedom to change internals later without breaking users.
- The public method can enforce any rule before writing: no overdraft, clamp ranges, format checks, etc.

## Invariant

A rule that must always hold (e.g. balance >= 0). Private data + method-only changes guarantee the rule is checked on every change, so the object is never left inconsistent.

## ⚠ Easily confused

- **private vs security** — `private` is compile-time access control for safe design, NOT runtime protection — nothing stops memory being read; the compiler just refuses direct access from other code.
- **encapsulation vs abstraction** — Encapsulation = hide data behind a gate. Abstraction = expose a simple interface, hide the complexity.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 05).