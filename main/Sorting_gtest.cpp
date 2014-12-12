#include <gtest/gtest.h>
#include <Sorting.h>

using namespace std;
//TESTS
//INSERTIONSORT
//Random Numbers
TEST(TestInsertionSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);

    Sorting::addRandomNumbers(test);

    //Sorting::printOut(test);
    Sorting::insertionSort(test);
    //Sorting::printOut(test);

    EXPECT_EQ(true, Sorting::isSorted(test));
}
//permutaded numbers
TEST(TestInsertionSortPermutadedNumbers, SortTest)
{
    vector<int> test(10,0);

    Sorting::addSameNumbers(test);
    //Sorting::printOut(test);
    Sorting::insertionSort(test);
    //Sorting::printOut(test);

    EXPECT_EQ(true, Sorting::isSorted(test));
}
//QUICKSORT
TEST(TestQuickSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    int length = test.size();

    Sorting::addRandomNumbers(test);

    //Sorting::printOut(test);
    Sorting::quickSort(test,0,length - 1);
    //Sorting::printOut(test);

    EXPECT_EQ(true, Sorting::isSorted(test));
}
TEST(TestQuickSortPermutatedNumbers, SortTest)
{
    vector<int> test(10,0);
    int length = test.size() - 1;

    Sorting::addSameNumbers(test);
    //Sorting::printOut(test);

    Sorting::quickSort(test,0,length);

    EXPECT_EQ(true, Sorting::isSorted(test));
}
//MERGESORT
TEST(TestMergeSortRandomNumbers, SortTest)
{
    vector<int> test(10,0);
    int length = test.size()- 1;

    Sorting::addRandomNumbers(test);

    //Sorting::printOut(test);
    Sorting::mergeSort(test,0,length);
    //Sorting::printOut(test);

    EXPECT_EQ(true, Sorting::isSorted(test));
}
TEST(TestMergeSortPermutatedNumbers, Sorttest)
{
    vector<int> test(10,0);
    int length = test.size() - 1;

    Sorting::addSameNumbers(test);
    Sorting::quickSort(test,0,length);

    EXPECT_EQ(true, Sorting::isSorted(test));

}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
