# 01 — Control Flow

*Category: C++ Core*

> Branching and loops decide which statements run.

## Must-remember points

- Branching (`if`/`else`/`switch`) and loops (`for`/`while`/`do-while`) direct which statements run.
- `switch` needs `break` in each case or it **falls through** to the next case.
- `do-while` runs the body at least once (condition checked after).

## Fall-through gotcha

A `switch` without `break` keeps running the following cases until a `break` or the end.
```cpp
switch(x){
  case 1: doA();      // no break -> also runs case 2!
  case 2: doB(); break;
}
```

## ⚠ Easily confused

- **while vs do-while** — `while` checks the condition BEFORE the first run (may run 0 times); `do-while` checks AFTER (runs at least once).
- **= vs ==** — `=` assigns; `==` compares. `if(x = 5)` assigns 5 and is always true — a classic bug.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 01).