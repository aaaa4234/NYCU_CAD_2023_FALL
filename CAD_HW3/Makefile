all: 312510237

CXX = g++

LINKFLAGS = -pedantic -Wall -fomit-frame-pointer -funroll-all-loops -O3 -std=c++11

312510237: cad_hw3.o 
	g++ $(LINKFLAGS) cad_hw3.o -o 312510237

cad_hw3.o: cad_hw3.cpp
	g++ $(LINKFLAGS)  -c cad_hw3.cpp

clean:
	rm -rf *.o 