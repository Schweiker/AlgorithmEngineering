#include <Meter.h>
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
void Meter::TimeStats()
{
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
void Meter::CycleStats()
{
    c_max = 0;
    c_min = c_measures[0];
    c_mean = 0;
    double sum = 0;
    //calculate max, min and sum for mean
    for(uint32_t i = 0; i < numberOfTests;i++)
    {
        if(c_measures[i] < c_min) c_min = c_measures[i];
        if(c_measures[i] > c_max) c_max = c_measures[i];
        sum += c_measures[i];
    }
    c_mean = sum / numberOfTests;

    //deviation
    double dev = 0;
    double devsum = 0;

    for(uint32_t i = 0; i < numberOfTests;i++)
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
