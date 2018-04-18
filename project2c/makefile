execute: queue.o stack.o node.o main.o
	g++ -Wall -std=c++11 -g -o execute queue.o stack.o node.o main.o

queue.o: queue.cpp
	g++ -Wall -std=c++11 -g -c queue.cpp

stack.o: stack.cpp
	g++ -Wall -std=c++11 -g -c stack.cpp

node.o: node.cpp
	g++ -Wall -std=c++11 -g -c node.cpp	
	
main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

clean:
	rm *.o *test