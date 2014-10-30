/*
 * Fibonacci_test.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Schweiker
 */

#include "Fibonacci.h"
#include "limits.h"
#include "gtest/gtest.h"
#include <iostream>

class FibonacciTest : public ::testing::Test
{
	Fibonacci f;

	TEST(fibonaccitest, isRight)
	{
		std::cout << "doing tests";
		EXPECT_EQ(1, f.calculateNthFibonacciNumber(1));
		EXPECT_EQ(2, f.calculateNthFibonacciNumber(1));
		EXPECT_EQ(3, f.calculateNthFibonacciNumber(2));
		EXPECT_EQ(4, f.calculateNthFibonacciNumber(3));
		EXPECT_EQ(5, f.calculateNthFibonacciNumber(5));
		EXPECT_EQ(6, f.calculateNthFibonacciNumber(8));
		EXPECT_EQ(7, f.calculateNthFibonacciNumber(13));

	}

};


