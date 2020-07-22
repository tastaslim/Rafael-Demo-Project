#include <bits/stdc++.h>
using namespace std;
void SumOfDigits(int n, int &k)
{
    if (n == 0)
    {
        return;
    }
    k++;
    SumOfDigits(n / 10, k);
}

int SumOfDigits(int n)
{
    int k = 0;
    SumOfDigits(n, k);
    if (n == 0)
    {
        return 1;
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    int ans = SumOfDigits(n);
    cout << ans;
}