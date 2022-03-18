GCC = gcc
FLAGS = -Wall -ansi

BIN = bin
SRC = src
PROG = $(BIN)/$@
OBJS = $(BIN)/$@.o
NUMBERS = $(shell find src/*.c | grep -oh ^[a-z,/,0-9]* | cut -d "/" -f2)

all:
	$(foreach var,$(NUMBERS),$(GCC) $(FLAGS) $(SRC)/$(var).c -o bin/$(var) -lm;)

clean:
	rm -f ./$(BIN)/*