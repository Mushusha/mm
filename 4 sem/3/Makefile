all: a

a: main.o class.o
	wg++ -fopenmp -o a.exe main.o class.o 

main.o: main.cpp
	wg++ -fopenmp -c main.cpp

class.o: class.cpp
	wg++ - fopenmp -c class.cpp

