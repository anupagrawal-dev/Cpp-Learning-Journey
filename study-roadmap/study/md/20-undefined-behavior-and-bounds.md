# 20 — Undefined Behavior & Bounds Checking

*Category: C++ Language & Safety*

> [] doesn't check; .at() throws; a passing run is not proof.

## Must-remember points

- `arr[i]` and `array::operator[]` do **NO bounds checking** → out-of-range access is **undefined behavior (UB)**.
- UB can *look* like it works (may print a value, may crash, may corrupt) — 'it printed 4' is NOT proof of correctness.
- `array::at(i)` / `vector::at(i)` **are** bounds-checked → throw `std::out_of_range`.
- Catch bugs with sanitizers: `-fsanitize=address,undefined`.
- C++ philosophy: 'don't pay for what you don't use' — speed by default, safety opt-in via `.at()`.

## Why [] is unchecked

Checking every index costs a comparison on every access — expensive in tight loops. Other languages (Java/Python) check always (safer, slower, no opt-out). C++ gives both: `[]` fast, `.at()` checked.

## ⚠ Easily confused

- **[] vs .at()** — `[]` = fast, no checks, UB on bad index. `.at()` = bounds-checked, throws `std::out_of_range`.
- **UB vs a controlled crash** — UB = anything can happen (silent corruption included). `.at()` throwing (even uncaught → abort) is a controlled, honest failure — far better.
- **'works' vs correct** — A program that runs and prints a value can still be UB. Correctness needs valid indices, not a lucky run.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 20).