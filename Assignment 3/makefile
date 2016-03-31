CXX = Item.cpp
CXX += List.cpp
CXX += Item.hpp
CXX += List.hpp
CXX += listMain.cpp

listMain: Item.o List.o listMain.o
	g++ List.o Item.o listMain.o -o listMain

List.o: List.cpp List.hpp
	g++ -c List.cpp


Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

listMain.o: listMain.cpp
	g++ -c listMain.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o listMain 

