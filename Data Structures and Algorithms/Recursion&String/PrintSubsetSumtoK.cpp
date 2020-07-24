/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
*/

#include <iostream>
using namespace std;

// Approach 1------>  With Extra Space O(n)

/*
void helper(int *input, int size, int *output, int m)
{
    if (size == 0)
    {
        int curr_sum = 0;
        for (int i = 0; i < m; i++)
        {
            curr_sum += output[i];
            // cout << output[i] << " ";
        }
        if (sum == curr_sum)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }

            cout << endl;
        }
        return;
    }
    helper(input + 1, size - 1, output, m);
    int *arr = new int[m + 1];
    for (int i = 0; i < m; i++)
    {
        arr[i] = output[i];
    }
    arr[m] = input[0];
    helper(input + 1, size - 1, arr, m + 1);
}
void printSubsetsOfArray(int input[], int size)
{
    int *output = new int[size];
    helper(input, size, output, 0);
}
*/

//Approach 2 -----> Without any Extra Space
void printSubsetsOfArray(int input[], int size, int output[], int m, int sum)
{
    if (size == 0)
    {
        int curr_sum = 0;
        for (int i = 0; i < m; i++)
        {
            curr_sum += output[i];
            // cout << output[i] << " ";
        }
        if (sum == curr_sum)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }

            cout << endl;
        }
        return;
    }
    printSubsetsOfArray(input + 1, size - 1, output, m, sum);
    output[m] = input[0];
    printSubsetsOfArray(input + 1, size - 1, output, m + 1, sum);
}

void printSubsetsOfArray(int input[], int size, int sum)
{
    int output[1000000];
    printSubsetsOfArray(input, size, output, 0, sum);
}
int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    int sum;
    cin >> sum;
    printSubsetsOfArray(input, length, sum);
    return 0;
}
