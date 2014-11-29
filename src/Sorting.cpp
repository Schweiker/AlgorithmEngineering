#include "../includes/Sorting.h"
using namespace std;

template <typename T>
void Sorting::insertionSort(vector<T> &toSort)
{
    T i, j;
    T element;

    for(i = 1; i < toSort.size();i++)
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



template <typename T>
void Sorting::quickSort(vector<T> &toSort, int left, int right)
{
    T i = left;
    T j = right;
    T element;
    T pivot = toSort[(left + right) / 2];

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
    if(i < right && right < toSort.size()) quickSort(toSort, i, right);
}
template <typename T>
bool Sorting::isSorted(T a, T b)
{
    if(a > b) return false;
    if(a <= b) return true;
}

template <typename T>
void Sorting::printOut(vector<T> &toPrint)
{
    for(int i = 0; i < toPrint.size();i++)
    {
        cout << toPrint[i] << " ";
    }
    cout << endl;

}

