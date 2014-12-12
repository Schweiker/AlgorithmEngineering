
#include <iostream>
#include <stdlib.h>
#include <typeinfo>

#include <Sorting.h>



using namespace std;

int main()
{


    int numbersOfElements = 10;

    vector<int> toSort (numbersOfElements,0);

    Sorting::addRepeatedNumber(toSort);
    //for quicksort we use the same array as for insertion sort
    vector<int> clone1(toSort);
    //vector<int> clone2(toSort);


    cout << "starting to sort" << endl;
    //Sorting::printOut(toSort);
    Sorting::printOut(clone1);
    //Sorting::printOut(clone2);

    Sorting::quickSort(clone1);
    //Sorting::insertionSort(toSort);
    //Sorting::mergeSort(clone2);

    cout << "Finished Sorting" << endl;
    //Sorting::printOut(toSort);
    Sorting::printOut(clone1);
    //Sorting::printOut(clone2);

return 0;
}

