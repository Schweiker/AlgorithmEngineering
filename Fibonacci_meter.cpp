#include "includes/Meter.h"
#include "includes/Fibonacci.h"
#include <iostream>
int main ()
{
    char AlgName[20];
    std::cout << "Starting to measure Fibonacci Algorithms" << std::endl;

   //because the first implementation of Fibonacci is so slow i will do just 20 tests
    int numberOfTest = 20;

    std::cout << "Start measure for first Implementation" << std::endl;

    Meter mAlg1 = Meter("FibAlg1_TIME.txt","FibAlg1_CYCLE.txt");

    for(int i = 0; i < 40;i++)
    {
        mAlg1.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber1, i);
        mAlg1.printDataTime(AlgName);
        mAlg1.printDataCycle(AlgName);
    }

    //the next implementations are assumed to be much faster so i will do 50 tests each

    std::cout << "Finished measure for first Implementation \n"
             << "Start measure for second Implementation" << std::endl;

    numberOfTest = 50;

    Meter mAlg2 = Meter("FibAlg2_TIME.txt","FibAlg2_CYCLE.txt");

    for(int i = 0; i < 50;i++)
    {
        mAlg2.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber2, i);
        mAlg2.printDataTime(AlgName);
        mAlg2.printDataCycle(AlgName);
    }

    std::cout << "Finished measure for second Implementation \n"
             << "Start measure for thrid Implementation" << std::endl;


    Meter mAlg3 = Meter("FibAlg3_TIME.txt","FibAlg3_CYCLE.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg3.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber3, i);
        mAlg3.printDataTime(AlgName);
        mAlg3.printDataCycle(AlgName);
    }

    std::cout << "Finished measure for third Implementation \n"
             << "Start measure for fourth Implementation" << std::endl;

    Meter mAlg4 = Meter("FibAlg4_TIME.txt","FibAlg4_CYCLE.txt");

    for(int i = 0; i < 50;i++)
    {
        mAlg4.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber4, i);
        mAlg4.printDataTime(AlgName);
        mAlg4.printDataCycle(AlgName);
    }

    std::cout << "Finished measure for fourth Implementation \n"
             << "Start measure for fifth Implementation" << std::endl;

    Meter mAlg5 = Meter("FibAlg5_TIME.txt","FibAlg5_CYCLE.txt");

    for(int i = 0; i < 50;i++)
    {
        mAlg5.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber5, i);
        mAlg5.printDataTime(AlgName);
        mAlg5.printDataCycle(AlgName);
    }

    std::cout << "Finished measure for fifth Implementation \n"
             << "Start measure for sixth Implementation" << std::endl;

    Meter mAlg6 = Meter("FibAlg6_TIME.txt","FibAlg6_CYCLE.txt");

    for(int i = 0; i < 50;i++)
    {
        mAlg6.measure(numberOfTest, *Fibonacci::calculateNthFibonacciNumber6, i);
        mAlg6.printDataTime(AlgName);
        mAlg6.printDataCycle(AlgName);
    }

    std::cout << "Finished measure for sixth Implementation \n"
             << "Finished all tests" << std::endl;


	return 0;
}
