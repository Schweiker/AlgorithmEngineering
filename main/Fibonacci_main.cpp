#include <iostream>
using namespace std;
#include "../includes/Fibonacci.h"

int main(int argc, char **argv)
{

    for(int i = 0; i <= 40; i++)
    {
        cout << Fibonacci::calculateNthFibonacciNumber5(i) << endl;
    }

return 0;
}
