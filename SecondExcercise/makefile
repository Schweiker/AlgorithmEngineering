#makros
CXX = g++
CXXFLAGS = -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread
SOURCES = src/Fibonacci.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Fibonacci

#builder

.PHONY: all
all: tests

.PHONY: tests
tests: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)
	./$(EXECUTABLE_TEST)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TESTOBJECTS) $(MAINOBJECTS) $(EXECUTABLE) $(EXECUTABLE_TEST)
