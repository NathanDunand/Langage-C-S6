GCC = gcc
FLAGS = -Wall -ansi -std=c99 -c
# -c pour pouvoir ensuite faire le linking

BIN = bin
SRC = src

MKDIR = mkdir -p

PROG = $(BIN)/$@
OBJS = $(BIN)/$@.o
NUMBERS = $(shell find src/*/*.c | grep -oh ^[a-z,/,0-9,\-]* | cut -d "/" -f2-)
FOLDERS = $(shell find src/*/*.c | grep -oh ^[a-z,/,0-9,\-]* | rev | cut -d "/" -f2- | rev | cut -d "/" -f2-)

all: link
	@echo executing ...
	$(foreach var, $(shell find bin/*/*.o | grep -oh ^[a-z,/,0-9,\-]* | rev | cut -d "/" -f2- | rev | cut -d "/" -f2-), cd $(BIN)/$(var) | ./$(BIN)/$(var)/main;)

link: compile
	@echo linking ...
	$(foreach var, $(shell find bin/*/*.o | grep -oh ^[a-z,/,0-9,\-]* | rev | cut -d "/" -f2- | rev | cut -d "/" -f2-), cd $(BIN)/$(var) | gcc $(BIN)/$(var)/*.o -o $(BIN)/$(var)/main;)

compile: clean
	@echo compiling ...
	$(foreach var,$(NUMBERS), $(GCC) $(FLAGS) $(SRC)/$(var).c -o $(BIN)/$(var).o -lm;)

clean:
	@echo cleaning ...
	rm -f ./$(BIN)/*/*
