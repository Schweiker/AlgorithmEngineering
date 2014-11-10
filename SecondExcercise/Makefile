#makros
SHELL = /bin/sh
CXX = g++
SRC = src/*.cpp
OBJECTS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -O
CXXFLAGS = -I/gtest-1.7.0/include/gtest
EXE = Fibonacci

.PHONY: all
all: build

.PHONY: build
build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CPPFLAGS) $(CXXFLAGS) -o $(EXE)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXE)
