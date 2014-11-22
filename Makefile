#makros
CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c -I/usr/src/linux-headers-3.13.0-32/include/asm-generic
CXXFLAGS_GTEST = -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread

#sources

Fibonacci.o: src/Fibonacci.cpp includes/Fibonacci.h
	$(CXX) $(CXXFLAGS) src/Fibonacci.cpp

Sorting.o: src/Sorting.cpp includes/Sorting.h
	$(CXX) $(CXXFLAGS) src/Sorting.cpp

#tests

Fibonacci_gtest.o: main/Fibonacci_gtest.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) main/Fibonacci_gtest.cpp

Fibonacci_gtest: Fibonacci_gtest.o Fibonacci.o
	$(CXX) -o Fibonacci_gtest Fibonacci_gtest.o Fibonacci.o $(LDFLAGS)
	./Fibonacci_gtest

tests: Fibonacci_gtest

#main
Sorting_main.o: Sorting_main.cpp
	$(CXX) $(CXXFLAGS) Sorting_main.cpp

Sorting_main: Sorting.o Sorting_main.o
	$(CXX) -o Sorting_main Sorting_main.o Sorting.o $(LDFLAGS)
	./Sorting_main

sortmain: Sorting_main

Fibonacci_main.o: main/Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) main/Fibonacci_main.cpp

Fibonacci_main: Fibonacci_main.o Fibonacci.o
	$(CXX) -o Fibonacci_main Fibonacci_main.o Fibonacci.o $(LDFLAGS)
	./Fibonacci_main

fibmain: Fibonacci_main

# meter objects

Stopwatch.o: test/Stopwatch.cpp includes/Stopwatch.h
	$(CXX) $(CXXFLAGS) test/Stopwatch.cpp

Meter.o: test/Meter.cpp includes/Meter.h
	$(CXX) $(CXXFLAGS) test/Meter.cpp

Fibonacci_meter.o: Fibonacci_meter.cpp
	$(CXX) $(CXXFLAGS) Fibonacci_meter.cpp

Fibonacci_meter: Fibonacci_meter.o Fibonacci.o Meter.o Stopwatch.o
	$(CXX) -o Fibonacci_meter Fibonacci_meter.o Fibonacci.o Meter.o Stopwatch.o $(LDFLAGS)
	./Fibonacci_meter

meter: Fibonacci_meter
# Removes all objects and executables:

cleantxt:
	rm -f *.txt

clean:
	rm -f *.o Fibonacci_main Fibonacci_gtest Fibonacci_meter Sorting_main
	reset
