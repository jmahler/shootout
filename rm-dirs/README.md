
NAME
----

rm-dirs - remove all directories except the n newest

PROBLEM
-------

From a directory full of a large number of directories (32k or more)
remove all the directories matching a pattern except the n newest.

SOLUTION
--------

Delete all files with the pattern 'test-*' except for the 2 newest.

    $ ls -t | grep 'test-*' | tail -n+3 | xargs rm -fr

To test this example, the following can be used to generate a
large number of directories with a file inside.

    #!/bin/bash
    
    for n in $(seq 1 32001); do
    	mkdir "test-$n" &&
    	echo "HELLO" > "test-$n/HELLO"
    done

To count the number of files in the directory use `wc`.

    $ ls | wc -l

Systems using the ext3 file system will have a limit of 32000 if this
directory is under a symbolic link.  Systems using ext4 have no such
limit.
