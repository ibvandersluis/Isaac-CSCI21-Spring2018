execute.o: lab07_unit_test.o lab07.o
	g++ -Wall -g -o execute lab07.o lab07_unit_test.o

lab07test_program.o: lab07_unit_test.cpp
	g++ -Wall -g -c lab07_unit_test.cpp

lab07.0: lab07.cpp
	g++ -Wall -g -c lab07.cpp	

clean:
	rm *.o *test