final: go_fish.o card.o deck.o player.o
	g++ -otest  go_fish.o card.o deck.o player.o
driver: go_fish.cpp card.h deck.h player.h
	g++ -c go_fish.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c  deck.cpp
player.o: player.cpp player.h card.h
	g++ -c  player.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
