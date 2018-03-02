execute: functions.o main.o
	g++ -Wall -std=c++11 -g -o execute functions.o main.o

main: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

functions: functions.cpp
	g++ -Wall -std=c++11 -g -c functions.cpp	

clean:
	rm *.o *test