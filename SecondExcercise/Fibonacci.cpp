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

	if(n == 0) return 0;

	if(n == 1) return 1;

	std::cout << "going recursive";
	return calculateNthFibonacciNumber(n - 1) + calculateNthFibonacciNumber(n -2);

}

