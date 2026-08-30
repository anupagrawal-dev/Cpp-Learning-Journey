# 26 — Allocation Methods & Fragmentation

*Category: OS Memory & Systems*

> Contiguous vs paging vs segmentation; internal vs external waste.

## Must-remember points

- Allocation schemes: **contiguous** (one block per process), and non-contiguous — **paging** (fixed pages) and **segmentation** (variable logical segments).
- **External fragmentation** = wasted gaps BETWEEN allocations (contiguous & segmentation suffer it). Paging cures it.
- **Internal fragmentation** = wasted space INSIDE the last page of a region (paging causes a little; ≤ page size − 1).
- Internal frag hits only the **last** page because every earlier page is completely full.
- External fragmentation is a **problem**, not a method — you don't choose it; contiguous allocation suffers it, paging avoids it.

## Segmentation in one line

Divide by MEANING (code/data/stack) into variable-size segments; address = (segment number, offset); segment table holds base+limit (limit = protection). Great for per-segment permissions/sharing, but variable size + contiguous placement brings external fragmentation back. Modern OSes use paging (often under a thin segmentation layer).

## ⚠ Easily confused

- **internal vs external fragmentation** — Internal = waste INSIDE an allocated block (last page). External = waste in gaps BETWEEN blocks.
- **paging vs segmentation** — Paging = fixed-size pages, avoids external frag, small internal frag. Segmentation = variable logical segments, great for protection/sharing, but external frag returns.
- **problem vs method** — External fragmentation is a side effect (problem). Paging/segmentation/contiguous are methods. You don't 'do external fragmentation'.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 26).