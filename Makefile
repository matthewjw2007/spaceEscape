spaceadv: main.o menu.o Alien.o CaptQuarters.o Game.o CargoHold.o Inventory.o Character.o DockingBay.o EngineRoom.o Space.o Kitchen.o MainDeck.o Player.o
	g++ -g -Wall -std=c++11 main.o menu.o Alien.o CaptQuarters.o Game.o CargoHold.o Inventory.o Character.o DockingBay.o EngineRoom.o Space.o Kitchen.o MainDeck.o Player.o -o spaceadv

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

menu.o: menu.cpp menu.h
	g++ -c -std=c++11 menu.cpp

Alien.o: Alien.cpp Alien.h
	g++ -c -std=c++11 Alien.cpp

CaptQuarters.o: CaptQuarters.cpp CaptQuarters.h
	g++ -c -std=c++11 CaptQuarters.cpp

Game.o: Game.cpp Game.h
	g++ -c -std=c++11 Game.cpp

CargoHold.o: CargoHold.cpp CargoHold.h
	g++ -c -std=c++11 CargoHold.cpp

Inventory.o: Inventory.cpp Inventory.h
	g++ -c -std=c++11 Inventory.cpp

Character.o: Character.cpp Character.h
	g++ -c -std=c++11 Character.cpp

DockingBay.o: DockingBay.cpp DockingBay.h
	g++ -c -std=c++11 DockingBay.cpp

EngineRoom.o: EngineRoom.cpp EngineRoom.h
	g++ -c -std=c++11 EngineRoom.cpp

Space.o: Space.cpp Space.h
	g++ -c -std=c++11 Space.cpp

Kitchen.o: Kitchen.cpp Kitchen.h
	g++ -c -std=c++11 Kitchen.cpp

MainDeck.o: MainDeck.cpp MainDeck.h
	g++ -c -std=c++11 MainDeck.cpp

Player.o: Player.cpp Player.h
	g++ -c -std=c++11 Player.cpp

clean:
	rm *.o spaceadv
