CC=gcc
CFLAGS= -g -O0 -I .
DEPS = def.h game.h board.h piece.h
OBJ = test.o game.o board.o piece.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chess: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
