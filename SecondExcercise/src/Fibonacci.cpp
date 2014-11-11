
#include <iostream>
#include <fstream>
using namespace std;
#include "gtest/gtest.h"

char lookUp[50];

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

void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

//get nth power of matrix F
void power(int F[2][2], int n)
{
  int i;
  int M[2][2] = {{1,1},{1,0}};

  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}


int calculateNthFibonacciNumber4(int n)
{
  int F[2][2] = {{1,1},{1,0}};

  if (n == 0)

      return 0;

  power(F, n-1);

  return F[0][0];
}

//simple matrix multiplikation


//calculates Nth Fibonacci Number in O(log n) time
int calculateNthFibonacciNumber5(int n)
{
	int i = n - 1;
	int a = 1;
	int b = 0;
	int c = 0;
	int d = 1;
	int t;
	if(n <= 0) return 0;
	while(i > 0)
	{
		while(i % 2 == 0)
		{
			t = d * (2 * c + d);
			c = c * c + d * d;
			d = t;
			i = i / 2;
		}
		t = d * (b + a) + c * b;
		a = d * b + c * a;
		b = t;
		i--;
	}
	return a + b;
}


void buildLookUpTable()
{

	for(int i = 0; i <= 50; i++)
	{
		lookUp[i] = calculateNthFibonacciNumber5(i);
	}
}

int calculateNthFibonacciNumber6(int n)
{
	int number = lookUp[n];
	return number;
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
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber1(44));

	//Tests for second Fibonacci Implemenation

	EXPECT_EQ(0, calculateNthFibonacciNumber2(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber2(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber2(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber2(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber2(5));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber2(44));

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
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber3(44));

	//Tests for fourth Fibonacci implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber4(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber4(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber4(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber4(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber4(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber4(5));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber4(44));

	//Tests for fifth Fibonacci implementation

	EXPECT_EQ(0, calculateNthFibonacciNumber5(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber5(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber5(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber5(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber5(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber5(5));
	//EXPECT_EQ(701408733, calculateNthFibonacciNumber5(44));




}

TEST(FibonacciLookUpTableTest, FibonacciTest)
{
    //Tests for sixth Fibonacci Implementation
    EXPECT_EQ(0, calculateNthFibonacciNumber6(0));
	EXPECT_EQ(1, calculateNthFibonacciNumber6(1));
	EXPECT_EQ(1, calculateNthFibonacciNumber6(2));
	EXPECT_EQ(2, calculateNthFibonacciNumber6(3));
	EXPECT_EQ(3, calculateNthFibonacciNumber6(4));
	EXPECT_EQ(5, calculateNthFibonacciNumber6(5));
	//Here the Test is failing, i think because of Overflow of the int.
	EXPECT_EQ(701408733, calculateNthFibonacciNumber6(44));

}


int main(int argc, char **argv)
{
	buildLookUpTable();
	::testing::InitGoogleTest(&argc, argv);


	std::cout << calculateNthFibonacciNumber1(0) << endl;
	std::cout << calculateNthFibonacciNumber2(1) << endl;
	std::cout << calculateNthFibonacciNumber3(2) << endl;
	std::cout << calculateNthFibonacciNumber2(3) << endl;
	std::cout << calculateNthFibonacciNumber3(4) << endl;
	std::cout << calculateNthFibonacciNumber4(5) << endl;

	std::cout << calculateNthFibonacciNumber5(6) << endl;


	cout << calculateNthFibonacciNumber6(7) << endl;

return RUN_ALL_TESTS();
}
