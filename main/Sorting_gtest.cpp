#include <gtest/gtest.h>
#include <Sorting.h>
#include <Heapsort.h>
#include <Introsort.h>

using namespace std;
//TESTS
//INSERTIONSORT
//Random Numbers
TEST(TestInsertionSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    addRandomNumbers(test);
    insertionSort(test);
    EXPECT_EQ(true, isSorted(test));
}
//permutaded numbers
TEST(TestInsertionSortPermutadedNumbers, SortTest)
{
    vector<int> test(10,0);
    addRepeatedNumber(test);
    insertionSort(test);
    EXPECT_EQ(true, isSorted(test));
}
//QUICKSORT
TEST(TestQuickSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    addRandomNumbers(test);
    quickSort(test);
    EXPECT_EQ(true, isSorted(test));
}
TEST(TestQuickSortPermutatedNumbers, SortTest)
{
    vector<int> test(10,0);
    addRepeatedNumber(test);
    quickSort(test);
    EXPECT_EQ(true, isSorted(test));
}
//MERGESORT
TEST(TestMergeSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    addRandomNumbers(test);
    mergeSort(test);
    EXPECT_EQ(true, isSorted(test));
}
TEST(TestMergeSortPermutatedNumbers, Sorttest)
{
    vector<int> test(10,0);
    addRepeatedNumber(test);
    quickSort(test);
    EXPECT_EQ(true, isSorted(test));

}

TEST(TestHeapSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    addRandomNumbers(test);
    heapsort(test);
    EXPECT_EQ(true, isSorted(test));
}

TEST(TestHeapSortPermutedNumbers, SortTest)
{
    vector<int> test(10,0);
    addPermutedNumbers(test);
    heapsort(test);
    EXPECT_EQ(true, isSorted(test));
}


TEST(TestIntroSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    addRandomNumbers(test);
    introsort(test);
    EXPECT_EQ(true, isSorted(test));
}

TEST(TestIntroSortPermutedNumbers, SortTest)
{
    vector<int> test(10,0);
    addPermutedNumbers(test);
    introsort(test);
    EXPECT_EQ(true, isSorted(test));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
