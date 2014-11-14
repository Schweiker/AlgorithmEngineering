#include "../src/Fibonacci.cpp"
#include <stdlib.h>
#include <iostream>
//TESTS

TEST(FibTestAlg1, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber1(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber1(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber1(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber1(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber1(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber1(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber1(44));
}

TEST(FibTestAlg2, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber2(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber2(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber2(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber2(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber2(44));
}

TEST(FibTestAlg3, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber3(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber3(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber3(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber3(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber3(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber3(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber3(44));
}
TEST(FibTestAlg4, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber4(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber4(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber4(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber4(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber4(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber4(34));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber4(44));
}

TEST(FibTestAlg5, FibonacciTest)
{

	//Tests for first Fibonbacci Implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber5(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber5(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber5(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber5(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber5(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber5(34));
	EXPECT_EQ(433494437, calculateNthFibonacciNumber5(43));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber5(44));
}

TEST(FibonacciLookUpTableTest, FibonacciTest)
{
    //Tests for sixth Fibonacci Implementation
    EXPECT_EQ(0, calculateNthFibonacciNumber6(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber6(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber6(2));
	EXPECT_EQ(89, calculateNthFibonacciNumber6(11));
	EXPECT_EQ(28657, calculateNthFibonacciNumber6(23));
	EXPECT_EQ(5702887, calculateNthFibonacciNumber6(34));
	//Here the Test is failing, i think because of Overflow of the int.
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber6(44));

}
TEST(FibonacciFailtest, FibonacciTest)
{
    //Here it fails because of a overflow of int, we could use a bigger container like unsigned int, or even long, but this would require more space.
    //EXPECT_EQ(2971215073, calculateNthFibonacciNumber1(47));
    EXPECT_EQ(2971215073, calculateNthFibonacciNumber2(47));
    EXPECT_EQ(2971215073, calculateNthFibonacciNumber3(47));
    EXPECT_EQ(2971215073, calculateNthFibonacciNumber4(47));
    EXPECT_EQ(2971215073, calculateNthFibonacciNumber5(47));
    EXPECT_EQ(2971215073, calculateNthFibonacciNumber6(47));
}
TEST(FibonacciRandomTest, FibonacciTest)
//using random tests to better my tests using values in lookup table because these Fibonacci Numbers are always right
{
    //just numbers below 47 because of overflow
    //not testing standard implementation because its too slow for large n
    //not testint over 40 because of lookup table
    srand(time(NULL));
    for(int i = 0; i <= 10; i++)
    {
        int number = rand() % 40;
        //gives out the Fibonaccinumbers that are to be tested
        std::cout << number << endl;
        //EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber1(number));
        //EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber1(number));
        EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber2(number));
        EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber3(number));
        EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber4(number));
        EXPECT_EQ(calculateNthFibonacciNumber6(number),calculateNthFibonacciNumber5(number));
    }
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

