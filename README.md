Simple-ust is a simple user-space thread library.  It is intended to illustrate
the ideas behind implementing a user-space thread library on Unix-like systems;
it is not intended to be a practical thread library.

## Files

* `ex.c` - An example program using simple-ust.

* `ust.*` - The user-space thread library.

* `td.*` - The thread-descriptor implementation.

* `makefile` - build the example.

## To use

Type

		touch dependencies ; make depends ; make

to build the library and example, then type

		./ex

to run the example.  The output should look like

		$ ./ex
		Go!
		white.
		blue.
		red.

		$

## Requirements

I dunno.  It runs on Debian testing and FreeBSD 10 and assumes the GNU tool
chain, a C compiler in particular.

If you want a copy of this file as html, you should install a markdown
processor.

## References

Chapters 4 (Exceptions and Assertions) and 20 (Threads) in
[<i>C Interfaces and Implementations</i>](https://openlibrary.org/books/OL990468M/C_interfaces_and_implementations)
by David Hanson, Addison-Wesley, 1997.


