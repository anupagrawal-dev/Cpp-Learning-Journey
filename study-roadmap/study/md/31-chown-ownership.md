# 31 — chown & Ownership

*Category: Linux*

> Change owner/group; only root can give a file away.

## Must-remember points

- `chown user file`, `chown user:group file`, `chown :group file` (group only); `-R` = recursive. `chgrp group file` changes only the group.
- **Only root (sudo) can change a file's owner** — a regular user can't give their file away or take another's. The owner CAN change the group to one they belong to.
- Ownership + rwx triplets together gate access: a process's UID/GID is checked against owner/group/other bits on every open/read/write.
- `id` = your UID/GID/groups; `whoami` = your username.
- Systems relevance: deploying a service = chown binary/data to a service user; setuid / privilege-dropping daemons rely on ownership.

## ⚠ Easily confused

- **chown vs chgrp** — chown changes owner (and optionally group); chgrp changes only the group.
- **id vs whoami** — `id` shows your UID/GID and all groups; `whoami` shows just your username.

➡ Questions for this topic: `questions/master-question-sheet.md` (section 31).