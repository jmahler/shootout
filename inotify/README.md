
NAME
----

inotify - Monitor file/directory changes using Inotify.

DESCRIPTION
-----------

This program watches a file or directory using inotify(7)
and displays everything that is occurring.

The following examples shows the output after Vim wrote
to watch.c.

    ~/shootout/inotify/c$ ./watch .
    ---
    1: 4913
    IN_CREATE
    2: 4913
    IN_OPEN
    ---
    1: 4913
    IN_ATTRIB
    2: 4913
    IN_CLOSE_WRITE
    IN_CLOSE
    3: 4913
    IN_DELETE
    4: watch.c
    IN_MOVED_FROM
    IN_MOVE
    5: watch.c~
    IN_MOVED_TO
    IN_MOVE
    ---
    1: watch.c
    IN_CREATE
    2: watch.c
    IN_OPEN
    ---
    1: watch.c
    IN_MODIFY
    ---
    1: watch.c
    IN_CLOSE_WRITE
    IN_CLOSE
    2: watch.c
    IN_ATTRIB
    ---
    1: watch.c~
    IN_DELETE
    ---
    1: .watch.c.swp
    IN_MODIFY

As another example, the file itself can be watched.

    ~/shootout/inotify/c$ ./watch watch.c

With Vim, the output may not be what you expect.

AUTHOR
------

Jeremiah Mahler <jmmahler@gmail.com>
http://github.com/jmahler

COPYRIGHT
--------

Copyright (c) 2014, Jeremiah Mahler. All Rights Reserved.
This project is free software and released under the
GNU General Public License.

