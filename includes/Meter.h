#ifndef meter_h
#define meter_h

#include <vector>
#include <cstdint>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <iostream>
/*
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/hardirq.h>
#include <linux/preempt.h>
#include <linux/sched.h>
*/
#include "Stopwatch.h"

using namespace std;

class Meter
{
    Stopwatch w;

    const char* filenameTime;
    const char* filenameCycle;
    const char* filenamePlotTime;
    const char* filenamePlotCycle;

    vector<uint64_t> t_measures;
    vector<uint64_t> c_measures;

    uint64_t t_max;
    uint64_t t_min;
    double t_mean;

    uint64_t c_max;
    uint64_t c_min;
    double c_mean;

    double t_standardDeviation;

    double c_standardDeviation;

    uint64_t numberOfTests;

    public:

        //const char* filename;

        Meter(const char* fileData,const char* FileCycle,const char* filePlotCycle,const char* filePlotTime);

        void measure(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest);

        void measureAlgorithmTime(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest);

        void measureAlgorithmCycles(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest);

        void initfileData();
        void initfileCycle();

        void printDataTime(const char* casename);
        void printDataCycle(const char* casename);
        void printDataToPlotTime(const char* casename);
        void printDataToPlotCycle(const char* casename);
};

#endif
