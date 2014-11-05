/*
 * Fibonacci.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Schweiker
 */

#include "Fibonacci.h"
#include <iostream>
using namespace std;

int Fibonacci::calculateNthFibonacciNumber1(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test

	if(n == 0) return 0;

	if(n == 1) return 1;

	return calculateNthFibonacciNumber1(n - 1) + calculateNthFibonacciNumber1(n -2);

}

int Fibonacci::calculateNthFibonacciNumber2(int n)
{
	//Implementation of Fibonacci with an Array.
	//It needs just linear Time and linear Space

	int array[n];
	array[0] = 0;
	array[1] = 1;
	for(int i = 2; i <= n;i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
	return array[n];
}

int Fibonacci::calculateNthFibonacciNumber3(int n)
{
	//Implementation of Fibonacci with 3 Variables
	//It needs linear time but constant Space

	int a = 0;
	int b = 1;
	int c;
	if(n == 0) return a;
	for(int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}
