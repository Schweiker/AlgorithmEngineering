#makros
CXX = g++
CXXFLAGS = -Wall -O -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread

SRC = $(WILDCARD src/*.cpp)
MAINSRC = $(WILDCARD src/*.cpp)
TESTSRC = $(WILDCARD src/*.cpp)

OBJECTS = $(patsubst %.cpp,%.o,$(SRC))
MAINOBJECTS = $(patsubst %.cpp,%.o,$(MAINSRC))
TESTOBJECTS = $(patsubst %.cpp,%.o,$(TESTSRC))

MAINEXECUTABLE = Fibonacci_main
TESTEXECUTABLE = Fibonacci_test




.PHONY: all
all: build $(SRC)

$(SRC) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(OBJECTS)

# builds algorithms
.PHONY: build
build: $(MAINOBJECTS) $(OBJECTS)
	$(CXX) $(MAINOBJECTS) $(OBJECTS) $(CXXFLAGS) -o $(MAINEXECUTABLE)
	./$(MAINEXECUTABLE)


# build tests
.PHONY: tests
tests: $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(TESTOBJECTS) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(MAINOBJECTS) $(TESTOBJECTS) $(EXECUTABLE) $(TESTEXECUTABLE)
