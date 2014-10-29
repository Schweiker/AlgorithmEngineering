/*
 * Fibonacci.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Schweiker
 */

#include "Fibonacci.h"

int Fibonacci::calculateNthFibonacciNumber(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test
	int res = 0;
	if(n <= 2)
	{
	return 1;
	}
	else
	{
		return res + calculateNthFibonacciNumber(n - 1) + calculateNthFibonacciNumber(n -2);
	}
}

