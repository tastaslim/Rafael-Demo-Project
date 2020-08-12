//TO get order simply check arr[1] and arr[0].
//if(arr[1]>arr[0]) ----> Ascending Order
//else  -----------------> Descending Order

#include <iostream>
using namespace std;
int BS(int *arr, int size, int x)
{
    bool m = true;
    if (arr[0] > arr[1])
    {
        m = false;
    }
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < x)
        {
            if (m) //Ascending Order
            {
                start = mid + 1;
            }
            else //Descending Order
            {
                end = mid - 1;
            }
        }
        else if (arr[mid] > x)
        {
            if (m) //Ascending Order
            {
                end = mid - 1;
            }
            else //Descending Order
            {
                start = mid + 1;
            }
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
    int arr[7] = {1, 2, 3, 4, 6, 8, 9};
    //int arr[7] = {123, 122, 43, 24, 16, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int valuetofind;
    cin >> valuetofind;
    int ans = BS(arr, size, valuetofind);
    cout << ans << endl;
    return 0;
}