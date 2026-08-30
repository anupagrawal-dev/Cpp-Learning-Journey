# Anup — C++/Linux Revision Log (main points per topic)

Purpose: the coach appends the KEY points of each topic here every day.
Every **Sunday**, the coach runs a REVISION session: questions drawn from all
topics below (spaced repetition), then notes any weak spots at the bottom.

Format per topic: 3–6 crisp bullet points = the "must-remember" core.

---

## C++ (The Cherno series)

### Control Flow (#15)
- Branching (`if`/`else`/`switch`) and loops (`for`/`while`/`do-while`) direct which statements run.
- `switch` needs `break` or it falls through to the next case.
- LeetCode: FizzBuzz (#412) — assigned.

### Pointers
- A pointer holds an **address**. `*` dereferences (read/write the pointed-to value); `&` takes an address.
- A pointer variable itself lives on the stack; what it points to may be stack or heap.
- Can be reseated (change which address it holds) and can be null.

### Stack & Heap Memory  ⭐ (deeply covered 2026-07-18)
- **Stack**: memory already committed to the process; allocation = move the stack pointer. Fast, automatic lifetime tied to scope. High addresses (`0x7fff...`), grows **DOWN** per function call.
- **Heap**: allocator searches a free list for a block; `new`/`delete`. Slow, manual lifetime. Low addresses (`0x55...` under PIE), grows **UP**.
- `push` = decrement SP to a **lower** address (`sub rsp,8; mov [rsp],val`). "Top of stack" = lowest address.
- Across function calls the frame always moves down; **within a frame** the compiler orders locals however it likes (don't infer growth from consecutive locals).
- Gotchas: returning `&local` = **dangling pointer / UB**; `new`↔`delete`, `new[]`↔`delete[]` (mismatch = UB); stack is small (~MBs) → deep recursion overflows.
- To see the heap address print `p`, not `&p` (which is the pointer's own stack address). ASLR randomizes the base each run.
- LeetCode: Min Stack (#155) — still pending.

### References
- A reference is an **alias** to an existing variable's address, **fixed at declaration** — cannot be reseated.
- Must be initialized when declared; **cannot be null** (in well-formed code); **no reference arithmetic**.
- Pass-by-value = copy (changes don't escape); pass-by-reference (`int&`) = writes go straight to the caller's variable.

### Classes (encapsulation)
- Private data + public methods = every change is forced through a **single gate** that validates it → object can never reach an invalid state (invariant safety).
- Private isn't about security/attackers — it's about **controlled change** + freedom to change internals later without breaking users.
- The gate (public method) can enforce any rule before writing: no overdraft, no negative amount, clamp ranges, format checks, etc.

### Classes vs Structs
- Only **two** real language differences: (1) default access — `struct` public, `class` private; (2) default inheritance — `struct` public, `class` private.
- Everything else is identical (both can have ctors, methods, virtuals, inheritance, templates...).
- `template<class T>` / `template<typename T>` allowed; `template<struct T>` is not.
- Convention only: struct = passive data bundles; class = encapsulated types with behavior/invariants.

### How to Write a Class (2026-08-01)
- Decide what's **private (data)** vs **public (interface)**; outsiders touch data only through methods → invariants protected.
- Method defined *inside* class body = implicitly `inline`; defined *outside* needs scope resolution `Class::method`. Forgetting `Class::` → compiler treats it as an unrelated global → linker "undefined reference."
- Header/source split: declarations in `.h`, definitions in `.cpp` (ODR — non-inline body in a header included in multiple TUs = duplicate-symbol error).
- **const-correctness**: a method that doesn't modify the object should be `const` (`int GetX() const`); lets you call it on const objects/refs. Interviewers notice missing const on getters.

### Static — outside classes (2026-08-01)
- `static` at **file/global scope** → **internal linkage**: symbol visible only in that translation unit (opposite of `extern`). Prevents duplicate-symbol clashes; each TU gets its own copy.
- Two non-static same-named globals *defined* in two TUs → duplicate-symbol link error; bare `extern int x;` with no definition anywhere → "undefined reference." `extern` = "defined elsewhere, share it."
- `static` **local variable** inside a function → initialized **once** on first entry, **retains value between calls**, lifetime = whole program, scope = the function. Thread-safe init since C++11 ("magic statics").
- Global static init **order across TUs is unspecified** → "static initialization order fiasco"; static locals dodge it (init on first use).

### Static — for Classes & Structs (2026-08-01)
- Static **member variable** = **one shared copy for all objects**, lives in static storage → does NOT add to object `sizeof`. Classic use: instance counter.
- A non-inline static data member must be **defined once outside the class** (`int Entity::count = 0;`) or → "undefined reference." C++17 `inline static` avoids the separate definition.
- Static **member function** has **no `this`** → callable as `Class::fn()` without an object, and can **only** access static members (can't read per-object data). Common interview trap.

### Enums (2026-08-01)
- Enum = names for integer constants. Values start at 0 and auto-increment unless assigned (`enum {A=3,B,C}` → B=4, C=5).
- Under the hood it's just an int; can set underlying type for size: `enum Color : uint8_t {...}` (1 byte vs default 4).
- **Plain `enum`** = names leak into enclosing scope (collisions) + implicit int conversion (silent bugs comparing unrelated enums).
- **`enum class`** (C++11) fixes both: names scoped (`Color::Red`), no implicit int conversion (needs `static_cast`). Preferred in modern C++.

### Constructors (2026-08-01)
- Special member, **same name as class, no return type**, runs automatically on object creation; job = valid initial state / acquire resources / enforce invariants.
- Compiler supplies a free **default (no-arg) ctor ONLY if you write zero ctors**. Write any ctor → free default is gone → `Entity e;` fails unless you add `Entity() = default;` or your own.
- Can be overloaded; `= default` / `= delete` force or forbid.
- **Member initializer list** (`: m_X(0)`) inits before body; **required** for `const` members, references, and object members with no default ctor; avoids default-then-reassign.
- **Most vexing parse**: `Entity e;` = object, but `Entity e();` = a *function declaration*. Use `Entity e;` or `Entity e{}`.

### Destructors (2026-08-01)  ⭐ strong
- `~ClassName()`, no params/return, exactly one (no overload). Runs at end of scope (stack) or on `delete` (heap). Members destroyed in **reverse** order; derived dtor before base.
- **RAII**: tie a resource's lifetime to an object's lifetime → cleanup is automatic & exception-safe (system won't reclaim leaked resources; the destructor is the reliable release point).
- **Virtual destructor** required on any polymorphic base: `delete` derived via base pointer with non-virtual dtor = **UB / leak** (only base part destroyed).
- **Rule of 3/5**: custom dtor ⇒ likely need custom copy ctor + copy assignment (+ move ctor/assignment in C++11), else shallow copy → shared pointer → double-free.

### Inheritance (2026-08-01)
- Derived class takes on base members; **code reuse** + models **is-a** (Audi is-a Car). Contrast **has-a** = composition (Car has-an Engine, a member object).
- Derived object contains a base subobject (**base part laid out first**); construction base→derived, destruction derived→base.
- Inheritance modes: `public` (true is-a; access levels preserved), `protected` (public/protected → protected), `private` (all → private; default for `class`).
- `protected` member = accessible to the class's own methods **and derived classes**, not outside ("family only").
- **Object slicing**: assigning derived → base **by value** copies only the base part (derived sliced off) → use base **pointers/references** for polymorphism. Diamond problem solved by `virtual` inheritance.

### Virtual Functions (2026-08-01)  ⭐ strong
- Without `virtual`, `basePtr->fn()` uses **static dispatch** → picks by **pointer type** (base version). `virtual` → **dynamic dispatch** → picks by **actual object type** at runtime.
- **vtable** = per-class array of function pointers, one slot per virtual fn (same slot order across base/derived); overridden slots point to derived versions, non-overridden inherit base's. **vptr** = hidden per-object pointer to its class's vtable. Call = index into vtable + call.
- Only **virtual** functions are in the vtable — normal/static functions and ctors are not; a class with zero virtuals has **no vtable/vptr** (no size cost).
- Cost: vptr (~8 bytes/object on 64-bit) + one indirection + usually no inlining.
- Use `override` (compiler verifies you match a base virtual) and `final` (stop further overriding).

### Interfaces / Abstract Classes (2026-08-01)
- Class with **≥1 pure virtual** (`virtual void f() = 0;`) = **abstract** → cannot be instantiated (`Widget w;` fails). ALL functions pure + no data = an **interface** (convention; no keyword).
- You CAN use base pointers/refs to an abstract class — that's the whole point: `Base* p = new Derived();` is valid as long as Derived **overrides every pure virtual** (making it concrete).
- An abstract base can still provide **implemented** (normal virtual) methods → shared behavior for all derived (Template Method pattern); pure virtuals force each derived to supply its own.
- Pure virtual's vtable slot points to a `__cxa_pure_virtual` stub until overridden. **Interface needs a virtual destructor.**
- Defines a **capability** (Printable/Serializable/Drawable) so unrelated classes are treated uniformly through interface pointers as long as they honor the contract.

### const / constexpr / volatile (2026-08-29)
- `const` = read-only after init (may be set at **runtime**); `constexpr` = evaluable at **compile time** (stronger; needed for array sizes, templates, switch cases). Every constexpr is const, not vice versa.
- `constexpr` function runs at compile time with compile-time args, else at runtime.
- `volatile` = don't optimize accesses; re-read from memory each time (hardware registers, signal handlers). **NOT** a threading tool — use `std::atomic`.

### Compile-time constants & VLAs (2026-08-29) ⭐ hands-on
- `int a[n]` with a runtime `n` = a **VLA** → NOT standard C++ (C99 + GNU/Clang extension only; MSVC rejects). `-pedantic` warns in every `-std` (98→20) — the flag, not the version, surfaces it; `-pedantic-errors` makes it an error.
- Use `constexpr`/`const` (with a constant initializer) for real compile-time array sizes. Tell: a VLA's `sizeof` is computed at runtime.

### Endianness (2026-08-29)
- Little-endian (x86) stores least-significant byte first → raw bytes look reversed; flip to read the value (`F4 01 00 00` → `0x000001F4` = 500).
- Applies to EVERY multi-byte value incl. pointers (a pointer is just an 8-byte int); only visible in raw bytes (hex / `char*` / cross-machine). `cout << p` shows the real readable address.
- Detect: `int n=1; *(char*)&n == 1` → little-endian.

### Arrays & memory contiguity (2026-08-29)
- 100k ints ≈ **400 KB**; arrays must be contiguous in **virtual** space (index = `base + i*size`); physical frames may be scattered (page table bridges).
- Big arrays → **heap** (`new`/`vector`); a large local array can overflow the small (~1–8 MB) stack.

### Undefined Behaviour & bounds checking (2026-08-29) ⭐ hands-on
- `[]` / `array::operator[]` do **NO** bounds check → out-of-range = **UB** (may "work", crash, or corrupt). A passing run is not proof of correctness.
- `.at()` bounds-checks → throws `std::out_of_range`. Uncaught throw → `std::terminate` ("Aborted"); wrap in `try/catch (const std::out_of_range&)` to recover.
- **AddressSanitizer** (`-fsanitize=address -g`) = runtime detector (must RUN); redzones catch overflows; report shows the variable + byte offsets; aborts on first error.
- C++ philosophy: fast by default (`[]`), safety opt-in (`.at()`, sanitizers).

### std::array vs std::vector (2026-08-29)
- `array` = fixed compile-time size, stack, no growth. `vector` = dynamic, heap, `push_back` to grow. Both: `[]` unchecked, `.at()` checked, `.size()` to loop safely.

---

## Linux (for C/C++ backend roles)

### Topic 1 — Filesystem & navigation (part 1)
- Single tree rooted at `/`; no drive letters. Absolute path starts at `/`; relative path starts from current dir. `.` = here, `..` = parent.
- Relative paths in code (`open("config.txt")`) resolve against the process's working directory — common "file not found" bug.
- Commands: `pwd`, `ls -la`, `cd ..`.

### Topic 1 — Permissions (part 2)
- `ls -l` line: 10 chars = 1 file-type (`-` file, `d` dir, `l` symlink) + 3 triplets `rwx` for owner / group / others.
- r=4, w=2, x=1; add per triplet → numeric modes like 755 (rwxr-xr-x), 644 (rw-r--r--).
- A binary needs the **x** bit to run with `./` ; source `.cpp` is usually 644 (no x), compiled binary 755.
- Next: `chmod` / `chown` to change the bits.

### Topic 1 — chmod (part 3)
- Numeric mode sets all three triplets at once: `chmod 755 f` (rwx/r-x/r-x), `chmod 644 f` (rw-/r--/r--).
- Symbolic mode nudges bits: `chmod +x f` (x for all), `chmod u+x f` (owner only); u=owner, g=group, o=others, a=all.
- Missing **x** = "Permission denied" when running `./script.sh` or a fresh binary — the #1 cause.

### Topic 1 — chown / ownership (part 4) (2026-08-01)
- `chown` changes a file's owner (± group): `chown user file`, `chown user:group file`, `chown :group file` (group only); `-R` = recursive. `chgrp group file` changes only the group.
- **Only root (sudo) can change a file's owner** — a regular user can't give their file away or take another's, even one they can read/write (security + quota reasons). Owner *can* change group to a group they belong to.
- Ownership + rwx triplets together gate access: a process's UID/GID is checked against owner/group/other bits on every open/read/write.
- `id` = your UID/GID/groups; `whoami` = your username — the identity the kernel checks.
- Systems relevance: deploying a service = chown binary/data to a service user; setuid / privilege-dropping daemons rely on ownership.

---

## Systems / OS Memory (self-study + deep-dive 2026-08-29)

### Paging & virtual memory
- Process cut into equal **pages**; RAM into equal **frames** (same size); **one page fills exactly one frame**. Removes the need for contiguous RAM.
- **Page** = content, **frame** = container. Virtual address space is **imaginary** (holds nothing, is NOT RAM) — labels the page table translates to real frames.
- The neat layout (text/data/heap/stack) is **virtual**; frames are **scattered**; the page table bridges them. Bonuses: virtual memory, isolation, sharing.

### Allocation methods & fragmentation
- Schemes: **contiguous** (one block), **paging** (fixed pages), **segmentation** (variable logical segments, base+limit, per-segment protection/sharing).
- **External frag** = gaps BETWEEN allocations (contiguous/segmentation suffer); paging cures it. **Internal frag** = waste in the LAST page (paging causes a little) — only the last page, since earlier pages are full.
- External fragmentation is a **problem, not a method**: contiguous allocation suffers it, paging avoids it.

### MMU, TLB & multi-level paging
- **MMU** = hardware; translates virtual→physical every access + checks permissions. Address = **page number + offset**.
- **TLB** = cache of recent translations (skip the walk). **Multi-level paging**: a flat table would be ~512 GB/process (x86-64) → a sparse tree of 512-entry tables (**4 levels** on x86-64), only used branches created.

### Demand paging & swapping
- **Demand paging**: load a page on first touch; miss = **page fault** (OS loads from disk, restarts instruction). Costly (~1000× RAM) but paid once/page, amortized by locality. **Minor** (already resident) vs **major** (disk read) fault.
- **Swapping** evicts cold pages to disk when RAM is full = virtual memory. Working set > RAM → **thrashing**.

---

## Weak spots to revisit (updated as we go)
- &ptr vs ptr confusion (caught in stack/heap practice 2026-07-18) — watch in future pointer work.
- Encapsulation "why private" — clarified 2026-07-18; confirm it's solid on next Sunday revision.
- Headers must #include what they use — main.h used std::cout without including <iostream> (compiled only by include-order luck). Flagged twice 2026-07-18; recheck.
- float→int truncation awareness (interest calc) — noted 2026-07-18; fine but watch in money math.
- BankAccount practice (2026-07-18): private balance + overdraft guard + applyInterest(BankAccount&) by reference + TransactionLog struct. All working; by-reference mutation confirmed (100→102).
- OS memory (paging/MMU/fragmentation/demand paging), endianness, and C++ safety (const/constexpr/volatile, VLA, UB & `[]` vs `.at()`, ASan, exceptions) — freshly covered 2026-08-29 with strong hands-on engagement; confirm retention next Sunday. Full reference set in `study/`.
- Still-pending practice/LeetCode carried forward: Min Stack #155 (Stack&Heap), FizzBuzz #412 (Control Flow), Design Parking System #1603 (Classes vs Structs).

---

## Revision session log
| Sunday date | Topics revised | Result / notes |
|-------------|----------------|----------------|
| (none yet)  |                |                |
