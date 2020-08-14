// We are rotating by 1 postion only
// Sorted array is rotated and it is given as input to us. Now find
//How many times original sorted array is rotated to give our input array.

#include <iostream>
using namespace std;

int BS(int *arr, int size)
{
    int start = 0, end = size - 1;
    int ans = -1;
    int k = start + (end - start) / 2;
    // Decreasing order array
    if (arr[k] <= arr[start] && arr[k] >= arr[end])
    {
        return end;
    }
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid + 1] >= arr[mid] && arr[mid - 1 + size] > arr[mid])
        {
            return mid;
        }
        else
        {
            // Increasing order. Normal case no rotation
            if (arr[mid] >= arr[start] && arr[mid] <= arr[end])
            {
                return start;
            }

            else if (arr[mid] >= arr[start])
            {
                start = mid + 1;
            }
            else if (arr[mid] <= arr[end])
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    //int arr[15] = {18 2 3 4 5 6 7 8 9 10 11 12 13};
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = BS(arr, n);
    cout << ans << endl;
    return 0;
}