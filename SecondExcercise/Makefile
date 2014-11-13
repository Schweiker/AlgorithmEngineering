CXX = g++
CXXFLAGS = -Wall -O -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
#LDFLAGS = -L/home/maximilian/gtest-1.7.0/lib/.libs/ -lgtest -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread
SRC = src/Fibonacci.cpp
MAINSRC = src/Fibonacci_main.cpp
TESTSRC = test/Fibonacci_test.cpp
MAINOBJECTS = $(MAINSRC:.cpp=.o)
TESTOBJECTS = $(TESTSRC:.cpp=.o)

EXECUTABLE = Fibonacci
TESTEXECUTABLE = Fibonacci_test


.PHONY: all
all: build

# builds algorithms
.PHONY: build
build: $(MAINOBJECTS)
	$(CXX) $(MAINOBJECTS) $(CXXFLAGS) -o $(EXECUTABLE)
	./$(EXECUTABLE)


# build tests
.PHONY: tests
tests: $(TESTOBJECTS)
	$(CXX) $(TESTOBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(MAINOBJECTS) $(TESTOBJECTS) $(EXECUTABLE) $(TESTEXECUTABLE)
