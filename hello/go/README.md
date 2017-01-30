
NAME
----

hello - Hello, World in Go

DESCRIPTION
-----------

The first way to build this program, since it is just a single
file, it to use go build.

    $ go build hello.go
    $ ./hello 
    Hello, World!

The second way is to follow the Go convention by using a Workspace [[1]].

First, a workspace with the proper env variables must be defined.

    $ go env
    ...
    GOBIN="/home/jeri/go/bin"
    GOPATH="/home/jeri/go"
    ...

If $GOPATH is added to your $PATH, binaries can be easily executed.

    $ export PATH=$PATH:$GOBIN

Get the shootout project in to the src directory either through links
or by placing it there directly.

    go/
      bin/
      src/
        shootout/hello/go/hello.go

To build and install run 'go install'.

    $ go install shootout/hello/go/hello.go

This can be run from any location when given the full path
relative to the src/ directory.  If you are in the source
directory itself you can use the local file name.

    $ pwd
    /home/jeri/shootout/hello/go
    $ go install hello.go 

Once this is done, and if $PATH includes $GOBIN, it can be
run from anywhere.

    $ hello
    Hello, World

Or it can be run directly.

    $ ./go/bin/hello 
    Hello, World!

The complexity of a workspace can appear to be a burden for a simple
example such as this.  The benefit will become more apparent with
larger projects which depend on other projects.

REFERENCES
----------

  [1] [Golang Workspaces][1]
  [1]: https://golang.org/doc/code.html#Workspaces
