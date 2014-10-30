#include "Fibonacci.h"
#include <iostream>
<<<<<<< HEAD
#include "gtest/gtest.h"



int main(int argc, char **argv)
{
	Fibonacci f;

	::testing::InitGoogleTest(&argc, argv);

	int res = f.calculateNthFibonacciNumber(7);

	std::cout << res;

	std::cout << f.calculateNthFibonacciNumber(7);

return RUN_ALL_TESTS();
=======



int main()
{
	Fibonacci f;

	std::cout << f.calculateNthFibonacciNumber(1);

return 0;
>>>>>>> 0f7639ace315b7dd1425879c2e72158558d85012
};
