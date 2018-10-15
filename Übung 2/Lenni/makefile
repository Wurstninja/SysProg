.DEFAULT_GOAL := p
CC=gcc
CFLAGS=-g -Wall

genlist: genlist.c 
	$(CC) -c genlist.c $(CCFLAGS)

p: genlist.o main.c
	$(CC) -o p main.c genlist.o $(CFLAGS)

clean: 
	rm p *.o

run:
	@echo $(shell make)
	$(shell export PATH=$PATH:)
	@echo $(shell p)