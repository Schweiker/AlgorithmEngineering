#makros
SHELL = /bin/sh
CXX = g++
<<<<<<< HEAD
SRC = src/*.cpp
OBJECTS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -O
CXXFLAGS = -I/gtest-1.7.0/include/gtest
EXE = Fibonacci
=======
CXXFLAGS = -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread
SOURCES = src/Fibonacci.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Fibonacci

#builder
>>>>>>> de7370e091b51a272dce6409e8ad2a833fc0a860

.PHONY: all
all: tests

.PHONY: tests
tests: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)
	./$(EXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
<<<<<<< HEAD
	rm -f $(OBJECTS) $(EXE)
=======
	rm -f $(OBJECTS) $(TESTOBJECTS) $(MAINOBJECTS) $(EXECUTABLE) $(EXECUTABLE_TEST)
>>>>>>> de7370e091b51a272dce6409e8ad2a833fc0a860
