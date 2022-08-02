all: a

a: main.o class.o
	wg++ -o a.exe main.o class.o 

main.o: main.cpp
	wg++ -c main.cpp

class.o: class.cpp
	wg++ -c class.cpp

