CC = gcc
CFLAGS=-I.
DEPS=myCrypto.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cipherFind: cipherFind.o myCrypto.o
	${CC} -o cipherFind cipherFind.o myCrypto.o
