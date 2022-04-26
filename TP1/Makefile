GCC = gcc
FLAGS = -Wall -ansi -lm

BIN = bin
SRC = src
PROG = $(BIN)/$@
OBJS = $(BIN)/$@.o
NUMBERS = $(shell find src/*.c | grep -oh ^[a-z,/,0-9]* | cut -d "/" -f2)

all:
	echo $(NUMBERS)
	$(foreach var,$(NUMBERS), $(GCC) $(FLAGS) $(SRC)/$(var).c -o bin/$(var);)

clean:
	rm -f ./$(BIN)/*
