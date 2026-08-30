# 17 — Compile-time Constants & VLAs

*Category: C++ Language & Safety*

> Why int arr[n] with a runtime n is not standard C++.

## Must-remember points

- `constexpr int s = 5*4; int a[s];` → legal, portable (compile-time constant).
- `const int s = 5*4; int a[s];` → also legal in C++ (const + constant initializer).
- `int s = 5*4; int a[s];` → **NOT standard C++** — a **VLA** (Variable Length Array).
- VLAs are valid in C (C99); g++/clang allow them as a **non-standard extension**; MSVC rejects them.
- `-pedantic` surfaces the warning in EVERY C++ standard (98→20); the flag, not the version.

## Prove it with the compiler

```bash
g++ -std=c++17 -pedantic t.cpp        # warning: ISO C++ forbids variable length array
g++ -std=c++17 -pedantic-errors t.cpp  # hard error
g++ -std=c++17 t.cpp                    # no warning (extensions on)
```

## ⚠ Easily confused

- **const int size vs plain int size** — `const int` (with a constant initializer) is a compile-time constant → valid array size. A plain `int` is a runtime variable → VLA (non-standard).
- **compiler allows vs standard allows** — g++ accepting it (extensions on) is not the same as the C++ standard allowing it. `-pedantic` shows the difference.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 17).