#include "../includes/Meter.h"
Meter::Meter(const char* file ="measurements.txt")
{
    filename = file;
    initfile();
}

void Meter::measureAlgorithm(uint32_t numOfTest, uint64_t(*f)(uint32_t), uint32_t valueToTest)
{
    if(numOfTest > 0)numberOfTests = numOfTest;

    measures = vector<uint64_t>(numberOfTests, 0);

    //do tests
    for(uint64_t i = 0; i < numberOfTests; i++)
    {
        w.start();
        (*f)(valueToTest);
        w.stop();
        measures[i] = w.peek();
        w.reset();
    }
    min = measures[0];
    max = 0;

    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        if(measures[i] < min) min = measures[i];
        if(measures[i] > max) max = measures[i];
        sum += measures[i];
    }
    mean = sum / numberOfTests;

    int64_t dev = 0;
    int64_t devsum = 0;

    for(uint64_t i = 0; i < numberOfTests;i++)
    {
        dev = mean - measures[i];

        devsum += (dev * dev);
    }
    if(numberOfTests)
    standardDeviation = sqrt((double)devsum/(numberOfTests-1));
}

	void Meter::initfile()
	{
		remove(filename);
		fstream file;
		file.open (filename, fstream::out | fstream::app);

		file << " Case:          #Tests:        Minimum(µs):        Maximum(µs):         Mean(µs):         deviation(µs):\n";
		file << "--------------------------------------------------------------------------------------------------------\n";
		file.close();
	}

	void Meter::printData(const char* casename)
	{
		fstream file;
		file.open(filename, fstream::out | fstream::app);
		file << std::setw(13) << filename
             << std::setw(13) << numberOfTests
             << std::setw(13) << min
             << std::setw(13) << max
             << std::setw(13) << mean
             << std::setprecision(3) << std::fixed << std::setw(30) << standardDeviation << "\n";
		file.close();
	}
