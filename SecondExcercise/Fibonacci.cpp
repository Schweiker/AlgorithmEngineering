/*
 * Fibonacci.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Schweiker
 */

#include "Fibonacci.h"
#include <iostream>
using namespace std;

int Fibonacci::calculateNthFibonacciNumber(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test

	if(n == 0) return 0;

	if(n == 1) return 1;

	return calculateNthFibonacciNumber(n - 1) + calculateNthFibonacciNumber(n -2);

}
