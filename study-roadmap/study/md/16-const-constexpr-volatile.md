# 16 — const, constexpr & volatile

*Category: C++ Language & Safety*

> Read-only vs compile-time-known vs don't-optimize.

## Must-remember points

- `const` = won't change after initialization (but CAN be set at runtime).
- `constexpr` = value/function evaluable at **compile time** (stronger). Every `constexpr` is `const`, not vice versa.
- `constexpr` function: runs at compile time with compile-time args, else at runtime.
- `volatile` = don't optimize accesses; re-read from memory every time (value may change externally). **Not** for thread sync — use `std::atomic`.

## const vs constexpr

```cpp
int n = getInput();
const int a = n;       // OK: const, value known at RUNTIME
constexpr int b = n;   // ERROR: n not a compile-time constant
constexpr int c = 42;  // OK
```

## ⚠ Easily confused

- **const vs constexpr** — const = read-only (may be set at runtime). constexpr = computed by the compiler before the program runs.
- **constexpr vs volatile** — Opposite ends: constexpr pushes work to compile time; volatile forbids optimization and forces runtime re-reads.
- **volatile vs atomic** — `volatile` = re-read from memory, no thread guarantees. `std::atomic` = actual thread-safe atomicity/ordering.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 16).