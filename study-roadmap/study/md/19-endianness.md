# 19 — Endianness

*Category: C++ Language & Safety*

> Byte order of multi-byte values; only visible in raw bytes.

## Must-remember points

- Endianness = the order bytes of a multi-byte value are stored. Little-endian stores least-significant byte first (x86/x64, most ARM); big-endian stores most-significant first.
- The **value** (how we write a number, MSB first) looks like big-endian; little-endian storage is reversed — flip to read it.
- Applies to EVERY multi-byte value (int, pointer). A pointer is just an 8-byte integer → stored little-endian too.
- Only visible in **raw bytes** (hex dump, `char*`, cross-machine data). `cout`/`printf` show the actual number, never reversed.
- Single bytes (`char`) are unaffected; network byte order is big-endian (`htonl`/`ntohl`).

## Reading a dump

```
int x = 500;   // 0x000001F4
memory (little-endian): F4 01 00 00
reverse -> 00 00 01 F4 = 500
```

## ⚠ Easily confused

- **little vs big endian** — Little = least-significant byte at the lowest address (reversed from writing). Big = most-significant first (reads naturally).
- **stored bytes vs the value** — Raw bytes are endian-dependent (reversed on little-endian). The printed value is always normal (MSB-first) — the CPU reorders for you.
- **cout pointer vs raw bytes** — `cout << p` prints the real address (readable). Walking `(char*)&p` shows the little-endian bytes (reversed).

➡ Questions for this topic: `questions/master-question-sheet.md` (section 19).