#!/usr/bin/make -f

CFLAGS=-Wall -ansi -pedantic -g
LDFLAGS=
EXEC=decode encode
BIN_ENCODE=bin/main_encode.o bin/utils.o
SRC_ENCODE=main_encode.c utils.c

BIN_DECODE=bin/main_decode.o bin/utils.o
SRC_DECODE=main_decode.c utils.c
HEAD=decode.h

BINS=$(sort $(BIN_DECODE) $(BIN_ENCODE))

all: $(EXEC)

decode: $(BIN_DECODE)
	$(CC) -o bin/$@ $(BIN_DECODE) $(LDFLAGS)

encode:  $(BIN_ENCODE)
	$(CC) -o bin/$@ $(BIN_ENCODE) $(LDFLAGS)

$(BINS): bin/%.o: src/%.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(BINS) *~

clear: clean
	$(RM) $(EXEC) $(USER)_sokoban.tgz

bertrand_vigenere.tgz: clear
	mkdir -p $(USER)_sokoban
	cp Makefile *.c *.h *.sok $(USER)_sokoban
	tar czf $(USER)_sokoban.tgz $(USER)_sokoban
	rm -rf $(USER)_sokoban

.PHONY: all clean clear