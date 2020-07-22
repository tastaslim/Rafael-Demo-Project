#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool is_palindromeHelper(char arr[], int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (arr[start] != arr[end])
    {
        return false;
    }
    return is_palindromeHelper(arr, start + 1, end - 1);
}

bool is_palindrome(char arr[])
{
    return is_palindromeHelper(arr, 0, strlen(arr) - 1);
}
int main()
{
    char arr[1000000];
    cin.getline(arr, 1000000);
    bool ans = is_palindrome(arr);
    if (ans)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
