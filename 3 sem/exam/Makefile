all: a

a: m.o in.o f.o
	gcc -o a.exe m.o in.o f.o

m.o: m.c
	gcc -c -g m.c

in.o: in.c
	gcc -c -g in.c

f.o: f.c
	gcc -c -g f.c

