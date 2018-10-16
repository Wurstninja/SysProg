CC=gcc
CFLAGS=-g -Wall
DEPS=
OBJECTS=a1.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

p: $(OBJECTS)
	gcc -o $@ $^ $(CFLAGS)

static_p: $(OBJECTS)
	gcc -o $@ $^ $(CFLAGS) -static

fresh: 
	gcc -c -o a1.o a1.c $(CFLAGS)
	gcc -o p a1.o $(CFLAGS)