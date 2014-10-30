/*
 * Fibonacci.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Schweiker
 */

#include "Fibonacci.h"
#include <iostream>

int Fibonacci::calculateNthFibonacciNumber(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test
<<<<<<< HEAD
	if(n == 0) return 0;

	if(n == 1) return 1;

	std::cout << "going recursive";
	return calculateNthFibonacciNumber(n - 1) + calculateNthFibonacciNumber(n -2);

=======
	int res = 0;
	if(n <= 2)
	{
	return 1;
	}
	else
	{
		return res + calculateNthFibonacciNumber(n - 1) + calculateNthFibonacciNumber(n -2);
	}
>>>>>>> 0f7639ace315b7dd1425879c2e72158558d85012
}

