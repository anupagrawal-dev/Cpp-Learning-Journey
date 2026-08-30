# 27 — Demand Paging, Page Faults & Swapping

*Category: OS Memory & Systems*

> Load pages lazily; overflow cold pages to disk.

## Must-remember points

- **Demand paging**: don't load the whole program up front — load each page only on first use.
- Touching a not-present page raises a **page fault**: the OS grabs a free frame, loads the page from disk, updates the table, restarts the instruction — invisibly.
- A page fault is expensive (disk ~1000× slower than RAM) but paid **once per page**, then amortized over many fast reuses (locality of reference).
- **Swapping**: when RAM is full, evict a cold page to disk (swap) to free a frame — this lets a program use more memory than physical RAM (virtual memory).
- Working set > RAM → constant faults = **thrashing** (severe slowdown).

## Minor vs major fault

Minor = page already in RAM (cache/shared/zero-fill) → just fix the mapping (cheap). Major = must read from disk (expensive).

## ⚠ Easily confused

- **demand paging vs swapping** — Demand paging = load pages in on first use. Swapping = push cold pages out to disk when RAM is full. Two directions of the same virtual-memory system.
- **minor vs major page fault** — Minor = no disk I/O (page already resident). Major = disk read required.
- **page fault vs segfault** — A page fault is normal (OS loads a page). A segmentation fault is an illegal access the OS refuses — different thing.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 27).