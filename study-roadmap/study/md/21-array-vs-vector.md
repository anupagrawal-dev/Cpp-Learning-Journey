# 21 — std::array vs std::vector

*Category: C++ Language & Safety*

> Fixed size vs growable; pick by whether the count is known.

## Must-remember points

- `std::array<T,N>` = **fixed** size baked in at compile time; cannot grow. Lives on the stack (no heap).
- `std::vector<T>` = **dynamic**; grows at runtime with `push_back`/`resize`. Backed by the heap.
- Both offer `[]` (unchecked) and `.at()` (checked), and `.size()` to loop safely.
- Fixed, known count → `array`. Varies/grows → `vector`.

## Choosing

```cpp
std::array<int,5> a = {10,20,30,40,50};
std::vector<int> v; v.push_back(10); v.push_back(20);
```

## ⚠ Easily confused

- **array vs vector** — array = fixed compile-time size, stack, no growth. vector = dynamic, heap, `push_back` to grow.
- **size vs capacity** — array's size is fixed forever. vector has a size (elements) and a capacity (allocated room) that grows as needed.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 21).