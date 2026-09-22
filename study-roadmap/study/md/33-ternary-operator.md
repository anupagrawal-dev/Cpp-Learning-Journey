# 33 — Ternary Operator

*Category: C++ Core*

> The conditional operator — pick a value inline with cond ? a : b.

## Must-remember points

- Real name = **conditional operator**; the only operator with **three** operands. Syntax: `cond ? a : b`.
- It's an **expression** (yields a value), not a statement — so it works inline: init a variable, a `const`, a `return`, a function argument.
- Only the **chosen** branch is evaluated (safe for guarded access like `p ? *p : 0`).
- Both branches must share a **common type**; if they differ but convert (int/double) the result is the common type — no common type = error.
- Low precedence: wrap it in parentheses with `<<` -> `cout << (c ? "a" : "b");`.
- Nesting/chaining is legal but hurts readability; prefer `if/else` or `switch` beyond one condition.

## One example that shows the key points

```cpp
int a = 3, b = 7;
int max     = (a > b) ? a : b;          // expression -> initialize a variable
const int x = (a < b) ? 5 : 15;         // works for a const (one-shot init)

int* p = nullptr;
int y = p ? *p : 0;                      // only the chosen branch runs -> safe

auto v = (a < b) ? 1 : 2.5;             // int -> double: result type is double

std::cout << (a < b ? "yes" : "no");    // parentheses: << binds tighter than ?:
```

## ⚠ Easily confused

- **ternary vs if/else** — Ternary is an expression that yields a value (works inline, can init a const). if/else runs statements and returns nothing.
- **same type vs common type** — Branches don't need the SAME type — they need a COMMON type. int/double -> result is double; int/string-literal -> error.
- **?: vs << precedence** — `<<` binds tighter than `?:`, so wrap the ternary in parentheses inside a cout.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 33).
