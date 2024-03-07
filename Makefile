TARGET = hello

CXX = g++

CXXFLAGS = -Wall -g

SRCS = hello.cpp

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

hello: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)