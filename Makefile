CC := gcc

CFLAGS := -pedantic-errors -Wall -Werror -Wextra -std=c11

DIRS := src/

SRCS := $(shell find $(DIRS) -name '*.c')

LFLAGS := -lSDL2main -lSDL2

BIN := snake

all: CFLAGS +=-O2
all: release

debug: CFLAGS +=-O0 -ggdb
debug: release

release:
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN) $(LFLAGS)

clean:
	$(RM) $(BIN)
