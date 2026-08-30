# 10 — Enums

*Category: C++ Core*

> Named integer constants; prefer `enum class`.

## Must-remember points

- Enum = names for integer constants. Values start at 0 and auto-increment unless assigned (`enum{A=3,B,C}` → B=4, C=5).
- Under the hood it's just an int; set the underlying type for size: `enum Color : uint8_t {...}` (1 byte vs default 4).
- **Plain `enum`**: names leak into the enclosing scope (collisions) + implicit int conversion (silent bugs).
- **`enum class`** (C++11): names scoped (`Color::Red`), no implicit int conversion (needs `static_cast`). Preferred.

## ⚠ Easily confused

- **enum vs enum class** — Plain `enum` leaks names and converts to int implicitly. `enum class` is scoped and type-safe (no implicit int conversion).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 10).