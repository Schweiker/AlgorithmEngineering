#ifndef Sorting_h
#define Sorting_h

#include <vector>
#include <iostream>


using namespace std;

class Sorting
{

    public:

        static void insertionSort(vector<int64_t> &toSort, int n);

        static void quickSort(vector<int64_t> &toSort, int left, int right);

        static void printOut(vector<int64_t> &toPrint, int n);
};


#endif // Sorting_h
