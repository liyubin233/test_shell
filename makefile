CC = gcc
CFLAGS = -Ilib -g -O2 -D_REENTRANT -Wall
LIBS = ./libunp.a -lpthread

PROGS = myshell 

all:    ${PROGS}

myshell:myshell.o 
	${CC} ${CFLAGS} -o $@ myshell.o ${LIBS}

clean:
	rm -rf  *.o *.lc
clean_app:
	rm -rf $(PROGS)
