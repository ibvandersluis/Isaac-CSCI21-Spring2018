execute: main.o tree.o node.o
	g++ -Wall -std=c++11 -g -o execute main.o tree.o node.o

main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp
	
tree.o: tree.cpp
	g++ -Wall -std=c++11 -g -c tree.cpp
	
node.o: node.cpp
	g++ -Wall -std=c++11 -g -c node.cpp

clean:
	rm *.o *test