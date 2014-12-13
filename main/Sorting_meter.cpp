#include <Meter.h>
#include <Sorting.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    char AlgName[20];

    cout << "Start to Measure Sorting Algorithms!" <<endl;

    vector<int> test;
    uint32_t numberoftest = 500;
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

    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addPermutedNumbers(test);
        //Sorting::printOut(test);
        InsertionSortP.measure(numberoftest,*Sorting::insertionSort<int>,test);

        InsertionSortP.printDataTime(AlgName);
        InsertionSortP.printDataCycle(AlgName);
        InsertionSortP.printDataToPlotCycle(AlgName,i);
        InsertionSortP.printDataToPlotTime(AlgName,i);
        test.clear();

    }
    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addRepeatedNumber(test);
        //Sorting::printOut(test);
        InsertionSortR.measure(numberoftest,*Sorting::insertionSort<int>,test);

        InsertionSortR.printDataTime(AlgName);
        InsertionSortR.printDataCycle(AlgName);
        InsertionSortR.printDataToPlotCycle(AlgName,i);
        InsertionSortR.printDataToPlotTime(AlgName,i);
        test.clear();

    }
    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        InsertionSortSN.measure(numberoftest,*Sorting::insertionSort<int>,test);

        InsertionSortSN.printDataTime(AlgName);
        InsertionSortSN.printDataCycle(AlgName);
        InsertionSortSN.printDataToPlotCycle(AlgName,i);
        InsertionSortSN.printDataToPlotTime(AlgName,i);
        test.clear();

    }
    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        InsertionSortRN.measure(numberoftest,*Sorting::insertionSort<int>,test);
        InsertionSortRN.printDataTime(AlgName);
        InsertionSortRN.printDataCycle(AlgName);
        InsertionSortRN.printDataToPlotCycle(AlgName,i);
        InsertionSortRN.printDataToPlotTime(AlgName,i);
        test.clear();

    }

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

    for(uint32_t i = 1;i < numberoftest;i++)
    {

        test.resize(i);
        Sorting::addPermutedNumbers(test);
        //Sorting::printOut(test);
        QuickSortP.measure(numberoftest,*Sorting::quickSort<int>,test);

        QuickSortP.printDataTime(AlgName);
        QuickSortP.printDataCycle(AlgName);
        QuickSortP.printDataToPlotCycle(AlgName,i);
        QuickSortP.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {

        test.resize(i);
        Sorting::addRepeatedNumber(test);
        //Sorting::printOut(test);
        QuickSortR.measure(numberoftest,*Sorting::quickSort<int>,test);

        QuickSortR.printDataTime(AlgName);
        QuickSortR.printDataCycle(AlgName);
        QuickSortR.printDataToPlotCycle(AlgName,i);
        QuickSortR.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {

        test.resize(i);
        Sorting::addSortedNumbers(test);
        //Sorting::printOut(test);
        QuickSortSN.measure(numberoftest,*Sorting::quickSort<int>,test);
        QuickSortSN.printDataTime(AlgName);
        QuickSortSN.printDataCycle(AlgName);
        QuickSortSN.printDataToPlotCycle(AlgName,i);
        QuickSortSN.printDataToPlotTime(AlgName,i);
        test.clear();

    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {

        test.resize(i);
        Sorting::addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        QuickSortRN.measure(numberoftest,*Sorting::quickSort<int>,test);
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

    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addPermutedNumbers(test);
        //Sorting::printOut(test);
        MergeSortP.measure(numberoftest,*Sorting::mergeSort<int>,test);
        MergeSortP.printDataTime(AlgName);
        MergeSortP.printDataCycle(AlgName);
        MergeSortP.printDataToPlotCycle(AlgName,i);
        MergeSortP.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addRepeatedNumber(test);
        //Sorting::printOut(test);
        MergeSortR.measure(numberoftest,*Sorting::mergeSort<int>,test);
        MergeSortR.printDataTime(AlgName);
        MergeSortR.printDataCycle(AlgName);
        MergeSortR.printDataToPlotCycle(AlgName,i);
        MergeSortR.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addSortedNumbers(test);
        //Sorting::printOut(test);
        MergeSortSN.measure(numberoftest,*Sorting::mergeSort<int>,test);
        MergeSortSN.printDataTime(AlgName);
        MergeSortSN.printDataCycle(AlgName);
        MergeSortSN.printDataToPlotCycle(AlgName,i);
        MergeSortSN.printDataToPlotTime(AlgName,i);
        test.clear();
    }

    for(uint32_t i = 1;i < numberoftest;i++)
    {
        test.resize(i);
        Sorting::addReverseSortedNumbers(test);
        //Sorting::printOut(test);
        MergeSortRN.measure(numberoftest,*Sorting::mergeSort<int>,test);
        MergeSortRN.printDataTime(AlgName);
        MergeSortRN.printDataCycle(AlgName);
        MergeSortRN.printDataToPlotCycle(AlgName,i);
        MergeSortRN.printDataToPlotTime(AlgName,i);
        test.clear();
    }


    cout << "finished to measure MergeSort" << endl;
}

