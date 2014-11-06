##makros
OBJECTS = Fibonacci_Test.o
CC = g++
CFLAGS = -Wall -c $(DEBUG)
LDFLAGS = C:\gtest-1.7.0\make
DEBUG = -g
SOURCES = src/Fibonacci.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXE = Fibonacci

.PHONY: all
all: build

.PHONY: build
build: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(CFLAGS) -o $(EXE)

.PHONY: clean
clean:
	rm -f $(OBJECTS)$(EXE)
