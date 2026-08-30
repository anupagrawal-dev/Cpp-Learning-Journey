# 23 — AddressSanitizer & Debugging Tools

*Category: C++ Language & Safety*

> A runtime detector that plants tripwires around your memory.

## Must-remember points

- Compile with `-fsanitize=address -g`; ASan is a **runtime** detector — it reports only when a bad access actually executes (a clean program prints nothing).
- It surrounds variables with poisoned **redzones**; touching one = flagged (`stack-buffer-overflow`, `heap-use-after-free`, etc.).
- By default it **aborts on the first error**; `ASAN_OPTIONS=halt_on_error=0` continues.
- The report shows the exact line, the variable, and its byte offsets (e.g. `[32,52) 'a'` = 20 bytes = 5 ints).
- Companion tools: `-fsanitize=undefined` (UBSan), `gdb`, `valgrind`.

## Reading the report

`'a' <== Memory access at offset 72 overflows this variable` with `[32, 52) 'a'` means the array is stack bytes 32–52 (20 bytes) and you wrote at offset 72 — 20 bytes past the end.

## ⚠ Easily confused

- **compile-time vs runtime detection** — ASan instruments at compile time but only reports at RUNTIME, when the bad access runs. Compiling clean ≠ bug-free.
- **ASan redzone vs stack canary** — Both guard memory, but ASan redzones catch any out-of-bounds access; a stack canary specifically detects return-address smashing.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 23).