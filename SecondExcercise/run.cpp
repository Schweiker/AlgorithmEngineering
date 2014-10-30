#include "Fibonacci.h"
#include <iostream>
#include "gtest/gtest.h"



int main(int argc, char **argv)
{
	Fibonacci f;

	::testing::InitGoogleTest(&argc, argv);

	int res = f.calculateNthFibonacciNumber(7);

	std::cout << res;

	std::cout << f.calculateNthFibonacciNumber(7);

return RUN_ALL_TESTS();
};
