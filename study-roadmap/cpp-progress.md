# Anup — C++ Learning Progress (The Cherno C++ series)

This file is the source of truth for Anup's C++ study. The evening coach reads it every run,
delivers a session for the CURRENT video, and updates it as Anup advances.

## Current status
- Current Cherno video: **Interfaces (Pure Virtual Functions)** (most recently watched; self-studied a batch)
- Stage for this video: `just_watched` — deep-dive delivered 2026-08-01; practice + LeetCode PENDING
- Last session date: 2026-08-01 (Anup reported self-watching a batch through Interfaces: Writing a Class, Static, Static for Classes/Structs, Enums, Constructors, Destructors, Inheritance, Virtual Functions, Interfaces). Deep-dive on Interfaces delivered this session.

## How to advance
When Anup says he has finished the practice + LeetCode for the current topic AND watched the next one,
update "Current Cherno video" to the new title/number, reset Stage to `just_watched`, and log the
finished video below.

## Completed videos log
| Video | Deep-dive done | Practice program done | LeetCode done |
|-------|:---:|:---:|:---:|
| #15 Control Flow | ✅ | pending | pending (FizzBuzz #412) |
| Pointers | ✅ | pending | pending |
| Stack & Heap Memory | ✅ | ✅ (2026-07-18) | pending (Min Stack #155) |
| References | ✅ (self) | — | — |
| Classes | ✅ (self) | — | — |
| Classes vs Structs | ✅ (2026-07-18) | ✅ BankAccount (2026-07-18) | pending |
| Writing a Class | ✅ (self) | pending | pending |
| Static | ✅ (self) | pending | pending |
| Static for Classes/Structs | ✅ (self) | pending | pending |
| Enums | ✅ (self) | pending | pending |
| Constructors | ✅ (self) | pending | pending |
| Destructors | ✅ (self) | pending | pending |
| Inheritance | ✅ (self) | pending | pending |
| Virtual Functions | ✅ (self) | pending | pending |
| Interfaces (Pure Virtual) | ✅ (2026-08-01 deep-dive) | pending | pending |

## LeetCode problems attempted
| # | Problem | Related topic | Status |
|---|---------|---------------|--------|
| 412 | FizzBuzz | Control Flow | assigned |
| 155 | Min Stack | Stack & Heap | assigned (pending) |
| 1603 | Design Parking System | Classes vs Structs | assigned 2026-07-22 |

## Notes / weak spots to revisit
- Stack/heap: strong conceptual grasp (SP shift vs free-list search, growth direction, alignment vs stack canaries). Reinforced 2026-07-17.
- Practice program 2026-07-18: wrote stack-vs-heap address program. GOTCHA to reinforce: printed `&p` (address of pointer, on stack) instead of `p` (the heap address). Also initially leaked `d` — no `delete[]`. Corrected both. Watch for &ptr vs ptr confusion in future pointer topics.
