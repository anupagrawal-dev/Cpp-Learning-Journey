# 04 — References

*Category: C++ Core*

> An alias to an existing variable, fixed at declaration.

## Must-remember points

- A reference is an **alias** to an existing variable's address, **fixed at declaration** — cannot be reseated.
- Must be initialized when declared; **cannot be null** (in well-formed code); no reference arithmetic.
- Pass-by-value = copy (changes don't escape); pass-by-reference (`int&`) = writes go straight to the caller's variable.

## Why pass by reference

Passing a big object by value copies it. A reference (or `const` reference) avoids the copy and can modify the caller's object.
```cpp
void addTip(int& bill){ bill += 10; }
void look(const std::string& s);  // no copy, read-only
```

## ⚠ Easily confused

- **reference vs pointer** — A reference is a fixed alias (no null, no reseating, no `*`/`&`). A pointer can be null, reseated, and needs dereferencing.
- **pass-by-value vs pass-by-reference** — By value copies the argument (changes stay local). By reference operates on the caller's actual variable.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 04).