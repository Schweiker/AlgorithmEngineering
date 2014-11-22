#include "../includes/Sorting.h"
using namespace std;

void Sorting::insertionSort(vector<int64_t> &toSort, int lengthOfToSort)
{
    int i, j;
    int64_t element;

    for(i = 1; i < lengthOfToSort;i++)
    {
        element = toSort[i];
        //cout << element << endl;

        for(j = i - 1; j >= 0 && toSort[j] >= element; j--)
        {
            //cout << "shuffing elements" << endl;
            toSort[j + 1] = toSort[j];
        }
        //printOut(toSort,lengthOfToSort);
        toSort[j + 1] = element;
    }
}

void Sorting::quickSort(vector<int64_t> &toSort, int left, int right)
{
    int i = left;
    int j = right;
    int element;
    int pivot = toSort[(left + right) / 2];

    //partiition
    while(i <= j)
    {
        while (toSort[i] < pivot)
        {
            i++;
        }
        while (toSort[j] > pivot)
        {
            j--;
        }
        if(i <= j)
        {
            element = toSort[i];
            toSort[i] = toSort[j];
            toSort[j] = element;
            i++;
            j--;
        }
    };
    if(left < j) quickSort(toSort, left, j);
    if(i < right) quickSort(toSort, i, right);
}


void Sorting::printOut(vector<int64_t> &toPrint,int toPrintLength)
{
    for(int i = 0; i < toPrintLength;i++)
    {
        cout << toPrint[i] << " ";
    }
    cout << endl;

}

