CC = gcc

html-builder: main.o html-lib.o
	cc main.o html-lib.o -o html-builder

html-bld.o: main.c
	cc -c main.c -o main.o

html-lib.o: ink-html.c
	cc -c ink-html.c -o html-lib.o

clean:
	rm $(wildcard *.o)

