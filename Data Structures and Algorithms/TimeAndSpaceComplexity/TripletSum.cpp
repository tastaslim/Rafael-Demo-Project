#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void FindTriplet(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[k] == (x - arr[i] - arr[j]))
                {
                    if (arr[i] <= arr[j] && arr[j] <= arr[k])
                    {
                        std::cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    }
                    else if (arr[i] <= arr[j] && arr[j] >= arr[k] && arr[i] <= arr[k])
                    {
                        std::cout << arr[i] << " " << arr[k] << " " << arr[j] << endl;
                    }
                    else if (arr[j] <= arr[i] && arr[i] <= arr[k])
                    {
                        std::cout << arr[j] << " " << arr[i] << " " << arr[k] << endl;
                    }
                    else if (arr[k] <= arr[i] && arr[i] <= arr[j])
                    {
                        std::cout << arr[k] << " " << arr[i] << " " << arr[j] << endl;
                    }
                    else if (arr[k] <= arr[j] && arr[j] <= arr[i])
                    {
                        std::cout << arr[k] << " " << arr[j] << " " << arr[i] << endl;
                    }
                    else if (arr[j] <= arr[k] && arr[k] <= arr[i])
                    {
                        std::cout << arr[j] << " " << arr[k] << " " << arr[i] << endl;
                    }
                }
            }
        }
    }
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
    int sum;
    cin >> sum;
    FindTriplet(arr, n, sum);
    return 0;
}