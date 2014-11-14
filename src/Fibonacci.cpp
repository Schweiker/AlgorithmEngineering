using namespace std;
#include "gtest/gtest.h"
#include <vector>
//#include <math.h>
using namespace std;
#include <cmath>

vector<int> lookUp = vector<int>(100);

int calculateNthFibonacciNumber1(int n)
{
	//standard implementation of fibonacci
	//runs in exponential time and needs exponential space
	//not test
	if(n < 0) return -1;

	if(n == 0) return 0;

	if(n == 1) return 1;

	return calculateNthFibonacciNumber1(n - 1) + calculateNthFibonacciNumber1(n -2);

}

int calculateNthFibonacciNumber2(int n)
{
	//Implementation of Fibonacci with an Array.
	//It needs just linear Time and linear Space
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;
	vector<int> numbers = vector<int>(n);
	numbers[0] = 0;
	numbers[1] = 1;
	for(int i = 2; i < n;i++)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	}
	return numbers[n - 1] + numbers[n - 2];
}

int calculateNthFibonacciNumber3(int n)
{
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;
	//Implementation of Fibonacci with 3 Variables
	//It needs linear time but constant Space
    //defines a vector with 2 variables
    //first none holds FibonacciNumbers of even n
    //second one holds FibonacciNumbers of odd n
    int twoNumbers[2];

    twoNumbers[0] = 0;
    twoNumbers[1] = 1;

    for(int i = 2;i < n;i++)
    {
        //when i is even -> update even Variable
        if(i % 2 == 0)
        {
            twoNumbers[0] += twoNumbers[1];
        }
        //odd -> update odd variable
        else
        {
            twoNumbers[1] += twoNumbers[0];
        }
        //return the nth Fib-Number
    }
    return twoNumbers[0] + twoNumbers[1];

}
//simple matrix multiplikation
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
    //runs in O(log n) time needs constant space
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;

    int F[2][2] = {{1,1},{1,0}};

    if (n == 0) return 0;

    power(F, n-1);

    return F[0][0];
}

int calculateNthFibonacciNumber5(double n)
{
    //needs O(log n) time and constant space
	if(n < 0) return -1;
	if(n == 0) return 0;
	if(n == 1) return 1;

    double result;
    result = (pow(1 + sqrt(5.0),n) - pow(1 - sqrt(5.0),n)) / (pow(2,n) * sqrt(5.0));

    //static const double phi = (1+sqrt(5))*0.5;
    //double number = pow(1-phi,n)/sqrt(5);
    return (int)result;
}

//lookup table needs constant time and needs O(1) time.
int calculateNthFibonacciNumber6(int n)
{
	if(n < 0 || n > 40) return -1;
	int numbers[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368,
                            75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169,
                            63245986, 102334155};
    return numbers[n];
}
