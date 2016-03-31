CXX = lab4.cpp
CXX += lab4Main.cpp
CXX += lab4.hpp

lab4Main: lab4.o lab4Main.o
	g++ lab4.o lab4Main.o -o lab4Main

lab4.o: lab4.cpp lab4.hpp
	g++ -c lab4.cpp

lab4Main.o: lab4Main.cpp
	g++ -c lab4Main.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o lab4Main 

