#makros
CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c
CXXFLAGS_GTEST = -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread

Fibonacci.o: src/Fibonacci.cpp includes/Fibonacci.h
	$(CXX) $(CXXFLAGS) src/Fibonacci.cpp

Fibonacci_test_main.o: Fibonacci_test_main.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) Fibonacci_test_main.cpp

Fibonacci_test: Fibonacci_test_main.o Fibonacci.o
	$(CXX) -o Fibonacci_test Fibonacci_test_main.o Fibonacci.o $(LDFLAGS)
	./Fibonacci_test

tests: Fibonacci_test

Fibonacci_main.o: Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) Fibonacci_main.cpp

Fibonacci_main: Fibonacci_main.o Fibonacci.o
	$(CXX) -o Fibonacci_main Fibonacci_main.o Fibonacci.o $(LDFLAGS)
	./Fibonacci_main

main: Fibonacci_main

Stopwatch.o: test/Stopwatch.cpp includes/Stopwatch.h
	$(CXX) $(CXXFLAGS) test/Stopwatch.cpp

Meter.o: test/Meter.cpp includes/Meter.h
	$(CXX) $(CXXFLAGS) test/Meter.cpp

Fibonacci_meter_main.o: Fibonacci_meter_main.cpp
	$(CXX) $(CXXFLAGS) Fibonacci_meter_main.cpp

Fibonacci_meter: Fibonacci_meter_main.o Fibonacci.o Meter.o Stopwatch.o
	$(CXX) -o Fibonacci_meter Fibonacci_meter_main.o Fibonacci.o Meter.o Stopwatch.o $(LDFLAGS)
	./Fibonacci_meter

meter: Fibonacci_meter
# Removes all objects and executables:

clean:
	rm -f *.o Fibonacci_main Fibonacci_test Fibonacci_meter
