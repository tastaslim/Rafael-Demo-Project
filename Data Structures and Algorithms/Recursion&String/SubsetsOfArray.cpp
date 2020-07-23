/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include <iostream>
using namespace std;
int subset(int input[], int start, int n, int output[][20])
{
    if (start == n)
    {
        output[start][start] = 0;
        return 1;
    }

    int k = subset(input, start + 1, n, output);
    for (int i = 0; i < k; i++)
    {
        output[i + k][0] = output[i][0] + 1;
        for (int j = output[i + k][0] - 1; j > 0; j--)
        {
            output[i + k][j + 1] = output[i][j];
        }
        output[i + k][1] = input[start];
    }
    return 2 * k;
}

int subset(int input[], int n, int output[][20])
{
    return subset(input, 0, n, output);
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}