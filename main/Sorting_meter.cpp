#include <Meter.h>
#include <Sorting.h>
#include <Heapsort.h>
#include <Introsort.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    char AlgName[20];

    cout << "Start to Measure Sorting Algorithms!" <<endl;

    vector<int> test;
    uint32_t numberoftest = 10000;
    //int lengthOfTestVector = 0;
    //vector<int> test(lengthOfTestVector,0);

    cout << "Start to Measure InsertionSort" << endl;

    Meter InsertionSortP = Meter("InsertionSort_Time_Permuted.txt","InsertionSort_Cycle_Permuted.txt",
                                "InsertionSort_Cycle_Plot_Permuted.txt","InsertionSort_Time_Plot_Permuted.txt");

    Meter InsertionSortR = Meter("InsertionSort_Time_Repeated.txt","InsertionSort_Cycle_Repeated.txt",
                                "InsertionSort_Cycle_Plot_Repeated.txt","InsertionSort_Time_Plot_Repeated.txt");

    Meter InsertionSortSN = Meter("InsertionSort_Time_Sorted.txt","InsertionSort_Cycle_Sorted.txt",
                                "InsertionSort_Cycle_Plot_Sorted.txt","InsertionSort_Time_Plot_Sorted.txt");

    Meter InsertionSortRN = Meter("InsertionSort_Time_Reverse.txt","InsertionSort_Cycle_Reverse.txt",
                                "InsertionSort_Cycle_Plot_Reverse.txt","InsertionSort_Time_Plot_Reverse.txt");

    cout << "InsertionSort on Permuted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addPermutedNumbers(test);
        //Sorting::printOut(test);
        InsertionSortP.measure(*insertionSort<int>,test);

        InsertionSortP.printDataTime(AlgName);
        InsertionSortP.printDataCycle(AlgName);
        InsertionSortP.printDataToPlotCycle(AlgName,i);
        InsertionSortP.printDataToPlotTime(AlgName,i);
        test.clear();

    }
    cout << "insertionsort on repeated numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addRepeatedNumber(test);
        //Sorting::printOut(test);
        InsertionSortR.measure(*insertionSort<int>,test);

        InsertionSortR.printDataTime(AlgName);
        InsertionSortR.printDataCycle(AlgName);
        InsertionSortR.printDataToPlotCycle(AlgName,i);
        InsertionSortR.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    cout << "InsertionSort on Sorted numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addSortedNumbers(test);
        InsertionSortSN.measure(*insertionSort<int>,test);
        InsertionSortSN.printDataTime(AlgName);
        InsertionSortSN.printDataCycle(AlgName);
        InsertionSortSN.printDataToPlotCycle(AlgName,i);
        InsertionSortSN.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    cout << "InsertionSort on  reverse Sorted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        InsertionSortRN.measure(*insertionSort<int>,test);
        InsertionSortRN.printDataTime(AlgName);
        InsertionSortRN.printDataCycle(AlgName);
        InsertionSortRN.printDataToPlotCycle(AlgName,i);
        InsertionSortRN.printDataToPlotTime(AlgName,i);
        test.clear();

    }
    numberoftest = 10000;

    cout << "finished to Measure InsertionSort" << endl;
    cout << "start to Measure QuickSort" << endl;

    //cout << "quickloop" << endl;
    Meter QuickSortP = Meter("QuickSort_Time_Permuted.txt","QuickSort_Cycle_Permuted.txt",
                            "QuickSort_Cycle_Plot_Permuted.txt","QuickSort_Time_Plot_Permuted.txt");

    Meter QuickSortR = Meter("QuickSort_Time_Repeated.txt","QuickSort_Cycle_Repeated.txt",
                            "QuickSort_Cycle_Plot_Repeated.txt","QuickSort_Time_Plot_Repeated.txt");

    Meter QuickSortSN = Meter("QuickSort_Time_Sorted.txt","QuickSort_Cycle_Sorted.txt",
                            "QuickSort_Cycle_Plot_Sorted.txt","QuickSort_Time_Plot_Sorted.txt");

    Meter QuickSortRN = Meter("QuickSort_Time_Reverse.txt","QuickSort_Cycle_Reverse.txt",
                            "QuickSort_Cycle_Plot_Reverse.txt","QuickSort_Time_Plot_Reverse.txt");

    cout << "QuickSort on permuted Numbers" << endl;

    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {

        test.resize(i);
        addPermutedNumbers(test);
        //Sorting::printOut(test);
        QuickSortP.measure(*quickSort<int>,test);

        QuickSortP.printDataTime(AlgName);
        QuickSortP.printDataCycle(AlgName);
        QuickSortP.printDataToPlotCycle(AlgName,i);
        QuickSortP.printDataToPlotTime(AlgName,i);
        test.clear();

    }


    cout << "QuickSort on Repeated Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {

        test.resize(i);
        addRepeatedNumber(test);
        //Sorting::printOut(test);
        QuickSortR.measure(*quickSort<int>,test);

        QuickSortR.printDataTime(AlgName);
        QuickSortR.printDataCycle(AlgName);
        QuickSortR.printDataToPlotCycle(AlgName,i);
        QuickSortR.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    cout << "QuickSort on Sorted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {

        test.resize(i);
        addSortedNumbers(test);
        //Sorting::printOut(test);
        QuickSortSN.measure(*quickSort<int>,test);
        QuickSortSN.printDataTime(AlgName);
        QuickSortSN.printDataCycle(AlgName);
        QuickSortSN.printDataToPlotCycle(AlgName,i);
        QuickSortSN.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    cout << "QuickSort on Reverse Sorted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {

        test.resize(i);
        addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        QuickSortRN.measure(*quickSort<int>,test);
        QuickSortRN.printDataTime(AlgName);
        QuickSortRN.printDataCycle(AlgName);
        QuickSortRN.printDataToPlotCycle(AlgName,i);
        QuickSortRN.printDataToPlotTime(AlgName,i);
        test.clear();

    }


    cout << "finished to Measure QuickSort" << endl;
    cout << "starting to measure MergeSort" << endl;



    Meter MergeSortP = Meter("MergeSort_Time_Permuted.txt","MergeSort_Cycle_Permuted.txt",
                            "MergeSort_Cycle_Plot_Permuted.txt","MergeSort_Time_Plot_Permuted.txt");

    Meter MergeSortR = Meter("MergeSort_Time_Repeated.txt","MergeSort_Cycle_Repeated.txt",
                            "MergeSort_Cycle_Plot_Repeated.txt","MergeSort_Time_Plot_Repeated.txt");

    Meter MergeSortSN = Meter("MergeSort_Time_Sorted.txt","MergeSort_Cycle_Sorted.txt",
                            "MergeSort_Cycle_Plot_Sorted.txt","MergeSort_Time_Plot_Sorted.txt");

    Meter MergeSortRN = Meter("MergeSort_Time_Reverse.txt","MergeSort_Cycle_Reverse.txt",
                            "MergeSort_Cycle_Plot_Reverse.txt","MergeSort_Time_Plot_Reverse.txt");

    cout << "MergeSort on Permuted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addPermutedNumbers(test);
        //Sorting::printOut(test);
        MergeSortP.measure(*mergeSort<int>,test);
        MergeSortP.printDataTime(AlgName);
        MergeSortP.printDataCycle(AlgName);
        MergeSortP.printDataToPlotCycle(AlgName,i);
        MergeSortP.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    cout << "MergeSort on Repeated Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addRepeatedNumber(test);
        //Sorting::printOut(test);
        MergeSortR.measure(*mergeSort<int>,test);
        MergeSortR.printDataTime(AlgName);
        MergeSortR.printDataCycle(AlgName);
        MergeSortR.printDataToPlotCycle(AlgName,i);
        MergeSortR.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    cout << "MergeSort on Sorted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addSortedNumbers(test);
        //Sorting::printOut(test);
        MergeSortSN.measure(*mergeSort<int>,test);
        MergeSortSN.printDataTime(AlgName);
        MergeSortSN.printDataCycle(AlgName);
        MergeSortSN.printDataToPlotCycle(AlgName,i);
        MergeSortSN.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    cout << "MergeSort on reverse Sorted Numbers" << endl;
    for(uint32_t i = 1;i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        MergeSortRN.measure(*mergeSort<int>,test);
        MergeSortRN.printDataTime(AlgName);
        MergeSortRN.printDataCycle(AlgName);
        MergeSortRN.printDataToPlotCycle(AlgName,i);
        MergeSortRN.printDataToPlotTime(AlgName,i);
        test.clear();
    }
    cout << "finished to measure MergeSort" << endl;

    cout << "Starting to measure Heapsort" << endl;

    Meter HeapsortP = Meter("Heapsort_Time_Permuted.txt","Heapsort_Cycle_Permuted.txt",
                            "Heapsort_Cycle_Plot_Permuted.txt","Heapsort_Time_Plot_Permuted.txt");

    Meter HeapsortR = Meter("Heapsort_Time_Repeated.txt","Heapsort_Cycle_Repeated.txt",
                            "Heapsort_Cycle_Plot_Repeated.txt","Heapsort_Time_Plot_Repeated.txt");

    Meter HeapsortSN = Meter("Heapsort_Time_Sorted.txt","Heapsort_Cycle_Sorted.txt",
                             "Heapsort_Cycle_Plot_Sorted.txt","Heapsort_Time_Plot_Sorted.txt");

    Meter HeapsortRN = Meter("Heapsort_Time_Reverse.txt","Heapsort_Cycle_Reverse.txt",
                             "Heapsort_Cycle_Plot_Reverse.txt","Heapsort_Time_Plot_Reverse.txt");

    cout << "Heapsort on Permuted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addPermutedNumbers(test);
        HeapsortP.measure(*heapsort<int>,test);
        HeapsortP.printDataTime(AlgName);
        HeapsortP.printDataCycle(AlgName);
        HeapsortP.printDataToPlotCycle(AlgName,i);
        HeapsortP.printDataToPlotTime(AlgName,i);
    }
    cout << "Heapsort on Repeated Number" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addRepeatedNumber(test);
        HeapsortR.measure(*heapsort<int>,test);
        HeapsortR.printDataTime(AlgName);
        HeapsortR.printDataCycle(AlgName);
        HeapsortR.printDataToPlotCycle(AlgName,i);
        HeapsortR.printDataToPlotTime(AlgName,i);
    }
    cout << "Heapsort on Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addSortedNumbers(test);
        HeapsortSN.measure(*heapsort<int>,test);
        HeapsortSN.printDataTime(AlgName);
        HeapsortSN.printDataCycle(AlgName);
        HeapsortSN.printDataToPlotCycle(AlgName,i);
        HeapsortSN.printDataToPlotTime(AlgName,i);
    }
    cout << "Heapsort on Reverse Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addReverseSortedNumbers(test);
        HeapsortRN.measure(*heapsort<int>,test);
        HeapsortRN.printDataTime(AlgName);
        HeapsortRN.printDataCycle(AlgName);
        HeapsortRN.printDataToPlotCycle(AlgName,i);
        HeapsortRN.printDataToPlotTime(AlgName,i);
    }

    cout << "Starting to measure Introsort" << endl;

    Meter IntrosortP = Meter("Introsort_Time_Permuted.txt","Introsort_Cycle_Permuted.txt",
                            "Introsort_Cycle_Plot_Permuted.txt","Introsort_Time_Plot_Permuted.txt");

    Meter IntrosortR = Meter("Introsort_Time_Repeated.txt","Introsort_Cycle_Repeated.txt",
                            "Introsort_Cycle_Plot_Repeated.txt","Introsort_Time_Plot_Repeated.txt");

    Meter IntrosortSN = Meter("Introsort_Time_Sorted.txt","Introsort_Cycle_Sorted.txt",
                             "Introsort_Cycle_Plot_Sorted.txt","Introsort_Time_Plot_Sorted.txt");

    Meter IntrosortRN = Meter("Introsort_Time_Reverse.txt","Introsort_Cycle_Reverse.txt",
                             "Introsort_Cycle_Plot_Reverse.txt","Introsort_Time_Plot_Reverse.txt");

    cout << "Introsort on Permuted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addPermutedNumbers(test);
        IntrosortP.measure(*heapsort<int>,test);
        IntrosortP.printDataTime(AlgName);
        IntrosortP.printDataCycle(AlgName);
        IntrosortP.printDataToPlotCycle(AlgName,i);
        IntrosortP.printDataToPlotTime(AlgName,i);
    }
    cout << "Introsort on Repeated Number" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addRepeatedNumber(test);
        IntrosortR.measure(*heapsort<int>,test);
        IntrosortR.printDataTime(AlgName);
        IntrosortR.printDataCycle(AlgName);
        IntrosortR.printDataToPlotCycle(AlgName,i);
        IntrosortR.printDataToPlotTime(AlgName,i);
    }
    cout << "Introsort on Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addSortedNumbers(test);
        IntrosortSN.measure(*heapsort<int>,test);
        IntrosortSN.printDataTime(AlgName);
        IntrosortSN.printDataCycle(AlgName);
        IntrosortSN.printDataToPlotCycle(AlgName,i);
        IntrosortSN.printDataToPlotTime(AlgName,i);
    }
    cout << "Introsort on Reverse Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addReverseSortedNumbers(test);
        IntrosortRN.measure(*heapsort<int>,test);
        IntrosortRN.printDataTime(AlgName);
        IntrosortRN.printDataCycle(AlgName);
        IntrosortRN.printDataToPlotCycle(AlgName,i);
        IntrosortRN.printDataToPlotTime(AlgName,i);
    }

    cout << "std::sort on inputs" << endl;
    Meter sortP = Meter("sort_Time_Permuted.txt","sort_Cycle_Permuted.txt",
                        "sort_Cycle_Plot_Permuted.txt","sort_Time_Plot_Permuted.txt");

    Meter sortR = Meter("sort_Time_Repeated.txt","sort_Cycle_Repeated.txt",
                        "sort_Cycle_Plot_Repeated.txt","sort_Time_Plot_Repeated.txt");

    Meter sortSN = Meter("sort_Time_Sorted.txt","sort_Cycle_Sorted.txt",
                         "sort_Cycle_Plot_Sorted.txt","sort_Time_Plot_Sorted.txt");

    Meter sortRN = Meter("sort_Time_Reverse.txt","sort_Cycle_Reverse.txt",
                         "sort_Cycle_Plot_Reverse.txt","sort_Time_Plot_Reverse.txt");

     for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addPermutedNumbers(test);
        sortP.measure(*csort<int>,test);
        sortP.printDataTime(AlgName);
        sortP.printDataCycle(AlgName);
        sortP.printDataToPlotCycle(AlgName,i);
        sortP.printDataToPlotTime(AlgName,i);
    }
    cout << "std::sort on Repeated Number" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addRepeatedNumber(test);
        sortR.measure(*csort<int>,test);
        sortR.printDataTime(AlgName);
        sortR.printDataCycle(AlgName);
        sortR.printDataToPlotCycle(AlgName,i);
        sortR.printDataToPlotTime(AlgName,i);
    }
    cout << "std::sort on Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addSortedNumbers(test);
        sortSN.measure(*csort<int>,test);
        sortSN.printDataTime(AlgName);
        sortSN.printDataCycle(AlgName);
        sortSN.printDataToPlotCycle(AlgName,i);
        sortSN.printDataToPlotTime(AlgName,i);
    }
    cout << "std::sort on Reverse Sorted Numbers" << endl;

    for(uint32_t i = 1; i < numberoftest;i += (i/10)+1)
    {
        test.resize(i);
        addReverseSortedNumbers(test);
        sortRN.measure(*csort<int>,test);
        sortRN.printDataTime(AlgName);
        sortRN.printDataCycle(AlgName);
        sortRN.printDataToPlotCycle(AlgName,i);
        sortRN.printDataToPlotTime(AlgName,i);
    }
}

