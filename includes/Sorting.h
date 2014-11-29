#ifndef Sorting_h
#define Sorting_h

#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;
class Sorting
{

    public:

        template <typename T>
        static void insertionSort(vector<T> &toSort);
        template <typename T>
        static void quickSort(vector<T> &toSort,int left, int right);
        template <typename T>
        static bool isSorted(T a, T b);
        template <typename T>
        static void printOut(vector<T> &toPrint);
};


#endif // Sorting_h
