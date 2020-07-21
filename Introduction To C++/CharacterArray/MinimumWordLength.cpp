#include <bits/stdc++.h>
using namespace std;
void minLengthWord(char input[], char output[])
{
    int count = 0, x = INT_MAX, start = 0, end = 0, k = 0, i = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            end = i - 1;
            if (count < x)
            {
                x = count;
                for (int j = start; j <= end; j++)
                {
                    output[k] = input[j];
                    k++;
                }
                output[k] = '\0';
            }
            count = 0;
            start = i + 1;
        }
        else
        {
            k = 0;
            count++;
        }
    }
    end = i - 1;
    if (count < x)
    {
        cout << endl;
        for (int j = start; j <= end; j++)
        {
            output[k] = input[j];
            k++;
        }
        output[k] = '\0';
    }
}
int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
