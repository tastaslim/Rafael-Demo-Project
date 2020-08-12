#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int MaxArea(int *arr, int n)
{
    stack<pair<int, int>> s1;
    stack<pair<int, int>> s2;
    vector<int> RV;
    vector<int> LV;

    // For RV
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1.empty())
        {
            RV.push_back(n);
            s1.push({arr[i], i});
        }
        else if (!s1.empty() && s1.top().first <= arr[i])
        {
            RV.push_back(s1.top().second);
            s1.push(arr[i]);
            while (!s1.empty() && s1.top().first > arr[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                RV.push_back(n);
            }
            else
            {
                RV.push_back(s1.top());
            }
            s1.push(arr[i]);
        }
        else if (!s1.empty() && s1.top().first > arr[i])
        {
            while (!s1.empty() && s1.top() <= arr[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                RV.push_back(n);
            }
            else
            {
                RV.push_back(s1.top());
            }
            s1.push(arr[i]);
        }
    }
    reverse(RV.begin(), RV.end());
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
    int maxArea = MaxArea(arr, n);
    cout << maxArea << endl;
    delete[] arr;
}