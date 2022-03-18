DIR = $(shell find -maxdepth 1 -type d | grep -oh [.][/][a-z,0-9]*$)

all:
	$(foreach var,$(DIR), cd $(var); make; cd ..;)

clean:
	$(foreach var,$(DIR), cd $(var); make clean; cd ..;)