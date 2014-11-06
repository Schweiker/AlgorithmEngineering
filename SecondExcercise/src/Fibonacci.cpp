
#include <iostream>
using namespace std;
#include "gtest/gtest.h"

int calculateNthFibonacciNumber1(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test

	if(n == 0) return 0;

	if(n == 1) return 1;

	return calculateNthFibonacciNumber1(n - 1) + calculateNthFibonacciNumber1(n -2);

}

int calculateNthFibonacciNumber2(int n)
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

int calculateNthFibonacciNumber3(int n)
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


//TESTS


TEST(FibTest, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber1(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber1(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber1(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber1(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber1(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber1(5));
	EXPECT_EQ(701408733, calculateNthFibonacciNumber1(44));

	//Tests for second Fibonacci Implemenation

	EXPECT_EQ(0, calculateNthFibonacciNumber2(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber2(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber2(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber2(5));
	EXPECT_EQ(701408733, calculateNthFibonacciNumber2(44));

	EXPECT_EQ(calculateNthFibonacciNumber1(0),calculateNthFibonacciNumber2(0));
	EXPECT_EQ(calculateNthFibonacciNumber1(1),calculateNthFibonacciNumber2(1));
	EXPECT_EQ(calculateNthFibonacciNumber1(2),calculateNthFibonacciNumber2(2));

	//Tests for third Fibonacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber3(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber3(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber3(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber3(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber3(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber3(5));
	EXPECT_EQ(701408733, calculateNthFibonacciNumber3(44));
}


int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

	std::cout << calculateNthFibonacciNumber1(7) << endl;
	std::cout << calculateNthFibonacciNumber2(7) << endl;
	std::cout << calculateNthFibonacciNumber3(7) << endl;
	std::cout << calculateNthFibonacciNumber2(44) << endl;
	std::cout << calculateNthFibonacciNumber3(44) << endl;

return RUN_ALL_TESTS();
}