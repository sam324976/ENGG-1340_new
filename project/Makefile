
output: 1340.o add.o edit.o fire.o search.o
	g++ 1340.o add.o edit.o fire.o search.o -o system

main.o : 1340.cpp
	g++ -c 1340.cpp

add.o : add.cpp function.h
	g++ -c add.cpp

edit.o : edit.cpp function.h
	g++ -c edit.cpp

fire.o : fire.cpp function.h
	g++ -c fire.cpp

search.o : search.cpp function.h
	g++ -c search.cpp
