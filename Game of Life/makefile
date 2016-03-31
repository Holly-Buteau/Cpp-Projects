CXX = gameOfLife.cpp
CXX += lifeMain.cpp
CXX += gameOfLife.hpp

lifeMain: gameOfLife.o lifeMain.o
	g++ gameOfLife.o lifeMain.o -o lifeMain

gameOfLife.o: gameOfLife.cpp gameOfLife.hpp
	g++ -c gameOfLife.cpp


lifeMain.o: lifeMain.cpp
	g++ -c lifeMain.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o lifeMain 

