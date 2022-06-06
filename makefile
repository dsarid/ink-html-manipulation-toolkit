CC = gcc

html-builder: html-bld.o html-lib.o
	cc html-bld.o html-lib.o -o html-builder

html-bld.o: html-builder.c
	cc -c html-builder.c -o html-bld.o

html-lib.o: ink-hmtk.c
	cc -c ink-hmtk.c -o html-lib.o

clean:
	rm $(wildcard *.o)

