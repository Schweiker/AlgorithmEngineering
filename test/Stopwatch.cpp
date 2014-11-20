#include "../includes/Stopwatch.h"

//start measuring time
void Stopwatch::start()
{
    t_start = std::chrono::system_clock::now();
}
//stop measuring time
void Stopwatch::stop()
{
    diff = std::chrono::system_clock::now() - t_start;
}
//reset timer
void Stopwatch::reset()
{
    diff = std::chrono::system_clock::duration::zero();
}
//show time measured
uint64_t Stopwatch::peek()
{
    return diff.count();
}
