
NAME
----

flock - file locking

DESCRIPTION
-----------

To test file locking a simple user program that performs the
following steps has been constructed.

 1. acquire the lock and open the file, else wait and try again
 1. keep the lock held until the user enters data
 1. write the data, release the lock and quit

The example can be tested by running it from two terminals.
The first opens the file and acquires the lock.
The seconds tries, but has to wait for the first to release
the lock first.
And since these examples are provided for various languages their
interoperability can be checked as well.

The following is a usage example.

    (terminal 1)
    $ ./flock tmp.txt
    acquiring lock...done
    Enter data:
    
    (terminal 2)
    $ ./flock tmp.txt
    acquiring lock...

Notice that terminal 1 got the lock but terminal 2 is blocked.

    (terminal 1)
    $ ./flock tmp.txt
    acquiring lock...done
    Enter data: one
    releasing lock...done
    $
    
    (terminal 2)
    $ ./flock tmp.txt
    acquiring lock...done
    Enter data: two
    releasing lock...done
    $

And the file has the data from the second write.

    $ cat tmp.txt
    two

