#include <Heapsort.h>

template<typename T>
void doheap(vector<T> &heap,int begin,int end)
{
    T save = heap[begin];
    while(begin <= end / 2)
    {
        int k = 2* begin;
        while(k < end && heap[k] < heap[k+1]) ++k;
        if(save >= heap[k]) break;
        heap[begin] = heap[k];
        begin = k;
    }
    heap[begin] = save;
}

template<typename T>
void _heapsort(vector<T> &heap,int begin,int end)
{
    int i;
    for(int j = (end - 1) / 2;j >= begin; j--)
    {
        doheap(heap,j,end-1);
    }
    for(i = end-1; i > begin;i--)
    {
        swap(heap,i,begin);
        doheap(heap,begin,i-1);
    }
}

template<typename T>
void heapsort(vector<T> &heap)
{
    int length = heap.size();
    _heapsort(heap,0,length);
}

template void heapsort<int>(vector<int>&);
template void _heapsort<int>(vector<int>&,int,int);
