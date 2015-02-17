#ifndef Sorting_h
#define Sorting_h

#include <vector>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <functional>


using namespace std;

        template <typename T>
        int qs_partition(vector<T> &toSort,int beginning,int end);

        template <typename T>
        void merges(vector<T> &toSort,int low, int high,int mid);

        template <typename T>
        void insertionSort(vector<T> &toSort);

        template <typename T>
        void quickSort(vector<T> &toSort);

        template <typename T>
        void mergeSort(vector<T> &toSort);

        template <typename T>
        bool isSorted(vector<T> &toCheck);

        template <typename T>
        void printOut(vector<T> &toPrint);

        template <typename T>
        void addRandomNumbers(vector<T> &toFill);

        template <typename T>
        void addPermutedNumbers(vector<T> &toFill);

        template <typename T>
        void addSortedNumbers(vector<T> &toFill);

        template <typename T>
        void addReverseSortedNumbers(vector<T> &toFill);

        template <typename T>
        void addRepeatedNumber(vector<T> &toFill);

        template <typename T>
        void swap(vector<T> &toWork,int i,int j);

        template <typename T>
        void csort(vector<T> &toSort);



#endif // Sorting_h
