#Name: Adi Mazgani
#Username: mazgana
#id: 203717699

a.out: Board.o Main.o Cell.o Game.o Player.o HumenPlayer.o AI.o
	g++ Board.o Main.o Cell.o Game.o  Player.o HumenPlayer.o AI.o

Board.o: Board.cpp Board.h Cell.h
	g++ -c Board.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

Game.o: Game.cpp Game.h GameFlow.h Player.h
	g++ -c Game.cpp

Player.o: Player.h Cell.h
	g++ -c Player.h

HumenPlayer.o: HumenPlayer.cpp HumenPlayer.h Player.h
	g++ -c HumenPlayer.cpp

AI.o: AI.cpp AI.h Player.h
	g++ -c AI.cpp

Main.o: Main.cpp Game.h
	g++ -c Main.cpp
