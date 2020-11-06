CC=gcc
CFLAGS=-g
EXECS=menu

all: $(EXECS)

clean: 
	rm -f *.o $(EXECS)
	rm -rf *.dSYM