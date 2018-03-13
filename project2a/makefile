execute: Proj1Aux.o main.o
	g++ -Wall -std=c++11 -g -o execute Proj1Aux.o main.o

main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

Proj1Aux.o: Proj1Aux.cpp
	g++ -Wall -std=c++11 -g -c Proj1Aux.cpp	

clean:
	rm *.o *test