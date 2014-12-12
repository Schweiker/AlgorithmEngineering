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
    T length = toSort.size() - 1;
    quickSorthelp(toSort,0, length);
}
/*
template <typename T>
T Sorting::getMedian(vector<T> &toCheck)
{
    cout << "getting median" << endl;
    T length = toCheck.size() - 1;
    T median = toCheck.size()/2;
    cout << median << endl;
    median = selectkth(toCheck,0,length,median);
    return median;
}

//gets the kth element -> array.size() / 2 gets median
//takes O(n)
template <typename T>
T Sorting::selectkth(vector<T> &toCheck, T p, T r, T k)
{
    cout << "select kth" << endl;
    if(p == r)
    {
        return p;
    }
    else
    {
    cout << p << " < | > " << r << endl;
    cout << "partition call in selectkth" << endl;
    T j = partition_quickSort(toCheck,p,r);
    cout << "length : " << j << endl;
    T length = j - p + 1;
    cout << "length : " << length<< endl;
    if(length == k) return j;
    else if(k < length) return selectkth(toCheck,p,j-1,k);
    else return selectkth(toCheck,j + 1, r, k-length);
    }

}
*/
/*
template <typename T>
T Sorting::partition_quickSort(vector<T> &toSort, T p, T r)
{
    cout << "partition" << endl;
    Sorting::printOut(toSort);
    std::nth_element(toSort.begin(),toSort.begin() + toSort.size()/2, toSort.end());
    Sorting::printOut(toSort);
    //T median = toSort[toSort.size()/2];
    cout << "median : " << median << endl;

    while(p < r)
    {
        cout << "p = " << p << endl;
        cout << "toSort[p] = " << toSort[p] << endl;
        cout << "r = " << r << endl;
        cout << "toSort[r] = " << toSort[r] << endl;

        while(toSort[p] < median)
        {
            cout << "while 1" << endl;
            p = p + 1;
            cout << "p : " << p << endl;
        }
        while(toSort[r] > median)
        {
            cout << "while 2" << endl;
            r = r - 1;
            cout << "r : " << p << endl;
        }
        if(toSort[p] == toSort[r])
        {
            cout << "if" << endl;
            p = p + 1;
            cout << "p : " << p << endl;
        }
        else if(p < r)
        {
            cout << "else if" << endl;
            T tmp = toSort[p];
            toSort[p] = toSort[r];
            toSort[r] = tmp;
        }
    }
    cout << "r : " <<r << endl;
    return r;
}
*/

template <typename T>
void Sorting::quickSorthelp(vector<T> &toSort, T start, T ends)
{
    T q = ends -start;
    if(q < 2) return;
    q = medianOfThreePartition(toSort,start,ends);
    quickSorthelp(toSort,start,q - 1);
    quickSorthelp(toSort,q + 1,ends);
}

template <typename T>
T Sorting::medianOfThreePartition(vector<T> &toSort,T p,T r)
{
    T counts;
    T x = toSort[p];
    T y = toSort[(r - p)/2+p];
    T z = toSort[r];
    T i = p - 1;
    T j = r;

    cout << "x : " << x << " y : " << y << " z : " << z << "i : " << i << " toSort[i]: " << toSort[i] << " j" << j << "toSort[j]" <<toSort[j] << endl;

    if((y > x && y < z) || (y > z && y < x))
    {
        x = y;
    }
    else if((z > x && z < y) || (z > y && z < x))
    {
        x = z;
    }
    while(1)
    {
        //cout << "loop mofuckers" << endl;
        cout << toSort[i] << " : " << toSort[j] << endl;
        while(toSort[j] >= x)
        {
            j--;
            counts++;
        }
        while(toSort[i] < x)
        {
            i++;
            counts++;
        }
        if(i < j && toSort[i] != toSort[j])
        {
            swap(toSort,i,j);
        }
        else
        {
             return j+1;
        }
    }
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
    mergeSorthelp(toSort,0,length);
}

template <typename T>
void Sorting::mergeSorthelp(vector<T> &toSort, T low, T high)
{
    T mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        mergeSorthelp(toSort,low,mid);
        mergeSorthelp(toSort,mid+1,high);
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
        T tmp = toWork[i];
        toWork[i] = toWork[j];
        toWork[j] = tmp;
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

template void Sorting::addRandomNumbers<int>(vector<int>&);
template void Sorting::addPermutedNumbers<int>(vector<int>&);
template void Sorting::addRepeatedNumber<int>(vector<int> &);
template void Sorting::addReverseSortedNumbers<int>(vector<int>&);
template void Sorting::addSortedNumbers<int>(vector<int>&);
template bool Sorting::isSorted<int>(vector<int>&);

template void Sorting::mergeSort<int>(vector<int>&);
template void Sorting::quickSort<int>(vector<int>&);
template void Sorting::insertionSort<int>(vector<int>&);

template void Sorting::printOut<int>(vector<int>&);

