Doubly: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Doubly

main.o: main.cpp Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

run:
	./Doubly

clean:
	rm *.o Doubly
