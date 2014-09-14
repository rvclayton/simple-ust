CC	= gcc
CFLAGS	= -g -Wall -pedantic -ansi

ex	: ex.o td.o ust.o
	  $(CC) -o $@ $(CFLAGS) $^

clean	:
	  crm ; rm -f *.o ex

depends	:
	  $(CC) -MM $(iflags) *.c | \
	  sed "s;$$HOME;$$\(HOME);g" > dependencies

include	dependencies
