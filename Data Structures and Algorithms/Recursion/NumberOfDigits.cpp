#include <iostream>
using namespace std;
int count1(int n)
{
    if (n == 0)
        return 0;
    int smallAns = count1(n / 10);
    return smallAns + 1;
}
int count(int n)
{
    if (n <= 0)
        return 1;
    return count1(n);
}

int main()
{
    int n;
    cin >> n;

    count(n);
}
