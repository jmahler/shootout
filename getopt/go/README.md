
NAME
----

getopt - Get command line arguments in Go

DESCRIPTION
-----------

This example shows how to parse command line arguments (getopt) in Go.

It is assumed that you are using a typical Golang develop environment
and that your $GOPATH is setup.  If not, refer to the shootout/hello/go
example.

    $ cd $GOPATH/src
    $ git clone https://github.com/pborman/getopt.git github.com/pborman/getopt

    $ cd ~/shootout/getopt/go
    $ go install getopt_go.go

    $ getopt_go -k mykey -f
    flag = true
     key = 'mykey'
    $ getopt_go
    flag = false
     key = ''
    $ 

REFERENCES
----------

  [1] [github.com/pborman/getopt][1]
  [1]: https://github.com/pborman/getopt
