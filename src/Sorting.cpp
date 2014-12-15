#include <Sorting.h>


template <typename T>
void Sorting::insertionSort(vector<T> &toSort)
{
    //if already sorted
    if(toSort.size() == 0 || toSort.size() == 1)
    {}
    else
    {
        T i, j;
        T element;

        for(i = 1; i < toSort.size();i++)
        {
        //cout << "insertion sort loop" << endl;
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

}

template <typename T>
void Sorting::quickSort(vector<T> &toSort)
{
    T ends = toSort.size() - 1;
    if(toSort.size() < 40)
    {
        insertionSort(toSort);
    }
    else
    {
        //cout << "index ends of toSort : " << ends << endl;
        quickSortHelp(toSort,0,ends);
    }

}

template <typename T>
void Sorting::quickSortHelp(vector<T> &toSort, int beginning, int end)
{
    if(end-beginning >= 1)
    {
        int partition = qs_partition(toSort,beginning,end);
        //cout << "partition is : " << partition << endl;
        //cout << "beginning : " << beginning << " end : " << end << endl;
        quickSortHelp(toSort,beginning,partition-1);
        quickSortHelp(toSort,partition + 1,end);
    }
}

template <typename T>
int Sorting::qs_partition(vector<T> &toSort,int beginning,int end)
{
    T pivot = medianOfThree(toSort,beginning,end);
    //cout << "pivot : " << pivot << endl;
    int left = beginning - 1;
    int right = end - 1 + 1; // - 1 for swap in medianofthree;
    for(;;)
    {
        //left = left + 1;
        while(toSort[left] < pivot && left < end)
        {
            left = left + 1;
        }
        //right = right - 1;
        while(toSort[right] > pivot && right > beginning)
        {
            right = right - 1;
        }
        if(right > left)
        {
            swap(toSort,left,right);
            if(toSort[left] == toSort[right])
            {
                left = left + 1;
            }
        }
        else
        {
            return left;
        }

    }
}

template <typename T>
T Sorting::medianOfThree(vector<T> &toLook,int left,int right)
//returns the median out of three positions(beginning, end , and middle) of the array
{
   int middle = (left + right) / 2;

    if(toLook[left] > toLook[middle])
    {
        swap(toLook,left,middle);
    }
    if(toLook[left] > toLook[right])
    {
        swap(toLook,left,right);
    }
    if(toLook[middle] > toLook[right])
    {
        swap(toLook,middle,right);
    }
    swap(toLook,middle,right-1);
    return toLook[right-1];
}

template <typename T>
T Sorting::median(vector<T> &a, int begs, int ends)
{
    //returns element that is the median in array a
    //takes linear time -> nth element takes linear time
    int midIndex = (ends + begs) / 2;
    nth_element(a.begin()+begs,a.begin() + midIndex,a.begin()+ends);
    return a[midIndex];
}

template <typename T>
void Sorting::merges(vector<T> &toSort, T low, T high, T mid)
{
    T i,j,k;
    vector<T> clone(toSort);
    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(toSort[i] < toSort[j])
        {
            clone[k] = toSort[i];
            k++;
            i++;
        }
        else
        {
            clone[k] = toSort[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        clone[k] = toSort[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        clone[k] = toSort[j];
        k++;
        j++;
    }
    for(i = low; i < k;i++)
    {
        toSort[i] = clone[i];
    }
}

template <typename T>
void Sorting::mergeSort(vector<T> &toSort)
{
    T length = toSort.size() - 1;
    if(toSort.size() < 40)
    {
        insertionSort(toSort);
    }
    else
    {
        mergeSortHelp(toSort,0,length);
    }

}

template <typename T>
void Sorting::mergeSortHelp(vector<T> &toSort, T low, T high)
{
    T mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        mergeSortHelp(toSort,low,mid);
        mergeSortHelp(toSort,mid+1,high);
        merges(toSort,low,high,mid);
    }
    return;
}


//for gtest
template <typename T>
bool Sorting::isSorted(vector<T> &toCheck)
{
    for(unsigned int i = 0; i < toCheck.size();i = i + 2)
    {
        //cout << toCheck[i] << " " << toCheck[i+1] << endl;
        if(toCheck[i] > toCheck[i+1]) return false;
    }
    return true;
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

// WAYS TO FILL IN VECTORS
template <typename T>
void Sorting::addRandomNumbers(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {

    }
    srand(time(NULL));
    T element;

    for(int i = 0; i < toFill.size(); i++)
    {
        element = rand() % 101;
        toFill[i] = element;
    }
    return;
}

template <typename T>
void Sorting::addPermutedNumbers(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {

    }
    srand(time(NULL));
    T element = rand() % 101;
    T x = rand() % toFill.size() / 4;
    for(int i = 0; i < toFill.size();i++)
    {
        if(i == x) element = rand() % 101;
        toFill[i] = element;
    }
}

template <typename T>
void Sorting::addSortedNumbers(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {
        cout << "no place to fill in vector!" << endl;
    }
    for(int i = 0;i < toFill.size();i++)
    {
        toFill[i] = i;
    }
}

template <typename T>
void Sorting::addReverseSortedNumbers(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {

    }
    T j = toFill.size();

    for(int i = 0;i < toFill.size();i++)
    {
        toFill[i] = j;
        j--;
    }
}

template <typename T>
void Sorting::addRepeatedNumber(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {

    }
    T element;
    srand(time(NULL));
    element = rand() % 101;
    for(int i = 0; i < toFill.size();i++)
    {
        toFill[i] = element;
    }
}
template <typename T>
void Sorting::swap(vector<T> &toWork,int i,int j)
{
    if(i == j || toWork[i] ==  toWork[j])
    {
    }
    else
    {
        //cout << "Swapping : " << toWork[i] << " : " << toWork[j] << endl;
        T tmp = toWork[i];
        toWork[i] = toWork[j];
        toWork[j] = tmp;
        //Sorting::printOut(toWork);
    }
}
/*
void Sorting::init()
{
    vector<int> toSort(10,0);
    Sorting::addRandomNumbers(toSort);
    Sorting::isSorted(toSort);
    //Sorting::insertionSort(toSort);
    int length = toSort.size();
    Sorting::quickSort(toSort);
    Sorting::mergeSort(toSort);
    Sorting::quickSorthelp(toSort,0,length);
    Sorting::mergeSorthelp(toSort,0,length);
    Sorting::printOut(toSort);

}
*/
//template class Sorting<int>;
template void Sorting::swap<int>(vector<int>&,int,int);
template int Sorting::median<int>(vector<int>&,int,int);
template int Sorting::qs_partition<int>(vector<int>&,int,int);

template void Sorting::addRandomNumbers<int>(vector<int>&);
template void Sorting::addPermutedNumbers<int>(vector<int>&);
template void Sorting::addRepeatedNumber<int>(vector<int>&);
template void Sorting::addReverseSortedNumbers<int>(vector<int>&);
template void Sorting::addSortedNumbers<int>(vector<int>&);
template bool Sorting::isSorted<int>(vector<int>&);

template void Sorting::mergeSort<int>(vector<int>&);
template void Sorting::quickSort<int>(vector<int>&);
template void Sorting::insertionSort<int>(vector<int>&);

template void Sorting::printOut<int>(vector<int>&);

