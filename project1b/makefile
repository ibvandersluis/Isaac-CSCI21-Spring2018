execute: functions.o main.o
	g++ -Wall -g -o execute functions.o main.o

main: main.cpp
	g++ -Wall -g -c main.cpp

functions: functions.cpp
	g++ -Wall -g -c functions.cpp	

clean:
	rm *.o *test