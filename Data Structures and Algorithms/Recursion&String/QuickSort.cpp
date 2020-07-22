#include <bits/stdc++.h>
using namespace std;
int Partiton(int *arr, int n, int start, int end)
{
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[start])
        {
            count++;
        }
    }
    int pivot = count + start;
    swap(arr[start], arr[pivot]);
    int i = start, j = end;
    while (i < pivot && j > pivot)
    {
        if (arr[i] <= arr[pivot])
        {
            i++;
        }
        else if (arr[j] > arr[pivot])
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return pivot;
}
void QuickSort(int *arr, int n, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int c = Partiton(arr, n, start, end);
    QuickSort(arr, n, start, c - 1);
    QuickSort(arr, n, c + 1, end);
}

void QuickSort(int *arr, int n)
{
    QuickSort(arr, n, 0, n - 1);
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
    QuickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}