#ifndef heapsort_h
#define heapsort_h

#include <Sorting.h>
#include <vector>
#include <iostream>

using namespace std;

        template<typename T>
        void doheap(vector<T> &heap,int begin,int end);

        template<typename T>
        void _heapsort(vector<T> &heap,int begin,int end);

        template<typename T>
        void heapsort(vector<T> &heap);

#endif // heapsort_h
