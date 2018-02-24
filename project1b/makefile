execute: creditcard.o main.o
	g++ -Wall -std=c++11 -g -o execute creditcard.o main.o

main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

creditcard.o: creditcard.cpp
	g++ -Wall -std=c++11 -g -c creditcard.cpp	

clean:
	rm *.o *test