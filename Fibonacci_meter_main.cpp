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

    Meter mAlg1 = ("FibAlg1_TIME.txt");
    for(int i = 0; i < 40;i++)
    {
        mAlg1.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber1, i);
        mAlg1.printData(AlgName);
    }

    //the next implementations are assumed to be much faster so i will do 50 tests each

    std::cout << "Finished measure for first Implementation \n"
             << "Start measure for second Implementation" << std::endl;

    numberOfTest = 50;

    Meter mAlg2 = ("FibAlg2_TIME.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg2.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber2, i);
        mAlg2.printData(AlgName);
    }

    std::cout << "Finished measure for second Implementation \n"
             << "Start measure for thrid Implementation" << std::endl;


    Meter mAlg3 = ("FibAlg3_TIME.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg3.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber3, i);
        mAlg3.printData(AlgName);
    }

    std::cout << "Finished measure for third Implementation \n"
             << "Start measure for fourth Implementation" << std::endl;

    Meter mAlg4 = ("FibAlg4_TIME.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg4.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber4, i);
        mAlg4.printData(AlgName);
    }

    std::cout << "Finished measure for fourth Implementation \n"
             << "Start measure for fifth Implementation" << std::endl;

    Meter mAlg5 = ("FibAlg5_TIME.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg5.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber5, i);
        mAlg5.printData(AlgName);
    }

    std::cout << "Finished measure for fifth Implementation \n"
             << "Start measure for sixth Implementation" << std::endl;

    Meter mAlg6 = ("FibAlg6_TIME.txt");
    for(int i = 0; i < 50;i++)
    {
        mAlg6.measureAlgorithm(numberOfTest, *Fibonacci::calculateNthFibonacciNumber6, i);
        mAlg6.printData(AlgName);
    }

    std::cout << "Finished measure for sixth Implementation \n"
             << "Finished all tests" << std::endl;


	return 0;
}
