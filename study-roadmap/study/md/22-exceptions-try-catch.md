# 22 — Exceptions & try/catch

*Category: C++ Language & Safety*

> Throw signals an error; catch handles it; uncaught = abort.

## Must-remember points

- `throw` raises an exception; a matching `catch` handles it. `.at()` throws `std::out_of_range` on a bad index.
- An **uncaught** exception propagates to `std::terminate` → 'Aborted (core dumped)'. That crash means nobody handled it.
- Wrap risky code in `try { ... } catch (const std::exception& e) { ... }`; `e.what()` gives the message.
- Catch by `const` reference (avoids slicing and copies).

## Handle vs abort

```cpp
try { a.at(10) = 4; }              // throws
catch (const std::out_of_range& e){
  std::cout << e.what();           // handled — program continues
}
```

## ⚠ Easily confused

- **uncaught throw vs bug in .at()** — The abort is from nobody catching the exception — `.at()` did its job by detecting the bad index.
- **catch by value vs by reference** — Catch by `const&` — catching by value can slice the exception object and copies it.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 22).