all:pushboxgame

pushboxgame:game.o map.o main.o
	g++ -W -Wall -o pushboxgame game.o map.o main.o -lncurses

game.o:game.cpp
	g++ -W -Wall -c -o game.o game.cpp 

map.o:map.cpp
	g++ -W -Wall -c -o map.o map.cpp

main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp

clean:
	rm pushboxgame ./*.o
