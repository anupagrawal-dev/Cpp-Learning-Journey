# 03 — Stack & Heap Memory

*Category: C++ Core*

> Two regions with very different allocation, speed, and lifetime rules.

## Must-remember points

- **Stack**: memory already committed; allocation = just move the stack pointer. Fast, automatic lifetime tied to scope. High addresses (`0x7fff...`), grows **DOWN**.
- **Heap**: allocator searches a free list for a block; `new`/`delete`. Slower, manual lifetime. Lower addresses, grows **UP**.
- `push` = decrement SP to a **lower** address; 'top of stack' = lowest address.
- Returning `&local` = dangling pointer/UB; mismatched `new`/`delete[]` = UB; deep recursion overflows the small (~MB) stack.
- ASLR randomizes the base address each run.

## Why the stack is fast

Stack memory is already reserved; allocating a local just moves the stack-pointer register, freeing moves it back on return. No searching, no bookkeeping.

## Why the heap is flexible but slower

`new` asks the allocator to find a free block (walk a free list), mark it used, return its address; you must `delete` it. Lifetime can outlive the function and size can be decided at runtime — at the cost of speed + manual management.

## ⚠ Easily confused

- **stack vs heap** — Stack = automatic, scope-bound, fast, small. Heap = manual (`new`/`delete`), lives until freed, flexible, slower.
- **grows down vs 'top'** — The stack grows toward LOWER addresses, so the 'top' (most recent push) is the LOWEST address.
- **&ptr vs ptr** — For a heap pointer `p`: `p` is the heap address; `&p` is p's own stack slot.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 03).