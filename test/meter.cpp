#include "Stopwatch.cpp"
#include <vector>
#include <cstdint>
#include <math.h>

#include <fstream>
#include <iomanip>

using namespace std;

class Meter{
public:

	Stopwatch w;

	vector<uint64_t> measurements;
	uint64_t mean;
	uint64_t min;
	uint64_t max;
	double deviation;
    //how many tests you want to compute
	int numbers;

	const char* filename;

	Meter(const char* fileDeclaration="measurements.txt")
	{
		filename = fileDeclaration;
		//initialize file for write results from measure
		initfile();
	}

	void measure(int nom, int(*f)(int), int n)
	{

		numbers = nom;
		measurements = vector<uint64_t>(nom, 0);

		// measure time alg f needs for calculate f(n)
		for (int i=0; i<numbers; i++)
		{
			w.start();
			f(n);
			w.stop();
			measurements[i] = w.peek();
		}

        //get min max and mean for table
		min = measurements[0];
		max = 0;
		uint64_t sum = 0;
		for (int  i=0; i<numbers; i++)
		{
            //get min max and sum for mean for table
			if (measurements[i] < min) min = measurements[i];
			if (measurements[i] > max) max = measurements[i];
			sum += measurements[i];
		}
		mean = sum/numbers;

		//standart deviation:
		int64_t dev, sum_of_dev = 0;
		for (int  i=0; i<numbers; i++)
		{
			dev = mean-measurements[i];
			sum_of_dev += (dev*dev);
		}
		//definition of standard deviation
		deviation = sqrt((double)sum_of_dev/(numbers-1));
	}

	void initfile(){
		remove(filename);
		fstream file;
		file.open (filename, fstream::out | fstream::app);

		file << " Case:          #Tests:        Minimum(µs):   Maximum(µs):   Mean(µs):      deviation(µs):\n";
		file << "-----------------------------------------------------------------------------------------------\n";
		file.close();
	}

	void printData(const char* casename){
		fstream file;
		file.open(filename, fstream::out | fstream::app);
		file << setw(13) << casename
             << setw(13) << numbers
             << std::setw(13) << min
             << std::setw(13) << max
             << std::setw(14) << mean
             << std::setprecision(3) << std::fixed << std::setw(14) << deviation << "\n";
		file.close();
	}
};
