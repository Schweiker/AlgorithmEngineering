#include "includes/Sorting.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));

    int numbersOfElements = 5;
    int element;

    vector<int64_t> toSort (numbersOfElements,0);

    for(int i = 0; i < numbersOfElements; i++)
    {
        element = rand() % 11;
        toSort[i] = element;
    }
    //for quicksort we use the same array as for insertion sort
    vector<int64_t> clone(toSort);

    cout << "starting to sort" << endl;
    Sorting::printOut(toSort, numbersOfElements);

    Sorting::quickSort(clone,0,numbersOfElements);
    Sorting::insertionSort(toSort, numbersOfElements);
    cout << "Finished Sorting" << endl;
    Sorting::printOut(toSort, numbersOfElements);
    Sorting::printOut(clone, numbersOfElements);

return 0;
};

