CXX = g++

LIBS = -lmingw32 -lSDL2main -lSDL2

all:
	$(CXX) ./src/*.cpp -I src/include -L src/lib -o main main.cpp $(LIBS)

run:
	./main

clean:
	rm -f ./main

linux_compile:
	$(CXX) ./src/*.cpp -I src/include -L src/lib -o main main.cpp `sdl2-config --libs`

