//Question Statement:
// Given a sorted non-decreasing array, we have to find number of occurence / Frequency
// of a given number in sorted array.

#include <iostream>
using namespace std;
int BS(int *arr, int size, int x)
{
    int start1 = 0, end1 = size - 1;
    int start2 = 0, end2 = size - 1;
    int last = -3, first = -1;
    int ans = -1;
    while (start1 <= end1)
    {
        int mid1 = start1 + ((end1 - start1) / 2);
        if (arr[mid1] < x)
        {
            start1 = mid1 + 1;
        }
        else if (arr[mid1] > x)
        {
            end1 = mid1 - 1;
        }
        else
        {
            first = mid1;
            end1 = mid1 - 1;
        }
    }

    while (start2 <= end2)
    {
        int mid2 = start2 + ((end2 - start2) / 2);
        if (arr[mid2] < x)
        {
            start2 = mid2 + 1;
        }
        else if (arr[mid2] > x)
        {
            end2 = mid2 - 1;
        }
        else
        {
            last = mid2;
            start2 = mid2 + 1;
        }
    }
    return last - first + 1;
}
int main()
{
    int arr[12] = {1, 3, 3, 3, 3, 4, 6, 8, 9, 9, 10};
    //int arr[7] = {123, 122, 43, 24, 16, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int valuetofind;
    cin >> valuetofind;
    int ans = BS(arr, size, valuetofind);
    cout << ans << endl;
    return 0;
}