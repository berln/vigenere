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

tgz: clear
	mkdir -p lanoeb_durans
	cp makefile lanoeb_durans
	cp -r bin lanoeb_durans
	cp -r src lanoeb_durans
	cp -r test lanoeb_durans
	tar czf lanoeb_durans.tgz lanoeb_durans
	rm -rf lanoeb_durans

.PHONY: all clean clear