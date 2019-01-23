CC := g++
CFLAGS := -std=c++11 -Wall -pedantic

all: graph.o wideBridges clean

wideBridges:
	$(CC) $(CFLAGS) -o $@ graph.o ./src/main.cpp 

graph.o:
	$(CC) $(CFLAGS) -c ./src/graph.cpp

clean:
	rm -f *.o