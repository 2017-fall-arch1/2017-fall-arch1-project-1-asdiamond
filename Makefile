all: bstdemo.exe

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites
#General format
#target: dependencies
#	bash command

bstdemo.exe: bst.o bstdemo.o
	cc -o $@ $^

bst.o: bst.c bst.h bstdemo.h
	cc -c $(CFLAGS) bst.c

bstdemo.o: bstdemo.c bstdemo.h bst.h
	cc -c $(CFLAGS) bstdemo.c

clean:
	rm -f *.o bstdemo.exe
	rm -f *.out

demo: bstdemo.exe
	(echo first; echo "second line"; echo "third and last") | ./bstdemo.exe

