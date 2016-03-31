CXX = finalMain.cpp
CXX += Space.cpp
CXX += Bedroom.cpp
CXX += Bathroom.cpp
CXX += Attic.cpp
CXX += Kitchen.cpp
CXX += LivingRoom.cpp
CXX += Space.hpp
CXX += Bedroom.hpp
CXX += Bathroom.hpp
CXX += Attic.hpp
CXX += Kitchen.hpp
CXX += LivingRoom.hpp
CXX += Item.cpp
CXX += Item.hpp
CXX += Player.cpp
CXX += Player.hpp

finalMain: Space.o Bedroom.o Bathroom.o Attic.o Kitchen.o LivingRoom.o Item.o Player.o finalMain.o
	g++ Space.o Bedroom.o Bathroom.o Attic.o Kitchen.o LivingRoom.o Item.o Player.o finalMain.o -o finalMain

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

Bedroom.o: Bedroom.cpp Bedroom.hpp
	g++ -c Bedroom.cpp

Bathroom.o: Bathroom.cpp Bathroom.hpp
	g++ -c Bathroom.cpp

Attic.o: Attic.cpp Attic.hpp
	g++ -c Attic.cpp

Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -c Kitchen.cpp

LivingRoom.o: LivingRoom.cpp LivingRoom.hpp
	g++ -c LivingRoom.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

finalMain.o: finalMain.cpp
	g++ -c finalMain.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o finalMain 







