CXX = Stack.cpp
CXX += Queue.cpp
CXX += sqMain.cpp
CXX += Stack.hpp
CXX += Queue.hpp
CXX += QueueNode.hpp


sqMain: Stack.o Queue.o sqMain.o
	g++ Stack.o Queue.o sqMain.o -o sqMain

Stack.o: Stack.cpp Stack.hpp
	g++ -c Stack.cpp

Queue.o: Queue.cpp Queue.hpp QueueNode.hpp
	g++ -c Queue.cpp

sqMain.o: sqMain.cpp
	g++ -c sqMain.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o sqMain 




