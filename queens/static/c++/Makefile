DEBUG=

solver: backtrack.o main.o
	g++ -Wall -pedantic -g -std=c++11 $(DEBUG) backtrack.o main.o -o solver

main.o:
	g++ -Wall -pedantic -g -std=c++11 $(DEBUG) -c main.cpp

backtrack.o:
	g++ -Wall -pedantic -g -std=c++11 $(DEBUG) -c backtrack.cpp

clean:
	rm -f *.o *.d solver
