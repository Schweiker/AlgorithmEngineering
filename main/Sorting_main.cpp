
#include <iostream>
#include <stdlib.h>
#include <typeinfo>

#include "../includes/Sorting.h"



using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));

    int numbersOfElements = 5;
    int element;

    vector<int> toSort (numbersOfElements,0);

    for(int i = 0; i < numbersOfElements; i++)
    {
        element = rand() % 101;
        toSort[i] = element;
    }
    //for quicksort we use the same array as for insertion sort
    vector<int> clone(toSort);

    cout << "starting to sort" << endl;
    Sorting::printOut(toSort);

    Sorting::quickSort(clone,0,clone.size() - 1);
    Sorting::insertionSort(toSort);
    cout << "Finished Sorting" << endl;
    Sorting::printOut(toSort);
    Sorting::printOut(clone);

return 0;
};

