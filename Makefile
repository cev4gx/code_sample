# Claire Veasey cev4gx 3/13/17 Makefile

CXX = clang++ -std=c++11 -O2
CXXFLAGS = -Wall

OFILES = hashTable.o timer.o wordPuzzle.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp
