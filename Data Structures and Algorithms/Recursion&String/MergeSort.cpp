#include <iostream>
using namespace std;
void MergeTwoSortedArray(int *arr, int n, int start, int end)
{
    int extra[n];
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            extra[k++] = arr[j++];
        }
        else
        {
            extra[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        extra[k++] = arr[i++];
    }
    while (j <= end)
    {
        extra[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = extra[i - start];
    }
}

void MergeSort(int *arr, int n, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(arr, n, start, mid);
    MergeSort(arr, n, mid + 1, end);
    MergeTwoSortedArray(arr, n, start, end);
}
void MergeSort(int *arr, int n)
{
    MergeSort(arr, n, 0, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}