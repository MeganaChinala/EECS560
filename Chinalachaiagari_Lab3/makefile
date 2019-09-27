DoubleHashing: main.o Executive.o Restaurant.o Hash.o
	g++ -std=c++11 -g -Wall main.o Executive.o Restaurant.o Hash.o -o DoubleHashing

main.o: main.cpp Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Restaurant.h Hash.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Restaurant.o: Restaurant.h Restaurant.cpp
	g++ -std=c++11 -g -Wall -c Restaurant.cpp

Hash.o: Hash.h Hash.cpp
	g++ -std=c++11 -g -Wall -c Hash.cpp

clean:
	rm *.o DoubleHashing
