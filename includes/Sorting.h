#ifndef Sorting_h
#define Sorting_h

#include <vector>
#include <iostream>


#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <functional>


using namespace std;
class Sorting
{
    private:

        static void init();

        template <typename T>
        static void merges(vector<T> &toSort,T low, T high,T mid);

        template <typename T>
        static T partition_quickSort(vector<T> &toSort, T left, T right);

        template <typename T>
        static void swap(vector<T> &toWork,int i,int j);

        template <typename T>
        static T medianOfThreePartition(vector<T> &toSort,T p,T r);

    public:

        template <typename T>
        static void insertionSort(vector<T> &toSort);

        template <typename T>
        static void quickSort(vector<T> &toSort);

        template <typename T>
        static void quickSorthelp(vector<T> &toSort,T left, T right);

        template <typename T>
        static void mergeSort(vector<T> &toSort);

        template <typename T>
        static void mergeSorthelp(vector<T> &toSort,T low,T high);

        template <typename T>
        static bool isSorted(vector<T> &toCheck);

        template <typename T>
        static void printOut(vector<T> &toPrint);

        template <typename T>
        static void addRandomNumbers(vector<T> &toFill);

        template <typename T>
        static void addPermutedNumbers(vector<T> &toFill);

        template <typename T>
        static void addSortedNumbers(vector<T> &toFill);

        template <typename T>
        static void addReverseSortedNumbers(vector<T> &toFill);

        template <typename T>
        static void addRepeatedNumber(vector<T> &toFill);
};


#endif // Sorting_h