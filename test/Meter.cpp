#include "../includes/Meter.h"
Meter::Meter(const char* fileData ="measurements.txt", const char* fileCycle="measurements2.txt"
            ,const char* filePlotCycle="measurements3.txt",const char* filePlotTime="measurements4.txt")
{
    filenameTime = fileData;
    filenameCycle = fileCycle;
    filenamePlotTime = filePlotTime;
    filenamePlotCycle = filePlotCycle;

    initfileData();
    initfileCycle();
}

void Meter::measure(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest)
{
    measureAlgorithmTime(numOfTest, (*f),valueToTest);
    measureAlgorithmCycles(numOfTest, (*f), valueToTest);
}

void Meter::measureAlgorithmTime(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest)
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
    t_min = t_measures[0];
    t_max = 0;

    double sum = 0;

    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        if(t_measures[i] < t_min) t_min = t_measures[i];
        if(t_measures[i] > t_max) t_max = t_measures[i];
        sum += t_measures[i];
    }
    t_mean = sum / numberOfTests;

    double dev = 0;
    double devsum = 0;

    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        dev += t_mean - t_measures[i];

        devsum += (dev * dev);
    }
    if(numberOfTests > 2);
    t_standardDeviation = sqrt((double)devsum/(numberOfTests-1));
}


void Meter::measureAlgorithmCycles(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest)
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
    c_max = 0;
    c_min = c_measures[0];
    c_mean = 0;
    double sum = 0;
    //calculate max, min and sum for mean
    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        if(c_measures[i] < c_min) c_min = c_measures[i];
        if(c_measures[i] > c_max) c_max = c_measures[i];
        sum += c_measures[i];
    }
    c_mean = sum / numberOfTests;

    //deviation
    double dev = 0;
    double devsum = 0;

    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        dev += c_mean - c_measures[i];
        devsum += (dev * dev);
    }
    if(numberOfTests > 2)
    {
        c_standardDeviation = sqrt((double)devsum/(numberOfTests-1));
    }
}

void Meter::initfileData()
{
    remove(filenameTime);
    fstream file;
    file.open (filenameTime, fstream::out | fstream::app);

    file << "#Tests:        Minimum(µs):        Maximum(µs):         Mean(µs):         deviation(µs):\n";
    file << "----------------------------------------------------------------------------------------\n";
    file.close();
}
void Meter::initfileCycle()
{
    remove(filenameCycle);
    fstream file;
    file.open (filenameCycle, fstream::out | fstream::app);

    file << "#Tests:        Minimum(µs):        Maximum(µs):         Mean(µs):         deviation(µs):\n";
    file << "----------------------------------------------------------------------------------------\n";
    file.close();
}


void Meter::printDataTime(const char* casename)
{
    fstream file;
    file.open(filenameTime, fstream::out | fstream::app);
    file << std::setw(13) << numberOfTests
         << std::setw(13) << t_min
         << std::setw(13) << t_max
         << std::setw(13) << t_mean
         << std::setprecision(3) << std::fixed << std::setw(30) << t_standardDeviation << "\n";
    file.close();
}

void Meter::printDataCycle(const char* casename)
{
    fstream file;
    file.open(filenameCycle, fstream::out | fstream::app);
    file << std::setw(13) << numberOfTests
         << std::setw(13) << c_min
         << std::setw(13) << c_max
         << std::setw(13) << c_mean
         << std::setprecision(3) << std::fixed << std::setw(30) << c_standardDeviation << "\n";
    file.close();
}
void Meter::printDataToPlotTime(const char* casename, int n)
{
    fstream file;
    file.open(filenamePlotTime, fstream::out | fstream::app);
    file << n << " " << t_mean << "\n";
    file.close();
}

void Meter::printDataToPlotCycle(const char* casename, int n)
{
    fstream file;
    file.open(filenamePlotCycle, fstream::out | fstream::app);
    file << n << " "<< c_mean << "\n";
    file.close();
}
