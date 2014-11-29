#makros
CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c
FLAGSFOROBJECTS = -o $@
#-I/usr/src/linux-headers-3.13.0-32/include/asm-generic
CXXFLAGS_GTEST = -I/home/maximilian/gtest-1.7.0/include
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread
OBJECTS = objects/
MAINS = main/

#sources

$(OBJECTS)Fibonacci.o: src/Fibonacci.cpp includes/Fibonacci.h
	$(CXX) $(CXXFLAGS) src/Fibonacci.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Sorting.o: src/Sorting.cpp includes/Sorting.h
	$(CXX) $(CXXFLAGS) src/Sorting.cpp $(FLAGSFOROBJECTS)

#tests

$(OBJECTS)Fibonacci_gtest.o: $(MAINS)Fibonacci_gtest.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) $(MAINS)Fibonacci_gtest.cpp $(FLAGSFOROBJECTS)

Fibonacci_gtest: $(OBJECTS)Fibonacci_gtest.o $(OBJECTS)Fibonacci.o
	$(CXX) -o Fibonacci_gtest $(OBJECTS)Fibonacci_gtest.o $(OBJECTS)Fibonacci.o $(LDFLAGS)
	./Fibonacci_gtest

tests: Fibonacci_gtest

#mains
$(OBJECTS)Sorting_main.o: $(MAINS)Sorting_main.cpp
	$(CXX) $(CXXFLAGS) $(MAINS)Sorting_main.cpp $(FLAGSFOROBJECTS)

Sorting_main: $(OBJECTS)Sorting_main.o $(OBJECTS)Sorting.o
	$(CXX) -o Sorting_main $(OBJECTS)Sorting_main.o $(OBJECTS)Sorting.o $(LDFLAGS)
	./Sorting_main

sortmain: Sorting_main

$(OBJECTS)Fibonacci_main.o: $(MAINS)Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) $(MAINS)Fibonacci_main.cpp $(FLAGSFOROBJECTS)

Fibonacci_main: $(OBJECTS)Fibonacci_main.o $(OBJECTS)Fibonacci.o
	$(CXX) -o Fibonacci_main $(OBJECTS)Fibonacci_main.o $(OBJECTS)Fibonacci.o $(LDFLAGS)
	./Fibonacci_main

fibmain: Fibonacci_main

# meter objects

$(OBJECTS)Stopwatch.o: test/Stopwatch.cpp includes/Stopwatch.h
	$(CXX) $(CXXFLAGS) test/Stopwatch.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Meter.o: test/Meter.cpp includes/Meter.h
	$(CXX) $(CXXFLAGS) test/Meter.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Fibonacci_meter.o: $(MAINS)Fibonacci_meter.cpp
	$(CXX) $(CXXFLAGS) $(MAINS)Fibonacci_meter.cpp $(FLAGSFOROBJECTS)

Fibonacci_meter: $(OBJECTS)Fibonacci_meter.o $(OBJECTS)Fibonacci.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o
	$(CXX) -o Fibonacci_meter $(OBJECTS)Fibonacci_meter.o $(OBJECTS)Fibonacci.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o $(LDFLAGS)
	./Fibonacci_meter

meter: Fibonacci_meter

plotfib:
	gnuplot 'plots/plotfibtime'
	gnuplot 'plots/plotfibcycles'

fibplot: meter plotfib


# Removes all objects and executables:

cleantxt:
	rm -f *.txt

cleanplot:
	rm -f *.png

clean:
	rm -f objects/*.o Fibonacci_main Fibonacci_gtest Fibonacci_meter Sorting_main
	reset

cleanall: cleantxt cleanplot clean
