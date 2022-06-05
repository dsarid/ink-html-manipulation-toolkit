CC = gcc

html-builder: html-bld.o
	cc html-bld.o -o html-builder

html-bld.o: html-builder.c
	cc -c html-builder.c -o html-bld.o

clean:
	rm $(wildcard *.o)

