#makros
CXX = g++
SRC = src/*.cpp
OBJECTS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -O
CXXFLAGS = -I/gtest-1.7.0/include/gtest
EXE = Fibonacci
CXXFLAGS = -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread
SOURCES = src/Fibonacci.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Fibonacci

.PHONY: all
all: tests

.PHONY: tests
tests: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)
	./$(EXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
