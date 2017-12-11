target: compileAll
	g++ -o exe/server.out *.o
	rm -f *.o

compileAll: ReversiGame/include/*.h ReversiGame/src/*.cpp
	g++ -IReversiGame/include/ -c ReversiGame/src/*.cpp
