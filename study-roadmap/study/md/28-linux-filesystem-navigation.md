# 28 — Filesystem & Navigation

*Category: Linux*

> One tree from /, absolute vs relative paths.

## Must-remember points

- Single tree rooted at `/`; no drive letters. Absolute path starts at `/`; relative path starts from the current directory. `.` = here, `..` = parent.
- Relative paths in code (`open("config.txt")`) resolve against the process's **working directory** — a common 'file not found' bug.
- Commands: `pwd` (where am I), `ls -la` (list, long, all), `cd ..` (up one).

## ⚠ Easily confused

- **absolute vs relative path** — Absolute starts at `/` (same everywhere). Relative starts from the current working directory (depends where you run it).
- **. vs ..** — `.` = the current directory. `..` = the parent directory.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 28).