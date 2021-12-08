CC = gcc

OBJS = src/*.c

COMPILER_FLAGS = -pedantic-errors \
				-Wall \
				-Werror \

LINKER_FLAGS = -lSDL2main \
				-lSDL2 \

OBJ_NAME = snake

all:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
