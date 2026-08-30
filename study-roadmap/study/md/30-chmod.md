# 30 — chmod

*Category: Linux*

> Change permission bits, numeric or symbolic.

## Must-remember points

- Numeric mode sets all three triplets at once: `chmod 755 f` (rwx/r-x/r-x), `chmod 644 f` (rw-/r--/r--).
- Symbolic mode nudges bits: `chmod +x f` (x for all), `chmod u+x f` (owner only); u=owner, g=group, o=others, a=all.
- Missing **x** = 'Permission denied' when running `./script.sh` or a fresh binary — the #1 cause.

## ⚠ Easily confused

- **numeric vs symbolic chmod** — Numeric (`755`) sets ALL bits at once. Symbolic (`u+x`) nudges specific bits without touching the rest.
- **chmod vs chown** — chmod changes the permission BITS; chown changes the OWNER/group. Different things.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 30).