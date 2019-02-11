# compiler
CC = gcc
CFLAGS = -Wall -O3

# dependencies
HEADERS = lu_dcmp.h

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -I.

example: lu_dcmp.o lu_example.o
	$(CC) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o example
