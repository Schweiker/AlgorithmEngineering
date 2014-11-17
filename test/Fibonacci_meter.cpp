#include "meter.cpp"
#include"../src/Fibonacci.cpp"

int main (int argc, char *argv[])
{
    Meter meter = ("measureFibonacciAlgorithms.txt");
    int nom = 100;

	meter.measure(nom,calculateNthFibonacciNumber1,20);
	meter.printData("FibonacciAlg1(20)");
	meter.measure(nom,calculateNthFibonacciNumber1,30);

	meter.measure(nom,calculateNthFibonacciNumber2,20);
	meter.printData("FibonacciAlg2(20)");
	meter.measure(nom,calculateNthFibonacciNumber2,30);
	meter.printData("FibonacciAlg2(30)");
	meter.measure(nom,calculateNthFibonacciNumber2,50);
	meter.printData("FibonacciAlg2(50)");
	meter.measure(nom,calculateNthFibonacciNumber2,100);
    meter.printData("FibonacciAlg2(100)");
	meter.measure(nom,calculateNthFibonacciNumber2,200);
	meter.printData("FibonacciAlg2(200)");

	meter.measure(nom,calculateNthFibonacciNumber3,20);
	meter.printData("FibonacciAlg3(20)");
	meter.measure(nom,calculateNthFibonacciNumber3,30);
	meter.printData("FibonacciAlg3(30)");
	meter.measure(nom,calculateNthFibonacciNumber3,50);
	meter.printData("FibonacciAlg3(50)");
	meter.measure(nom,calculateNthFibonacciNumber3,100);
	meter.printData("FibonacciAlg3(100)");
	meter.measure(nom,calculateNthFibonacciNumber3,200);
	meter.printData("FibonacciAlg3(200)");

	meter.measure(nom,calculateNthFibonacciNumber4,20);
	meter.printData("FibonacciAlg4(20)");
	meter.measure(nom,calculateNthFibonacciNumber4,30);
	meter.printData("FibonacciAlg4(30)");
	meter.measure(nom,calculateNthFibonacciNumber4,50);
	meter.printData("FibonacciAlg4(50)");
	meter.measure(nom,calculateNthFibonacciNumber4,100);
	meter.printData("FibonacciAlg4(100)");
	meter.measure(nom,calculateNthFibonacciNumber4,200);
	meter.printData("FibonacciAlg4(200)");

	meter.measure(nom,calculateNthFibonacciNumber5,20);
	meter.printData("FibonacciAlg5(20)");
	meter.measure(nom,calculateNthFibonacciNumber5,30);
	meter.printData("FibonacciAlg5(30)");
	meter.measure(nom,calculateNthFibonacciNumber5,50);
	meter.printData("FibonacciAlg5(50)");
	meter.measure(nom,calculateNthFibonacciNumber5,100);
	meter.printData("FibonacciAlg5(100)");
	meter.measure(nom,calculateNthFibonacciNumber5,200);
	meter.printData("FibonacciAlg5(200)");

	//i dont measure calculateFibonacciNumbers6 because it is a look up table and has constant time

	return 0;
}
