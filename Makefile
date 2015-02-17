#makros
CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c -g
FLAGSFOROBJECTS = -o $@
#-I/usr/src/linux-headers-3.13.0-32/include/asm-generic
CXXFLAGS_GTEST = -I/home/maximilian/gtest-1.7.0/include
CXXFLAGS_INCLUDE = -Iincludes
#LDFLAGS = -L/usr/lib/libgtest.a -pthread
LDFLAGS = /home/maximilian/gtest-1.7.0/lib/.libs/libgtest.a -pthread
OBJECTS = objects/
MAINS = main/

BUILD ?= debug
ifeq ($(BUILD), debug)
	CXXFLAGS += -ggdb3 -DDEBUG
endif

#sources

$(OBJECTS)Fibonacci.o: src/Fibonacci.cpp includes/Fibonacci.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Fibonacci.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Sorting.o: src/Sorting.cpp includes/Sorting.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Sorting.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Heapsort.o: src/Heapsort.cpp includes/Heapsort.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Heapsort.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Introsort.o: src/Introsort.cpp includes/Introsort.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Introsort.cpp $(FLAGSFOROBJECTS)

#tests

$(OBJECTS)Fibonacci_gtest.o: $(MAINS)Fibonacci_gtest.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) $(CXXFLAGS_INCLUDE) $(MAINS)Fibonacci_gtest.cpp $(FLAGSFOROBJECTS)

Fibonacci_gtest: $(OBJECTS)Fibonacci_gtest.o $(OBJECTS)Fibonacci.o
	$(CXX) -o Fibonacci_gtest $(OBJECTS)Fibonacci_gtest.o $(OBJECTS)Fibonacci.o $(LDFLAGS)
	./Fibonacci_gtest

fibtest: Fibonacci_gtest

$(OBJECTS)Sorting_gtest.o: $(MAINS)Sorting_gtest.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) $(CXXFLAGS_INCLUDE) $(MAINS)Sorting_gtest.cpp $(FLAGSFOROBJECTS)

Sorting_gtest: $(OBJECTS)Sorting_gtest.o $(OBJECTS)Sorting.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o
	$(CXX) -o Sorting_gtest $(OBJECTS)Sorting_gtest.o $(OBJECTS)Sorting.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o $(LDFLAGS)
	./Sorting_gtest

sorttest: Sorting_gtest

tests: Fibonacci_gtest Sorting_gtest

#mains
$(OBJECTS)Sorting_main.o: $(MAINS)Sorting_main.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Sorting_main.cpp $(FLAGSFOROBJECTS)

Sorting_main: $(OBJECTS)Sorting.o $(OBJECTS)Sorting_main.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o
	$(CXX) -o Sorting_main $(OBJECTS)Sorting.o $(OBJECTS)Sorting_main.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o $(LDFLAGS)
	./Sorting_main

sortmain: Sorting_main

$(OBJECTS)Fibonacci_main.o: $(MAINS)Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Fibonacci_main.cpp $(FLAGSFOROBJECTS)

Fibonacci_main: $(OBJECTS)Fibonacci_main.o $(OBJECTS)Fibonacci.o
	$(CXX) -o Fibonacci_main $(OBJECTS)Fibonacci_main.o $(OBJECTS)Fibonacci.o $(LDFLAGS)
	./Fibonacci_main

fibmain: Fibonacci_main

$(OBJECTS)Heapsort_main.o: $(MAINS)Heapsort_main.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Heapsort_main.cpp $(FLAGSFOROBJECTS)

Heapsort_main: $(OBJECTS)Heapsort_main.o $(OBJECTS)Heapsort.o
	$(CXX) -o Heapsort_main $(OBJECTS)Heapsort_main.o $(OBJECTS)Heapsort.o $(LDFLAGS)
	./Heapsort_main

heapmain: Heapsort_main

# meter objects
$(OBJECTS)Stopwatch.o: test/Stopwatch.cpp includes/Stopwatch.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) test/Stopwatch.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Meter.o: test/Meter.cpp includes/Meter.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) test/Meter.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Fibonacci_meter.o: $(MAINS)Fibonacci_meter.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Fibonacci_meter.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Sorting_meter.o: $(MAINS)Sorting_meter.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Sorting_meter.cpp $(FLAGSFOROBJECTS)

