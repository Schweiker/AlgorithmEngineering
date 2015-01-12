#include <Introsort.h>
#include <Heapsort.h>
#include <Sorting.h>

template<typename T>
void introsort_recursive(vector<T> &toSort,int first,int last,int depth)
{
    while(last - first > 0)
    {
        if(depth == 0)
        {
            _heapsort(toSort, first, last-first+1);
        }
        else
        {
            int pivot;
            if(isSorted(toSort))
            {
                break;
            }
            pivot = qs_partition(toSort,first,last);
            introsort_recursive(toSort,pivot + 1,last,depth - 1);
            last = pivot - 1;
        }
    }
}

template<typename T>
void _insertion (vector<T> &a, int n)
{
	int i;
	for (i = 1; i < n; i++ ) {
		int j;
		T save = a[i];
		for ( j = i; j >= 1 && a[j - 1] > save; j-- )
			a[j] = a[j - 1];
		a[j] = save;
	}
}

template<typename T>
void _introsort(vector<T> &toSort,int n)
{
    introsort_recursive(toSort,0,n-1,(int(2*log(double(n)))));
    _insertion(toSort,n);
}

template<typename T>
void introsort(vector<T> &toSort)
{
    int length = toSort.size();
    _introsort(toSort, length);
}
/*
template<typename T>
void doheap(vector<T> &heap,int begin,int end)
{
    T save = heap[begin];
    while(begin <= end / 2)
    {
        int k = 2* begin;
        while(k < end && heap[k] < heap[k+1])
        {
            ++k;

            if(save >= heap[k])
            {
                break;
            }
            heap[begin] = heap[k];
            begin = k;
        }
        heap[begin] = save;
    }
}

template<typename T>
void _heapsort(vector<T> &heap,int begin,int end)
{
    int i;
    for(int i = (end - 1) / 2;i >= begin; i--)
    {
        doheap(heap,i,end-1);
    }
    for(i = end-1; i > begin;i--)
    {
        swap(heap,i,begin);
        doheap(heap,begin,i-1);
    }
}
*/

template void introsort<int>(vector<int>&);
template void _insertion<int>(vector<int>&,int);
