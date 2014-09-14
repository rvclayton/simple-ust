CC	= gcc
CFLAGS	= -g -Wall -pedantic -ansi

objs	= ex.o td.o ust.o
ex	: $(objs)
	  $(CC) -o $@ $(CFLAGS) $(objs)

clean	:
	  crm ; rm -f *.o ex

depends	:
	  $(CC) -MM $(iflags) *.c | \
	  sed "s;$$HOME;$$\(HOME);g" > dependencies

include	dependencies
