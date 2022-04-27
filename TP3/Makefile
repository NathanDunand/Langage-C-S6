GCC = gcc
FLAGS = -Wall -ansi -std=c99

BIN = bin
SRC = src

MKDIR = mkdir -p

PROG = $(BIN)/$@
OBJS = $(BIN)/$@.o
NUMBERS = $(shell find src/*.c | grep -oh ^[a-z,/,0-9,\-]* | cut -d "/" -f2-)

all:
	$(foreach var,$(NUMBERS), $(GCC) $(FLAGS) $(SRC)/$(var).c -o $(BIN)/$(var) -lm;)

clean:
	rm -f ./$(BIN)/*
