.DEFAULT_GOAL := compile

###   CHANGE   ###
LIBS :=
NAME := rand_mat
DIR := #build/
CC  := gcc
CFLAGS := -g -W
### END CHANGE ###

SRC = $(wildcard *.c) # careful with test.c etc
DEPS := $(wildcard *.h)
OBJECTS :=$(patsubst %.c,$(DIR)%.o,$(wildcard *.c))

dir_exists: | $(DIR)
	@echo 

$(DIR)%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $(DIR)$@ $^ $(CFLAGS)

clean: 
	@echo $(shell rm $(DIR)$(NAME) $(OBJECTS))
	@echo $(shell rm -r -f $(DIR))

run:
	$(shell make dir_exists)
	@echo $(shell make $(NAME))
	./$(DIR)$(NAME)

v:
	@echo $(shell make $(NAME))
	@echo $(shell valgrind ./$(DIR)$(NAME))

compile:
	@echo $(shell make $(NAME))

$(DIR):
	mkdir -p $@
