execute: Proj1Aux.o main.o
	g++ -Wall -std=c++11 -g -o execute Proj1Aux.o main.o

Proj1Aux.o: Proj1Aux.cpp
	g++ -Wall -std=c++11 -g -c Proj1Aux.cpp	
	
main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

clean:
	rm *.o *test