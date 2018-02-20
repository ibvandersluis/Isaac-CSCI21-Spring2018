execute: lab12_unit_test.o item.o food_item.o magic_item.o
	g++ -Wall -g -o execute magic_item.o food_item.o item.o lab12_unit_test.o

lab12_unit_test.o: lab12_unit_test.cpp
	g++ -Wall -g -c lab12_unit_test.cpp

item.o: item.cpp
	g++ -Wall -g -c item.cpp

food_item.o: food_item.cpp
	g++ -Wall -g -c food_item.cpp
	
magic_item.o: magic_item.cpp
	g++ -Wall -g -c magic_item.cpp

clean:
	rm *.o *test