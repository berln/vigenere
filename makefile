CFLAGS=-Wall -ansi -pedantic -g
LDFLAGS=
EXEC=decode encode
BIN_ENCODE=main_encode.o utils.o
SRC_ENCODE=main_encode.c utils.c

BIN_DECODE=main_decode.o utils.o
SRC_DECODE=main_decode.c utils.c
HEAD=decode.h

all: $(EXEC)

decode: $(BIN_DECODE)
	$(CC) -o $@ $(BIN_DECODE) $(LDFLAGS)

encode:  $(BIN_ENCODE)
	$(CC) -o $@ $(BIN_ENCODE) $(LDFLAGS)

%.o: %.c $(HEAD)
	$(CC) -c $< $(CFLAGS)

clean:
	$(RM) *.o *~

clear: clean
	$(RM) $(EXEC) $(USER)_sokoban.tgz

bertrand_vigenere.tgz: clear
	mkdir -p $(USER)_sokoban
	cp Makefile *.c *.h *.sok $(USER)_sokoban
	tar czf $(USER)_sokoban.tgz $(USER)_sokoban
	rm -rf $(USER)_sokoban

.PHONY: all clean clear