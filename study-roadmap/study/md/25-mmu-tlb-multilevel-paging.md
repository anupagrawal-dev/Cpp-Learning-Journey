# 25 — MMU, TLB & Multi-level Paging

*Category: OS Memory & Systems*

> Hardware translation, a cache for it, and a sparse page-table tree.

## Must-remember points

- The **MMU** is hardware in the CPU that translates virtual→physical on every access, and checks permission bits (raising page/protection faults).
- A virtual address = **page number + offset**: page number → page table → frame number; frame + offset → physical address.
- The **TLB** is the MMU's small cache of recent page→frame translations, so most accesses skip the table walk.
- A single flat page table would be huge (x86-64: ~512 GB per process) → **multi-level paging**: a sparse tree of small tables, only allocating branches that are used.
- x86-64 uses **4 levels** (9+9+9+9 bits + 12-bit offset); each table has 512 entries.

## Why a tree instead of one table

48-bit address, 4 KB pages → 2^36 pages; one flat table = 2^36 × 8 bytes = 512 GB. Most is unused, so a tree creates only the sub-tables for regions in use → a few KB.

## ⚠ Easily confused

- **MMU vs TLB** — MMU = the hardware translator (walks the page table). TLB = a small cache inside/next to the MMU holding recent translations.
- **page number vs offset** — Page number selects WHICH page (→ frame via the table). Offset selects WHERE INSIDE the page/frame.
- **flat vs multi-level page table** — Flat = one giant table (512 GB, impossible). Multi-level = a sparse tree of small tables; only used branches exist.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 25).