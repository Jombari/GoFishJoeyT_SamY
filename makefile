final: card_demo.o card.o deck.o player.o
	g++ -otest  card_demo.o card.o deck.o player.o
driver: card_demo.cpp card.h deck.h player.h
	g++ -c card_demo.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c  deck.cpp
player.o: player.cpp player.h card.h
	g++ -c  player.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
