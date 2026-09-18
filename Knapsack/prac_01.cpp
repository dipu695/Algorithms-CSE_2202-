#include <bits/stdc++.h>
using namespace std;

int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n)
{
    int k[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                k[i][j] = maxValue(val[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
        }
    }
    return k[n][W];
}

int main()
{
    int n, W;
    int wt[20], val[20];

    cout << "Enter number of item: ";
    cin >> n;

    cout << "Enter value and weight of each item: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    cout << "Enter the size of knapsack: ";
    cin >> W;

    cout << "Maximum value: " << knapsack(W, wt, val, n);

    return 0;
}