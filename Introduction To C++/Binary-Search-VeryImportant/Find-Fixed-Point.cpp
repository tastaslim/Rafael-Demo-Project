//A fixed point is described as :
// if a number is same as it's index in a given array. It is called
// as Fixed Point.

// Here we have find numbe of occurence / Frequency
// of a given number in sorted array.
#include <bits/stdc++.h>
using namespace std;
int BS(int *arr, int start, int end)
{

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < mid)
        {
            // return BS(arr, mid + 1, end);
            start = mid + 1;
        }
        else if (arr[mid] > mid)
        {
            // return BS(arr, start, mid - 1);
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int arr[5] = {-10, -1, 0, 2, 4};
    int low = *min_element(arr, arr + 5);
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = BS(arr, 0, size - 1);
    cout << ans << endl;
    return 0;
}