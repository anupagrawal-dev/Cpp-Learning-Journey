# Anup — Linux Learning Progress (for C++ / Linux backend roles)

The evening coach reads this every run and teaches a SMALL part of the current Linux topic
(one concept + one hands-on command/exercise), then advances the pointer as Anup progresses.
Focus is Linux as it matters for C/C++ systems, backend, and low-latency roles.

## Current status
- Current topic: **1 — Filesystem, navigation & permissions** (essentially complete after chown hands-on)
- Sub-part next: **Topic 2 — Processes & signals** (ps, top/htop, kill, signals, /proc/<pid>). chown/chgrp taught 2026-08-01; hands-on (root-requirement demo) pending Anup's report.
- Last session date: 2026-08-01 (Anup engaged chown — strong on owner:group, `user:group` syntax, -R; taught the missing root-requirement rule + id/whoami + C/C++ systems relevance)
- Covered so far in topic 1: navigation (pwd, ls -la, cd, absolute vs relative paths, . and ..); permission string reading (-rwxr-xr-x, file-type char, r=4/w=2/x=1, 755/644, why binaries need x bit); chmod numeric + symbolic; chown/chgrp (ownership, only root can give a file away, chgrp for group, id/whoami)

## Syllabus (progressive — go in order, spend multiple days per topic if needed)
1. Filesystem, navigation & permissions (ls, cd, paths, chmod/chown, rwx)
2. Processes & signals (ps, top/htop, kill, signals, /proc/<pid>)
3. File I/O & file descriptors (fd 0/1/2, redirection, pipes `|`, `>`, `<`)
4. Users, groups & ownership; sudo
5. Shell scripting basics (variables, loops, conditionals, exit codes)
6. Text tools for engineers (grep, sed, awk, find, xargs)
7. Virtual memory & how a process is laid out (stack/heap/text, mmap, /proc/<pid>/maps)
8. System calls & tracing (strace, ltrace, common syscalls: read/write/open/close)
9. Processes vs threads; fork/exec/wait; zombies & orphans
10. IPC (pipes, FIFOs, shared memory, message queues, sockets overview)
11. Sockets & TCP/IP basics (socket/bind/listen/accept/connect)
12. I/O multiplexing — select/poll/**epoll** (key for low-latency servers)
13. Networking tools (ss/netstat, tcpdump, lsof, nc)
14. Debugging C++ on Linux (gdb, core dumps, valgrind, AddressSanitizer)
15. Performance & profiling (perf, /proc/stat, time, htop, latency basics)
16. Linking & libraries (static vs dynamic, ldd, LD_LIBRARY_PATH, rpath)
17. Build & deploy (make/CMake, systemd services, cron)

## Completed topics log
| Topic | Key thing learned | Hands-on done |
|-------|-------------------|:---:|
| (none yet) | | |

## Notes / weak spots to revisit
- (none yet)
