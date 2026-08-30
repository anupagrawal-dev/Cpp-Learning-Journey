# 24 — Paging & Virtual Memory

*Category: OS Memory & Systems*

> Chop the process into pages so it needn't be contiguous.

## Must-remember points

- A process's virtual space is cut into equal **pages**; physical RAM into equal **frames** of the same size. Each page is stored in one frame.
- **One frame holds exactly one page** (one big 'ball' fills the box). Different regions (code/heap/stack) land in different frames.
- Paging removes the need for one big contiguous block → solves external fragmentation.
- The program sees a clean **contiguous virtual** layout; the pages sit in **scattered physical** frames. The page table connects them.
- Bonuses: virtual memory (run bigger than RAM), isolation/protection, sharing (one library frame for many processes).

## Page vs frame

A **page** is a chunk of your program (content) — a chapter torn from a book. A **frame** is a slot in RAM (container) — a shelf slot. 'Page 3 in frame 47' = page 3's bytes physically sit in frame 47.

## ⚠ Easily confused

- **page vs frame** — Page = content (a slice of your program). Frame = container (a slot in physical RAM). Same size; one page per frame.
- **virtual vs physical address** — Virtual = per-process, imaginary, contiguous, what the program sees. Physical = the real RAM location; scattered; only the kernel/MMU sees it.
- **contiguous-virtual vs scattered-physical** — Contiguous in virtual space and scattered across frames physically — the page table bridges the two.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 24).