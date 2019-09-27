OpenHashing: main.o LinkedList.o Node.o Executive.o HashTable.o
	g++ -std=c++11 main.o LinkedList.o Node.o Executive.o HashTable.o -o OpenHashing
main.o: main.cpp LinkedList.h Node.h
	g++ -std=c++11 -c main.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -std=c++11 -c LinkedList.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -c Executive.cpp
HashTable.o: HashTable.cpp HashTable.h
	g++ -std=c++11 -c HashTable.cpp
clean:
	rm *.o OpenHashing
