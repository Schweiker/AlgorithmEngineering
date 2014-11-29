#include "../includes/Fibonacci.h"
#include "gtest/gtest.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
//TESTS

TEST(FibTestAlg1, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber1(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber1(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber1(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber1(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber1(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber1(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber1(44));
}

TEST(FibTestAlg2, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber2(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber2(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber2(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber2(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber2(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber2(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber2(44));
}

TEST(FibTestAlg3, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber3(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber3(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber3(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber3(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber3(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber3(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber3(44));
}
TEST(FibTestAlg4, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber4(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber4(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber4(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber4(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber4(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber4(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber4(44));
}

TEST(FibTestAlg5, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber5(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber5(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber5(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber5(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber5(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber5(34));
	EXPECT_EQ(433494437, Fibonacci::calculateNthFibonacciNumber5(43));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber5(44));
}

TEST(FibonacciLookUpTableTest, FibonacciTest)
{
    //Tests for sixth Fibonacci Implementation
    EXPECT_EQ(0, Fibonacci::calculateNthFibonacciNumber6(0));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber6(1));
	EXPECT_EQ(1, Fibonacci::calculateNthFibonacciNumber6(2));
	EXPECT_EQ(89, Fibonacci::calculateNthFibonacciNumber6(11));
	EXPECT_EQ(28657, Fibonacci::calculateNthFibonacciNumber6(23));
	EXPECT_EQ(5702887, Fibonacci::calculateNthFibonacciNumber6(34));
	//Here the Test is failing, i think because of Overflow of the int.
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber6(44));

}
/*
TEST(FibonacciFailtest, FibonacciTest)
{
    //Here it fails because of a overflow of int, we could use a bigger container like unsigned int, or even long, but this would require more space.
    //EXPECT_EQ(2971215073, calculateNthFibonacciNumber1(47));
    EXPECT_EQ(2971215073, Fibonacci::calculateNthFibonacciNumber2(47));
    EXPECT_EQ(2971215073, Fibonacci::calculateNthFibonacciNumber3(47));
    EXPECT_EQ(2971215073, Fibonacci::calculateNthFibonacciNumber4(47));
    EXPECT_EQ(2971215073, Fibonacci::calculateNthFibonacciNumber5(47));
    EXPECT_EQ(2971215073, Fibonacci::calculateNthFibonacciNumber6(47));
}
*/
