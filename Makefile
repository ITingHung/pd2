all: player

player: ai.o 
	g++ -o player ai.o

ai.o: ai.cpp ai.h
	g++ -c ai.cpp

clean:
	rm player *.o
