all: player

player: ai.o 
	g++ -o player ai.o

ai.o: ai.cpp
	g++ -c ai.cpp

clean:
	rm player *.o
