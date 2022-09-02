CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -ansi
BIN=bin/
INCLUDE=include

l: example/l.c src/sgr.c
	$(CC) $^ -o $(BIN)$@ $(CFLAGS) -I$(INCLUDE)

hello: example/hello.c src/sgr.c
	$(CC) $^ -o $(BIN)$@ $(CFLAGS) -I$(INCLUDE)

.PHONY: makebin
makebin:
	@mkdir bin