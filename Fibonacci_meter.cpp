#include "includes/Meter.h"
#include "includes/Fibonacci.h"
#include <iostream>
int main ()
{
    char AlgName[20];
    std::cout << "Starting to measure Fibonacci Algorithms" << std::endl;

   //because the first implementation of Fibonacci is so slow i will do just 20 tests
    int numberOfTest = 10;

    std::cout << "Start measure for first Implementation" << std::endl;

    Meter mAlg1 = Meter("FibAlg1_TIME.txt","FibAlg1_CYCLE.txt","FibAlg1_TIME_plot.txt","FibAlg1_CYCLE_plot.txt");

    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg1.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber1, i);
        mAlg1.printDataTime(AlgName);
        mAlg1.printDataCycle(AlgName);
        mAlg1.printDataToPlotTime(AlgName);
        mAlg1.printDataToPlotCycle(AlgName);

    }

    //the next implementations are assumed to be much faster so i will do 50 tests each

    std::cout << "Finished measure for first Implementation \n"
             << "Start measure for second Implementation" << std::endl;

    numberOfTest = 50;

    Meter mAlg2 = Meter("FibAlg2_TIME.txt","FibAlg2_CYCLE.txt","FibAlg2_TIME_plot.txt","FibAlg2_CYCLE_plot.txt");

    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg2.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber2, i);
        mAlg2.printDataTime(AlgName);
        mAlg2.printDataCycle(AlgName);
        mAlg2.printDataToPlotTime(AlgName);
        mAlg2.printDataToPlotCycle(AlgName);
    }

    std::cout << "Finished measure for second Implementation \n"
             << "Start measure for thrid Implementation" << std::endl;


    Meter mAlg3 = Meter("FibAlg3_TIME.txt","FibAlg3_CYCLE.txt","FibAlg3_TIME_plot.txt","FibAlg3_CYCLE_plot.txt");
    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg3.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber3, i);
        mAlg3.printDataTime(AlgName);
        mAlg3.printDataCycle(AlgName);
        mAlg3.printDataToPlotTime(AlgName);
        mAlg3.printDataToPlotCycle(AlgName);
    }

    std::cout << "Finished measure for third Implementation \n"
             << "Start measure for fourth Implementation" << std::endl;

    Meter mAlg4 = Meter("FibAlg4_TIME.txt","FibAlg4_CYCLE.txt","FibAlg4_TIME_plot.txt","FibAlg4_CYCLE_plot.txt");

    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg4.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber4, i);
        mAlg4.printDataTime(AlgName);
        mAlg4.printDataCycle(AlgName);
        mAlg4.printDataToPlotTime(AlgName);
        mAlg4.printDataToPlotCycle(AlgName);
    }

    std::cout << "Finished measure for fourth Implementation \n"
             << "Start measure for fifth Implementation" << std::endl;

    Meter mAlg5 = Meter("FibAlg5_TIME.txt","FibAlg5_CYCLE.txt","FibAlg5_TIME_plot.txt","FibAlg5_CYCLE_plot.txt");

    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg5.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber5, i);
        mAlg5.printDataTime(AlgName);
        mAlg5.printDataCycle(AlgName);
        mAlg5.printDataToPlotTime(AlgName);
        mAlg5.printDataToPlotCycle(AlgName);
    }

    std::cout << "Finished measure for fifth Implementation \n"
             << "Start measure for sixth Implementation" << std::endl;

    Meter mAlg6 = Meter("FibAlg6_TIME.txt","FibAlg6_CYCLE.txt","FibAlg6_TIME_plot.txt","FibAlg6_CYCLE_plot.txt");

    for(int i = 0; i < numberOfTest;i++)
    {
        mAlg6.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber6, i);
        mAlg6.printDataTime(AlgName);
        mAlg6.printDataCycle(AlgName);
        mAlg6.printDataToPlotTime(AlgName);
        mAlg6.printDataToPlotCycle(AlgName);
    }

    std::cout << "Finished measure for sixth Implementation \n"
             << "Finished all tests" << std::endl;


	return 0;
}