Fibonacci_meter: $(OBJECTS)Fibonacci_meter.o $(OBJECTS)Fibonacci.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o
	$(CXX) -o Fibonacci_meter $(OBJECTS)Fibonacci_meter.o $(OBJECTS)Fibonacci.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o $(LDFLAGS)
	./Fibonacci_meter

Sorting_meter: $(OBJECTS)Sorting_meter.o $(OBJECTS)Sorting.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o
	$(CXX) -o Sorting_meter $(OBJECTS)Sorting_meter.o $(OBJECTS)Sorting.o $(OBJECTS)Meter.o $(OBJECTS)Stopwatch.o $(OBJECTS)Heapsort.o $(OBJECTS)Introsort.o $(LDFLAGS)
	./Sorting_meter

sortmeter: Sorting_meter

fibmeter: Fibonacci_meter

fibplot:
	gnuplot 'plots/plotfibtime'
	gnuplot 'plots/plotfibcycles'

sortplot:
	gnuplot 'plots/plotsortcycle_permuted'
	gnuplot 'plots/plotsorttime_permuted'
	gnuplot 'plots/plotsortcycle_reverse'
	gnuplot 'plots/plotsorttime_reverse'
	gnuplot 'plots/plotsortcycle_repeated'
	gnuplot 'plots/plotsorttime_repeated'
	gnuplot 'plots/plotsortcycle_sorted'
	gnuplot 'plots/plotsorttime_sorted'

fibplot: fibmeter fibplot

sortplot: sortmeter sortplot

#targets for build all meters and all plots

meter: Sorting_meter Fibonacci_meter

plot: fibplot sortplot

######################################################################
##For Dijkstra##

$(OBJECTS)Dijkstra_redblack.o: src/Dijkstra_redblack.cpp includes/Dijkstra_redblack.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Dijkstra_redblack.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Dijkstra_binary.o: src/Dijkstra_binary.cpp includes/Dijkstra_binary.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Dijkstra_binary.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Dijkstra_pq.o: src/Dijkstra_pq.cpp includes/Dijkstra_pq.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) src/Dijkstra_pq.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Dijkstra_gtest.o: $(MAINS)Dijkstra_gtest.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) $(CXXFLAGS_INCLUDE) $(MAINS)Dijkstra_gtest.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Dijkstra_main.o: $(MAINS)Dijkstra_main.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Dijkstra_main.cpp $(FLAGSFOROBJECTS)

$(OBJECTS)Dijkstra_meter.o: $(MAINS)Dijkstra_meter.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_INCLUDE) $(MAINS)Dijkstra_meter.cpp $(FLAGSFOROBJECTS)

Dijkstra_main: $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_main.o
	$(CXX) -o Dijkstra_main $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_main.o $(LDFLAGS)
	#./Dijkstra_main

Dijkstra_gtest: $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_gtest.o
	$(CXX) -o Dijkstra_gtest $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_gtest.o $(LDFLAGS)
	./Dijkstra_gtest

Dijkstra_meter: $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_meter.o $(OBJECTS)Stopwatch.o $(OBJECTS)Meter.o
	$(CXX) -o Dijkstra_meter $(OBJECTS)Dijkstra_redblack.o $(OBJECTS)Dijkstra_binary.o $(OBJECTS)Dijkstra_pq.o $(OBJECTS)Dijkstra_meter.o $(OBJECTS)Stopwatch.o $(OBJECTS)Meter.o $(LDFLAGS)

pathmain: Dijkstra_main

path_gtest: Dijkstra_gtest

path_meter: Dijkstra_meter

path_plot:
	gnuplot 'plots/Dijkstra_FullConnected_Cycle'
	gnuplot 'plots/Dijkstra_FullConnected_Time'

# Removes all objects and executables:

cleantxt:
	rm -f *.txt

cleanplot:
	rm -f *.png

clean:
	rm -f objects/*.o Fibonacci_main Fibonacci_gtest Fibonacci_meter Sorting_main Sorting_gtest Sorting_meter Dijkstra*
	reset

cleanall: cleantxt cleanplot clean
