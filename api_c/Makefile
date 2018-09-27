INC=../lua-5.3.5/src
LIBDIR=../lua-5.3.5/src
SRC=ex1.c 
BIN=ex1 repl

all: ex1 repl

repl: repl.c
	gcc -Wall -I$(INC) -o repl repl.c -llua -lm -ldl

ex1: ex1.c
	gcc -Wall -I$(INC) -llua $? -o $(BIN)

clean:
	rm -f *.o $(BIN)
