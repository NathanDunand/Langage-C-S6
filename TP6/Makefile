DIR = $(shell find -type d -maxdepth 1 | grep -oh ^[.,/,a-z,0-9]*)

all:
	@echo $(DIR)
	$(foreach var,$(DIR) cd $(var);)