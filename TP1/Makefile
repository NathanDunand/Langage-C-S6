GCC = gcc
FLAGS = -Wall -ansi

BIN = bin
SRC = src
PROG = $(BIN)/$@
OBJS = $(BIN)/$@.o
NUMBERS = $(shell ls src/ -1 | sed 's/\.[^.]*$\//')

all:
	$(foreach var,$(NUMBERS),$(GCC) -c $(FLAGS) $(SRC)/$(var).c -o bin/$(var);)

clean:
	rm -f ./$(BIN)/*