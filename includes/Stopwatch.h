#ifndef stopwatch_h
#define stopwatch_h

#include <chrono>
#include <cstdint>

class Stopwatch
{
    std::chrono::system_clock::time_point t_start;
	std::chrono::duration<uint64_t,std::ratio<1,1000000000l> > diff;

	public:

        Stopwatch(){}

        void start();

        void stop();

        void reset();

        uint64_t peek();
};

#endif
