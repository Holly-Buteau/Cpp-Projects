CXX = creatureMain.cpp
CXX += Creature.cpp
CXX += Vampire.cpp
CXX += Medusa.cpp
CXX += Barbarian.cpp
CXX += HarryPotter.cpp
CXX += BlueMen.cpp
CXX += Creature.hpp
CXX += Vampire.hpp
CXX += Medusa.hpp
CXX += Barbarian.hpp
CXX += HarryPotter.hpp
CXX += BlueMen.hpp
CXX += creatureQueue.cpp
CXX += creatureQueue.hpp

creautreMain: Creature.o Vampire.o Barbarian.o Medusa.o HarryPotter.o BlueMen.o creatureQueue.o creatureMain.o
	g++ Creature.o Vampire.o Barbarian.o Medusa.o HarryPotter.o BlueMen.o creatureQueue.o creatureMain.o -o creatureMain

Creature.o: Creature.cpp Creature.hpp
	g++ -c Creature.cpp

creatureQueue.o: creatureQueue.cpp creatureQueue.hpp
	g++ -c creatureQueue.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

creatureMain.o: creatureMain.cpp
	g++ -c creatureMain.cpp

default:
	g++ -std=c++0x ${CXX} -o prog

clean:
	rm *.o creatureMain 






