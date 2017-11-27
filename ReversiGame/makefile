a.out: Board.o Main.o Cell.o Game.o Player.o HumanPlayer.o AI.o
	g++ Board.o Main.o Cell.o Game.o  Player.o HumanPlayer.o AI.o

Board.o: Board.cpp Board.h Cell.h
	g++ -c Board.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

Game.o: Game.cpp Game.h Board.h HumanPlayer.h AI.h
	g++ -c Game.cpp

Player.o: Player.h Cell.h
	g++ -c Player.h

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h Player.h Cell.h
	g++ -c HumanPlayer.cpp

AI.o: AI.cpp AI.h Player.h Cell.h
	g++ -c AI.cpp

Main.o: Main.cpp Game.h
	g++ -c Main.cpp
