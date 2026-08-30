# 18 — Arrays & Memory Contiguity

*Category: C++ Language & Safety*

> Contiguous in virtual space; scattered in physical RAM.

## Must-remember points

- `int` is 4 bytes → an array of 100,000 ints ≈ **400 KB**.
- An array MUST be contiguous: `arr[i]` is computed as `base + i*sizeof(int)` — pointer arithmetic depends on it.
- Contiguity is required in **virtual** address space, not physical RAM. The array's pages can sit in scattered frames; the page table makes them appear contiguous.
- Big arrays belong on the **heap** (`new`/`vector`); a large local array can overflow the ~1–8 MB stack.
- With demand paging, virtual space is reserved immediately but physical frames arrive lazily on first touch.

## Why scattered-physical is fine

A 400 KB array spans ~100 pages (4 KB each). They're contiguous in VIRTUAL addresses (what `arr[i]` uses) but can map to scattered physical frames. Within a page the ints are contiguous; across a page boundary the next frame may be anywhere — the virtual addresses stay continuous, so indexing never notices.

## ⚠ Easily confused

- **virtual-contiguous vs physical-scattered** — The array is one continuous run of VIRTUAL addresses (what indexing uses). In physical RAM its frames can be scattered — fine, thanks to the page table.
- **stack array vs heap array** — `int a[N]` local = on the stack (small, risky for big N). `new int[N]` / `std::vector` = on the heap (large).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 18).