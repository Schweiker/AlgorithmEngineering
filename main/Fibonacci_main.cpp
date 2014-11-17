#include <iostream>
using namespace std;
#include "../src/Fibonacci.cpp"

int main(int argc, char **argv)
{

    for(int i = 0; i <= 40; i++)
    {
        cout << calculateNthFibonacciNumber5(i) << endl;
    }

return 0;
}
