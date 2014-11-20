#ifndef meter_h
#define meter_h

#include <vector>
#include <cstdint>
#include <math.h>
#include <fstream>
#include <iomanip>

#include "Stopwatch.h"

using namespace std;

class Meter
{
    Stopwatch w;

    const char* filename;

    vector<uint64_t> measures;

    uint64_t max;
    uint64_t min;
    uint64_t mean;

    uint64_t sum;

    double standardDeviation;

    uint64_t numberOfTests;

    public:

        //const char* filename;

        Meter(const char* file);

        void measureAlgorithm(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest);

        void initfile();

        void printData(const char* casename);
};

#endif
