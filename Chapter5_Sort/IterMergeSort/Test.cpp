#include "MergeSortIter.hpp"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main (void)
{
    int arr [] = {5, 8, 7, 1, 0, 87, 24, 75, 123, 65, 9887};
    int len = sizeof (arr) / sizeof (int);

    cout << "Initial array." << endl;
    cout << "Number of elements : " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //////////////////////////////////////////////////////////
    MergeSortIter (arr, len);

    cout << "MergeSort using Iteration." << endl;
    cout << "Number of elements : " << len << endl;

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}