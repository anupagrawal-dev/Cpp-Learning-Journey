# 08 — Static (outside classes)

*Category: C++ Core*

> File-scope static = internal linkage; static local = persists across calls.

## Must-remember points

- `static` at file/global scope → **internal linkage**: symbol visible only in that translation unit (opposite of `extern`).
- Two same-named non-static globals defined in two TUs → duplicate-symbol link error; bare `extern int x;` with no definition → 'undefined reference'.
- `static` **local variable** → initialized **once** on first entry, **retains value between calls**, lifetime = whole program, scope = the function. Thread-safe init since C++11.
- Global static init order across TUs is unspecified ('static initialization order fiasco'); static locals dodge it (init on first use).

## ⚠ Easily confused

- **static (file) vs extern** — `static` global = internal linkage (private to this file). `extern` = 'defined elsewhere, share it' (external linkage).
- **static local vs normal local** — A normal local is created/destroyed each call. A `static` local is created once, keeps its value between calls, and lives for the whole program.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 08).