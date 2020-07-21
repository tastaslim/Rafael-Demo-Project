#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int row, col;
	cin >> row >> col;
	int **arr = new int *[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	int l = 0, u = 0, r = col - 1, b = row - 1;
	int dir = 0;

	while (l <= r && u <= b)
	{
		if (dir == 0)
		{
			for (int i = l; i <= r; i++)
			{
				cout << arr[u][i] << " ";
			}
			u++;
			dir++;
		}

		else if (dir == 1)
		{
			for (int i = u; i <= b; i++)
			{
				cout << arr[i][r] << " ";
			}
			r--;
			dir++;
		}
		else if (dir == 2)
		{
			for (int i = r; i >= l; i--)
			{
				cout << arr[b][i] << " ";
			}
			b--;
			dir++;
		}
		else
		{
			for (int i = b; i >= u; i--)
			{
				cout << arr[i][l] << " ";
			}
			l++;
			dir++;
		}
		dir = dir % 4;
	}
	return 0;
}