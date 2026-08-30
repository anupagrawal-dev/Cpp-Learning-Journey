# 29 — Permissions (rwx)

*Category: Linux*

> Read the 10-char mode; r=4 w=2 x=1.

## Must-remember points

- `ls -l` line: 10 chars = 1 file-type (`-` file, `d` dir, `l` symlink) + three `rwx` triplets for owner / group / others.
- r=4, w=2, x=1; add per triplet → numeric modes like 755 (rwxr-xr-x), 644 (rw-r--r--).
- A binary needs the **x** bit to run with `./`; a source `.cpp` is usually 644 (no x), a compiled binary 755.

## ⚠ Easily confused

- **owner vs group vs others** — Three separate rwx triplets: the file's owner, its group, everyone else. The kernel picks which triplet applies from your UID/GID.
- **r/w/x on a file vs a directory** — On a directory, `x` = can enter/traverse, `r` = can list names, `w` = can add/remove entries — different from files.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 29).