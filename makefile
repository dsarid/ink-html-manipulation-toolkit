CC = gcc

html-builder: main.o html-lib.o
	cc main.o html-lib.o -o html-builder

html-bld.o: src/main.c
	cc -c src/main.c -o main.o

html-lib.o: src/ink-html.c
	cc -c src/ink-html.c -o html-lib.o

clean:
	rm $(wildcard *.o)
