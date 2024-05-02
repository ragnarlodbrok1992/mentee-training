CXX = g++

LIBS = -lmingw32 -lSDL2main -lSDL2

CXXFLAGS = -Wall -g

all:
	$(CXX) $(CXXFLAGS) ./src/*.cpp -I src/include -L src/lib -o main main.cpp $(LIBS)

run:
	./main

clean:
	rm -f ./main
