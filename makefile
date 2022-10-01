#------------------------------------------
#	author	: SniehNikita
#	github	: https://github.com/SniehNikita
#	date	: 01.10.2022
#	
#	!!! Built and tested in Linux !!!
#
#------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra --std=c11
EXEC = lib_htab test-dynamic test-static

# List all obj files to include into library
HTAB_OBJS = htab.o



all: clear $(EXEC)

# Creates dynamic and static libs
lib_htab: $(HTAB_OBJS)
	ar rsc lib_htab.a $^
	$(CC)  $(CFLAGS) -fPIC -shared $^ -o lib_htab.so

test-static:
	$(CC) $(CFLAGS) -L. lib_htab.a test.c -o $@

test-dynamic:
	$(CC) $(CFLAGS) -L. lib_htab.so test.c -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clear:
	rm -f *.o
	rm -f test-static
	rm -f test-dynamic
	rm -f lib_htab.so
	rm -f lib_htab.a