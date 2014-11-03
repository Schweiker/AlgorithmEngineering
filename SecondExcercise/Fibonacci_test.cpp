#include "Fibonacci.h"
#include <iostream>
using namespace std;
#include "gtest/gtest.h"

TEST(FibTest, FibonacciTest)
{
	Fibonacci f;

	EXPECT_EQ(0, f.calculateNthFibonacciNumber(0));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber(1));
	EXPECT_EQ(1, f.calculateNthFibonacciNumber(2));
	EXPECT_EQ(2, f.calculateNthFibonacciNumber(3));
	EXPECT_EQ(3, f.calculateNthFibonacciNumber(4));
	EXPECT_EQ(5, f.calculateNthFibonacciNumber(5));
	EXPECT_EQ(701408733, f.calculateNthFibonacciNumber(44));
}



int main(int argc, char **argv)
{
	Fibonacci f;

	::testing::InitGoogleTest(&argc, argv);

	std::cout << f.calculateNthFibonacciNumber(7) << endl;
	std::cout << f.calculateNthFibonacciNumber(44) << endl;
return RUN_ALL_TESTS();
}
