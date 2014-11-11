CXX = g++
CXXFLAGS = -Wall -O -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
#LDFLAGS = -L/home/maximilian/gtest-1.7.0/lib/.libs/ -lgtest -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread
SOURCES = src/Fibonacci.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Fibonacci

.PHONY: all
all: build

# builds algorithms
.PHONY: build
build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
