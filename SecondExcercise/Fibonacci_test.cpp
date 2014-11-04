#include "Fibonacci.h"
#include <iostream>
using namespace std;
#include "gtest/gtest.h"

TEST(FibTest, FibonacciTest)
{
	Fibonacci f;

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, f.calculateNthFibonacciNumber1(0));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber1(1));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber1(2));
	EXPECT_EQ(2, f.calculateNthFibonacciNumber1(3));
	EXPECT_EQ(3, f.calculateNthFibonacciNumber1(4));
	EXPECT_EQ(5, f.calculateNthFibonacciNumber1(5));
	EXPECT_EQ(701408733, f.calculateNthFibonacciNumber1(44));

	//Tests for second Fibonacci Implemenation

	EXPECT_EQ(0, f.calculateNthFibonacciNumber2(0));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber2(1));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber2(2));
	EXPECT_EQ(2, f.calculateNthFibonacciNumber2(3));
	EXPECT_EQ(3, f.calculateNthFibonacciNumber2(4));
	EXPECT_EQ(5, f.calculateNthFibonacciNumber2(5));
	EXPECT_EQ(701408733, f.calculateNthFibonacciNumber2(44));

	EXPECT_EQ(f.calculateNthFibonacciNumber1(0),f.calculateNthFibonacciNumber2(0));
	EXPECT_EQ(f.calculateNthFibonacciNumber1(1),f.calculateNthFibonacciNumber2(1));
	EXPECT_EQ(f.calculateNthFibonacciNumber1(2),f.calculateNthFibonacciNumber2(2));

	//Tests for third Fibonacci Implementation

	EXPECT_EQ(0, f.calculateNthFibonacciNumber3(0));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber3(1));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber3(2));
	EXPECT_EQ(2, f.calculateNthFibonacciNumber3(3));
	EXPECT_EQ(3, f.calculateNthFibonacciNumber3(4));
	EXPECT_EQ(5, f.calculateNthFibonacciNumber3(5));
	EXPECT_EQ(701408733, f.calculateNthFibonacciNumber3(44));
}



int main(int argc, char **argv)
{
	Fibonacci f;

	::testing::InitGoogleTest(&argc, argv);

	std::cout << f.calculateNthFibonacciNumber1(7) << endl;
	std::cout << f.calculateNthFibonacciNumber2(7) << endl;
	std::cout << f.calculateNthFibonacciNumber3(7) << endl;
	std::cout << f.calculateNthFibonacciNumber2(44) << endl;
	std::cout << f.calculateNthFibonacciNumber3(44) << endl;

return RUN_ALL_TESTS();
}
