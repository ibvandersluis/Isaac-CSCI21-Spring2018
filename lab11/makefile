execute: lab11_unit_test.o money.o
	g++ -Wall -g -o execute money.o lab11_unit_test.o

lab11test_program: lab11_unit_test.cpp
	g++ -Wall -g -c lab11_unit_test.cpp

money: money.cpp
	g++ -Wall -g -c money.cpp

clean:
	rm *.o *test