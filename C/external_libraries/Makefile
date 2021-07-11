CC = clang
CFLAGS = -Wall -Ilib/glad/include
LDFLAGS = lib/glad/src/glad.o -lglfw

SRC  = $(wildcard src/*.c)
OBJ  = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: libs main

libs:
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c

run: all
	$(BIN)/main

main: $(OBJ)
	$(CC) -o $(BIN)/main $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)