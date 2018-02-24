execute: lab21_unit_test.o template.o
	g++ -Wall -g -o execute template.o lab21_unit_test.o

lab21test_program.o: lab21_unit_test.cpp
	g++ -Wall -g -c lab21_unit_test.cpp

template.o: template.cpp
	g++ -Wall -g -c template.cpp

clean:
	rm *.o *test