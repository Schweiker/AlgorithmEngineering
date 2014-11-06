#makros
CXX = g++
OBJECTS = $(SRC:.cpp=.o)
SRC = src/Fibonacci.cpp
CPPFLAGS = -Wall -O
CXXFLAGS = -isystem $(GTEST_DIR)/include
GTEST_DIR = C:\gtest-1.7.0
EXE = Fibonacci

.PHONY: all
all: build

.PHONY: build
build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CPPFLAGS) $(CXXFLAGS) -o $(EXE)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXE) gtest.a gtest_main.a *.o
