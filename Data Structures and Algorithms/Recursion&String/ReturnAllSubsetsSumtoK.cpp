#include <iostream>
using namespace std;
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

//Using 1 extra array only

int subsetSumToK(int input[], int n, int output[][50], int sum)
{
    //base case
    if (n == 0)
    {
        if (sum == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }

    int sum1 = subsetSumToK(input + 1, n - 1, output, sum);
    int k = 0;

    for (int i = 0; i < sum1; i++)
    {
        for (int j = 0; j <= output[i][0]; j++)
        {
            output[k][j] = output[i][j];
        }
        k = k + 1;
    }
    int arr[1000][50];
    int sum2 = subsetSumToK(input + 1, n - 1, arr, sum - input[0]);

    for (int i = 0; i < sum2; i++)
    {
        int size = arr[i][0] + 1;
        output[k][0] = size;
        output[k][1] = input[0];
        for (int j = 2; j <= size; j++)
        {
            output[k][j] = arr[i][j - 1];
        }
        k = k + 1;
    }
    return k;
}

// Using 2 extra array

/*int subsetSumToK(int input[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }

    int arr1[1000][50];
    int arr2[1000][50];

    int s1 = subsetSumToK(input + 1, n - 1, arr1, k);
    int s2 = subsetSumToK(input + 1, n - 1, arr2, k - input[0]);
    int row = 0;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j <= arr1[i][0]; j++)
        {
            output[row][j] = arr1[i][j];
        }
        row++;
    }

    for (int i = 0; i < s2; i++)
    {
        int size = arr2[i][0] + 1;
        output[row][0] = size;
        output[row][1] = input[0];
        for (int j = 2; j <= size; j++)
        {
            output[row][j] = arr2[i][j - 1];
        }
        row++;
    }
    return row;
}
*/
int main()
{
    int input[20], length, output[1000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
