#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double GeometricSum(int n, int i)
{
    if (i > n)
    {
        return 0;
    }
    float value = (1 * 1.0) / (pow(2, i));
    return GeometricSum(n, i + 1) + value;
}
int main()
{
    int n;
    cin >> n;
    double ans = GeometricSum(n, 0);
    cout << ans << endl;
    return 0;
}
