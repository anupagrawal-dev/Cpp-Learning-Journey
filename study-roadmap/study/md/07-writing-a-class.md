# 07 — How to Write a Class

*Category: C++ Core*

> Split private data vs public interface; mind inline, headers, and const.

## Must-remember points

- Decide what's **private (data)** vs **public (interface)**; outsiders touch data only through methods.
- Method defined *inside* the class body = implicitly `inline`; defined *outside* needs `Class::method`. Forgetting `Class::` → treated as an unrelated global → linker 'undefined reference'.
- Header/source split: declarations in `.h`, definitions in `.cpp` (ODR — a non-inline body in a header included by multiple TUs = duplicate-symbol error).
- **const-correctness**: a method that doesn't modify the object should be `const` (`int GetX() const`).

## ODR — One Definition Rule

A non-inline function may be DEFINED only once across the whole program. A full function body in a header included by two .cpp files = two definitions → duplicate-symbol link error. Declarations in headers; definitions in one .cpp.

## ⚠ Easily confused

- **declaration vs definition** — A declaration says 'this exists' (goes in .h); a definition provides the body/storage (goes in one .cpp).
- **inline member vs Class::** — Defined inside the class body → implicitly inline. Defined outside → must qualify with `Class::` or it's an unrelated global.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 07).