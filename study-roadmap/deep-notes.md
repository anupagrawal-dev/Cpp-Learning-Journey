# Anup — Deep Notes (beyond the video)

Running log of the deep discussions that went *past* the Cherno/other videos.
Videos give the skeleton; these notes are the understanding built on top.
Organized reference versions live in `study/` (this folder) (one page per topic + a question sheet).

---

## 2026-08-29 — OS memory, endianness, and C++ safety (big session)

Sparked by self-study on **paging**; turned into an end-to-end walk from written code to execution, plus a deep C++ safety thread driven by hands-on WSL experiments.

### Systems / OS memory
- **Paging**: process cut into equal **pages**; RAM cut into equal **frames** (same size). One page fills exactly one frame (one big "ball" per box, never many). Solves the need for contiguous RAM.
- **Page vs frame** = content vs container. "Page 3 in frame 47" = page 3's bytes physically sit in frame 47.
- **Virtual address space is imaginary** — holds nothing, does NOT hold RAM; it's a set of address labels. Real bytes live in frames; the page table translates.
- **Contiguous-virtual / scattered-physical**: the neat memory layout (text/data/heap/stack) is virtual; frames are scattered; the page table bridges them.
- **External fragmentation** = wasted gaps BETWEEN allocations (contiguous alloc suffers). **Internal** = wasted space in the LAST page of a region (paging causes a little). Internal hits only the last page because earlier pages are full.
- External fragmentation is a **problem, not a method** — contiguous allocation suffers it; paging cures it. (Also covered how it builds up over time: variable-size programs start/stop → holes separated by live programs + carved into slivers.)
- **Segmentation**: divide by meaning (code/data/stack), variable size, base+limit per segment (limit = protection). Great for permissions/sharing, but external frag returns. Modern OSes use paging (often under a thin segmentation layer).
- **MMU** = hardware translator (virtual→physical every access + permission checks). **Address = page number + offset**. **TLB** = cache of recent translations.
- **Multi-level paging**: a flat table would be ~512 GB/process (x86-64); use a sparse tree of small 512-entry tables (4 levels on x86-64, 9+9+9+9+12 bits) — only used branches exist.
- **Demand paging**: load a page on first touch; miss = **page fault** (OS loads from disk, restarts instruction). Costly (~1000× RAM) but paid once/page, amortized by locality. Minor fault = already resident; major = disk read.
- **Swapping**: evict cold pages to disk when RAM is full = virtual memory. Working set > RAM → **thrashing**.

### Endianness
- Little-endian (x86) stores least-significant byte first → raw bytes look reversed vs how we write numbers. Flip to read (`F4 01 00 00` → `0x000001F4` = 500).
- Applies to EVERY multi-byte value (int AND pointer — a pointer is just an 8-byte int). Only visible in raw bytes (hex dump / `char*` / cross-machine); `cout << p` prints the real, readable address.
- Detect: `int n=1; *(char*)&n == 1` → little-endian.

### C++ language & safety (hands-on in WSL)
- **VLA**: `int a[n]` with runtime `n` is NOT standard C++ — a GNU/Clang extension. Proven: `-pedantic` warns in every `-std` (98→20); `-pedantic-errors` makes it an error; MSVC rejects. Use `constexpr`/`const` for real compile-time array sizes. Tell: VLA `sizeof` is runtime.
- **const vs constexpr vs volatile**: const = read-only (may be runtime-set); constexpr = compile-time-known (needed for array sizes/templates); volatile = don't optimize, re-read each access (hardware/signals) — NOT a threading tool (use `std::atomic`).
- **`array[10]` on a size-5 `std::array`** printed `4` — that's **undefined behavior**, not correctness. `operator[]` does no bounds check (speed by default). `.at()` DOES check → throws `std::out_of_range`.
- **AddressSanitizer** (`-fsanitize=address -g`): runtime detector; must RUN to trigger. Caught the stack-buffer-overflow, showed `[32,52) 'a'` (20 bytes = 5 ints) with write at offset 72. Redzones = tripwires. Aborts on first error (`halt_on_error=0` to continue).
- **Exceptions**: uncaught `.at()` throw → `std::terminate` → "Aborted (core dumped)"; wrap in `try/catch (const std::out_of_range&)` to recover. Catch by const reference.
- **array vs vector**: array = fixed compile-time size, stack, no growth; vector = dynamic, heap, `push_back`.
- **Arrays & contiguity**: 100k ints ≈ 400 KB; must be contiguous in VIRTUAL space (indexing = `base + i*size`); physical frames can be scattered. Big arrays → heap, not stack.

### Learning method (his own realization)
- The depth came from the *discussion*, not the video. Correct instinct. Video's job = give the map/vocabulary so you know what to ask; discussion + hands-on = mastery.
- Capture habit started: this file + the `study/` reference set + question sheet.

**Engagement:** strong throughout — tested claims himself (VLA across all `-std`, ASan, `.at()`), reasoned paging from first principles. Not a beginner; building real momentum.
