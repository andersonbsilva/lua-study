INC=../lua-5.3.5/src
LIBDIR=../lua-5.3.5/src
SRC=ex1.c 
BIN=ex1

all: $(SRC)
	gcc -Wall -I$(INC) -llua $? -o $(BIN)

clean:
	rm -f *.o $(BIN)
