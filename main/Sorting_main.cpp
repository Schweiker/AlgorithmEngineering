
#include <iostream>
#include <stdlib.h>
#include <typeinfo>

#include <Sorting.h>
#include <Heapsort.h>
#include <Introsort.h>



using namespace std;

int main()
{
    int numbersOfElements = 10;
    vector<int> a(numbersOfElements,0);
    addRandomNumbers(a);
    printOut(a);
    introsort(a);
    printOut(a);
    return 0;
}

