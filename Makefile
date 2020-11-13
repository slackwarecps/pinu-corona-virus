CC=gcc
CFLAGS=-g
EXECS=validacao

all: $(EXECS)

clean: 
	rm -f *.o $(EXECS)
	rm -rf *.dSYM