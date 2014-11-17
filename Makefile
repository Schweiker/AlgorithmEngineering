#makros
CXX = g++ -std=gnu++11
CXXFLAGS = -Wall -O -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread

SRC = src/Fibonacci.cpp
MAINSRC = main/Fibonacci_main.cpp
TESTSRC = test/Fibonacci_test.cpp
METERSRC = test/Fibonacci_meter.cpp

OBJECTS = $(patsubst %.cpp, %.o, $(SRC))
MAINOBJECTS = $(patsubst %.cpp, %.o, $(MAINSRC))
TESTOBJECTS = $(patsubst %.cpp, %.o, $(TESTSRC))
METEROBJECTS = $(patsubst %.cpp, %.o, $(METERSRC))

MAINEXECUTABLE = Fibonacci_main
TESTEXECUTABLE = Fibonacci_test
METEREXECUTABLE = Fibonacci_meter

.PHONY: all
all: build

# builds pure algorithms
.PHONY: build
build: $(MAINOBJECTS)
	$(CXX) $(MAINOBJECTS) $(CXXFLAGS) -o $(MAINEXECUTABLE)
	./$(MAINEXECUTABLE)

#$(MAINOBJECTS): $(MAINSRC) $(SRC)
#	$(CXX) $(MAINSRC) $(SRC) $(CXXFLAGS) -o $(MAINOBJECTS)
.PHONY: meter
meter: $(METEROBJECTS)
	$(CXX) $(METEROBJECTS) $(CXXFLAGS) -o $(METEREXECUTABLE)
	./$(METEREXECUTABLE)

# build tests
.PHONY: test
test: $(TESTOBJECTS)
	$(CXX) $(TESTOBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(MAINOBJECTS) $(TESTOBJECTS) $(METEROBJECTS) $(MAINEXECUTABLE) $(TESTEXECUTABLE) $(METEREXECUTABLE)
