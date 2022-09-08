CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -ansi
BIN=bin/
INCLUDE=include

all: l hello

l: example/l.c src/sgr.c
	$(CC) $^ -o $(BIN)$@ $(CFLAGS) -I$(INCLUDE)

hello: example/hello.c src/sgr.c
	$(CC) $^ -o $(BIN)$@ $(CFLAGS) -I$(INCLUDE)

.PHONY: makebin all
makebin:
	@mkdir bin