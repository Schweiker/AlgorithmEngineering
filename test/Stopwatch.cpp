#include <chrono>
#include <cstdint>

class Stopwatch
{
    public :

        std::chrono::system_clock::time_point t_start;
        std::chrono::duration<uint64_t,std::ratio<1,1000000> > diff;

        Stopwatch(){}

        //start measuring time
        void start()
        {
            t_start = std::chrono::system_clock::now();
        }

        void stop()
        {
            diff = std::chrono::system_clock::now()-start;
        }
        void reset()
        {
            diff = std::chrono::system_clock::duration::zero();
        }
        uint64_t peek()
        {
            return diff.count();
        }
};
