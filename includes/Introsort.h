#ifndef Introsort_h
#define Introsort_h

#include <Heapsort.h>
#include <Sorting.h>
#include <algorithm>
#include <math.h>

using namespace std;

template<typename T>
void introsort_recursive(vector<T> &toSort,int first,int last,int depth);

template<typename T>
void _insertion(int a[],int n);

template<typename T>
void _introsort(vector<T> &toSort,int n);

template<typename T>
void introsort(vector<T> &toSort);

#endif // Introsort_h
