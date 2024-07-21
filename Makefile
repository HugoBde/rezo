CC      = gcc
CFLAGS  = -g
INCLUDE = -Iinclude

SRC = $(wildcard src/*.c)

OBJS = $(patsubst src/%.c,build/%.o,$(SRC))

BIN = build/main

run: $(BIN)
	$(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) 

build/%.o: src/%.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(INCLUDE)

clean:
	rm build/*
