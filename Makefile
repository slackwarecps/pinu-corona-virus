CC=gcc
CFLAGS=-g
EXECS=menu arquivo novo login teste

all: $(EXECS)

clean: 
	rm -f *.o $(EXECS)
	rm -rf *.dSYM