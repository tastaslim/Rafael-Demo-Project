//Question Statement
/*
A child is running up a staircase with N steps, and can hope 
either 1 step, 2 steps or 3 steps at a time. Implement a 
method to count how many possible ways the child can run up 
to the stairs. You need to return number of possible ways W.
*/

#include <bits/stdc++.h>
using namespace std;
//Using Brute Force O(3^n)

/*int PossibleWays(int n)
{
    if (n <= 0)
        return 0;
    if (n <= 2)
        return n;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    return PossibleWays(n - 1) + PossibleWays(n - 2) + PossibleWays(n - 3);
}*/

//Using Dynamic Programming O(n)
long long int PossibleWays(int n)
{
    int arr[100000];
    arr[0] = 0, arr[1] = 1, arr[2] = 2, arr[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    long long int ans = PossibleWays(n);
    cout << ans;
}