#ifndef meter_h
#define meter_h

#include <vector>
#include <cstdint>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <iostream>

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

    uint32_t numberOfTests;

    public:

        //const char* filename;

        Meter(const char* fileData,const char* FileCycle,const char* filePlotCycle,const char* filePlotTime);

        template<typename RT,typename PT,typename PT2>
        void measure(uint32_t numOfTest, RT(*f)(PT arg),PT2 valueToTest);

        template<typename RT,typename PT,typename PT2>
        void measureAlgorithmTime(uint32_t numOfTest, RT(*f)(PT arg),PT2 valueToTest);

        template<typename RT,typename PT,typename PT2>
        void measureAlgorithmCycles(uint32_t numOfTest, RT(*f)(PT arg),PT2 valueToTest);

        void TimeStats();
        void CycleStats();

        void initfileData();
        void initfileCycle();

        void printDataTime(const char* casename);
        void printDataCycle(const char* casename);
        void printDataToPlotTime(const char* casename,int n);
        void printDataToPlotCycle(const char* casename, int n);
};


template <typename RT, typename PT,typename PT2>
void Meter::measure(uint32_t numOfTest, RT(*f)(PT arg), PT2 valueToTest)
{
    measureAlgorithmTime(numOfTest, (*f),valueToTest);
    measureAlgorithmCycles(numOfTest, (*f), valueToTest);
}
template <typename RT, typename PT,typename PT2>
void Meter::measureAlgorithmTime(uint32_t numOfTest, RT(*f)(PT arg), PT2 valueToTest)
{

    if(numOfTest > 0)numberOfTests = numOfTest;

    t_measures = vector<uint64_t>(numberOfTests, 0);

    //do tests
    for(uint64_t i = 0; i < numberOfTests; i++)
    {
        w.start();
        (*f)(valueToTest);
        w.stop();
        t_measures[i] = w.peek();
        w.reset();
    }
    TimeStats();
}

template <typename RT, typename PT,typename PT2>
void Meter::measureAlgorithmCycles(uint32_t numOfTest, RT(*f)(PT arg), PT2 valueToTest)
{

    if(numOfTest > 0) numberOfTests = numOfTest;

    //build Memory for Data from Measurements
    c_measures = vector<uint64_t>(numberOfTests, 0);



    //unsigned long flags;
    uint64_t c_start, c_end, c_diff;
    unsigned cycles_low, cycles_high, cycles_low1, cycles_high1;
    //disable preemption
    //preempt_disable();
    //disable hard interrupts
    //raw_local_irq_save(flags);

    for(uint64_t i = 0; i < numberOfTests;i++)
    {

        asm volatile
        (
            "CPUID\n\t"
            "RDTSC\n\t"
            "mov %%edx,  %0\n\t"
            "mov %%eax,  %1\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax", "%rbx", "%rcx", "%rdx"
        );

        //call function to measure and let it do work
        (*f)(valueToTest);

        asm volatile
        (
            "CPUID\n\t"
            "RDTSC\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t": "=r" (cycles_high1), "=r" (cycles_low1):: "%rax", "%rbx", "%rcx", "%rdx"
        );

        c_start =  (((uint64_t)cycles_high << 32) | cycles_low);
        c_end = (((uint64_t)cycles_high1 << 32) | cycles_low1);
        c_diff = c_end - c_start;

        c_measures[i] = c_diff;
    }
    //enable HArd interrupts
    //raw_local_irq_restore(flags);
    //enable preemption
    //preempt_enable();

    //statistics
    CycleStats();
}

#endif
