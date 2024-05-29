CXX = g++

LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

CXXFLAGS = -Wall -Wpedantic -g 

all:
	$(CXX) $(CXXFLAGS) ./src/*.cpp -I src/include -L src/lib -o main main.cpp $(LIBS)

run:
	./main

clean:
	rm -f ./main

linux_compile:
	$(CXX) ./src/*.cpp -I src/include -L src/lib -o main main.cpp `sdl2-config --libs`

