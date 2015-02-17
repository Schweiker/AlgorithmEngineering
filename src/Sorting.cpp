#include <Sorting.h>

template <typename T>
void swap(vector<T> &toWork,int i,int j)
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


template <typename T>
void insertionSort(vector<T> &toSort)
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
T medianOfThree(vector<T> &toLook,int left,int right)
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
int qs_partition(vector<T> &toSort,int beginning,int end)
{
    //normal partition

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
int threeWayPartition(vector<T> &toSort,int l,int r)
{
    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;
    T pivot = medianOfThree(toSort,l,r);

    for(;;)
    {
        while(toSort[++i] < pivot);
        while(pivot < toSort[--j])
        {
            if(j == 1)
            {
                break;
            }
        }
        if(i >= j) break;
        swap(toSort,i,j);
        if(toSort[i] == pivot)
        {
            p++;
            swap(toSort,p,i);
        }
        if(pivot == toSort[j])
        {
            q--;
            swap(toSort,j,q);
        }
    }
    swap(toSort,i,r);
    j = i - 1;
    i = i + 1;

    for(int k = 1;k < p; k++,j--)
    {
        swap(toSort,k,j);
    }
    for(int k = r - 1;k > q;k--,i++)
    {
        swap(toSort,i,k);
    }
    return i;
}


template <typename T>
void quickSortHelp(vector<T> &toSort, int beginning, int end)
{
    if(end-beginning >= 1)
    {
        int partition = threeWayPartition(toSort,beginning,end);
        //cout << "partition is : " << partition << endl;
        //cout << "beginning : " << beginning << " end : " << end << endl;
        quickSortHelp(toSort,beginning,partition - 1);
        quickSortHelp(toSort,partition + 1,end);
    }
}



template <typename T>
void quickSort(vector<T> &toSort)
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
T median(vector<T> &a, int begs, int ends)
{
    //returns element that is the median in array a
    //takes linear time -> nth element takes linear time
    int midIndex = (ends + begs) / 2;
    nth_element(a.begin()+begs,a.begin() + midIndex,a.begin()+ends);
    return a[midIndex];
}

template <typename T>
void merges(vector<T> &toSort,int l, int m, int r,vector<T> tmp)
{
/* attempt to in place merge, but the routine does not sort right
    int i,j,k;
    int n1 = m - l;
    int n2 = r - m;

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(toSort[l+i] <= toSort[m+1+j])
        {
            swap(toSort,l+i,k);
            i++;
        }
        else
        {
            swap(toSort,m+j+1,k);
            j++;
        }
        k++;
    }
*/
    int i1 = l;
    int i2 = m;
    for(int i = 0; i < r-l; i++)
    {
        if(i1 < m && i2 < r)
        {
            if(toSort[i1] <= toSort[i2])
            {
                tmp[i] = toSort[i1++];
            }
            else
            {
                tmp[i] = toSort[i2++];
            }
        }
        else
        {
            if(i1 == m)
            {
                tmp[i] = toSort[i2++];
            }
            else
            {
                tmp[i] = toSort[i1++];
            }
        }
    }
    for(int i = 0; i < r - l; i++)
    {
        toSort[l + i] =  tmp[i];
    }
    return;
}


template <typename T>
void mergesort(vector<T> &toSort,int low , int high, vector<T> &tmp)
{
    if(high - low >= 2)
    {
        int m = low + ((high - low)/2);
        mergesort(toSort,low,m,tmp);
        mergesort(toSort,m,high,tmp);
        merges(toSort,low,m,high,tmp);
    }
}

template <typename T>
void mergeSort(vector<T> &toSort)
{
    int length = toSort.size();
    vector<T> tmp = vector<T>(toSort.size());
    mergesort(toSort,0,length,tmp);

}

template<typename T>
void csort(vector<T> &toSort)
{
    std::sort(toSort.begin(),toSort.end());
}


//for gtest
template <typename T>
bool isSorted(vector<T> &toCheck)
{
    for(unsigned int i = 0; i < toCheck.size();i = i + 2)
    {
        //cout << toCheck[i] << " " << toCheck[i+1] << endl;
        if(toCheck[i] > toCheck[i+1]) return false;
    }
    return true;
}



template <typename T>
void printOut(vector<T> &toPrint)
{
    for(int i = 0; i < toPrint.size();i++)
    {
        cout << toPrint[i] << " ";
    }
    cout << endl;

}

// WAYS TO FILL IN VECTORS
template <typename T>
void addRandomNumbers(vector<T> &toFill)
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
void addPermutedNumbers(vector<T> &toFill)
{
    if(toFill.size() == 0)
    {

    }
    else
    {
        srand(time(NULL));
        T element = rand() % 101;
        T x = rand() % toFill.size() / 4;
        for(int i = 0; i < toFill.size();i++)
        {
            if(i == x)
            {
                element = rand() % 101;
                x = i * 2;
            }
            toFill[i] = element;
        }
    }
}

template <typename T>
void addSortedNumbers(vector<T> &toFill)
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
void addReverseSortedNumbers(vector<T> &toFill)
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
void addRepeatedNumber(vector<T> &toFill)
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

template void addRandomNumbers<int>(vector<int>&);
template void addPermutedNumbers<int>(vector<int>&);
template void addRepeatedNumber<int>(vector<int>&);
template void addReverseSortedNumbers<int>(vector<int>&);
template void addSortedNumbers<int>(vector<int>&);
template bool isSorted<int>(vector<int>&);

template void mergeSort<int>(vector<int>&);
template void quickSort<int>(vector<int>&);
template void insertionSort<int>(vector<int>&);
template void csort<int>(vector<int>&);

template int qs_partition<int>(vector<int>&,int,int);

template void printOut<int>(vector<int>&);

