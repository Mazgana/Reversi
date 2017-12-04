# Adi Mazgani 203717699
# Leah Wachtfogel 206098931

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -Iinclude/ -c src/*.cpp
