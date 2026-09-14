//knapsac(0-1)
#include <bits/stdc++.h>
using namespace std;

// Function to find the bigger value
int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}

// Knapsack function

// W   → Bag capacity
// wt  → Weight`
// val → Value
// n   → Number of items
int knapSack(int W, int wt[], int val[], int n)
{
    // DP table
    // k[i][j] = maximum value using first i items
    // when the bag capacity is j

    int k[n + 1][W + 1];

    // Go through all items
    for (int i = 0; i <= n; i++)
    {
        // Try all possible capacities
        for (int j = 0; j <= W; j++)
        {
            // If there are no items
            // OR bag capacity is 0
            // maximum value = 0
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }

            // If the current item can fit
            else if (wt[i - 1] <= j)
            {
                // Two choices:
                // 1. Take the item
                // 2. Don't take the item

                // Take the maximum of these two choices
                k[i][j] = maxValue(
                    val[i - 1] + k[i - 1][j - wt[i - 1]], // Take
                    k[i - 1][j]                           // Don't take
                );
            }

            // If the item doesn't fit
            else
            {
                // Don't take the item
                k[i][j] = k[i - 1][j];
            }
        }
    }

    // Return the maximum value
    return k[n][W];
}

int main()
{
    int n, W;

    int wt[20], val[20];

    // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Input value and weight
    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    // Knapsack capacity
    cout << "Enter the size of knapsack: ";
    cin >> W;

    // Display maximum value
    cout << "Maximum value: "
         << knapSack(W, wt, val, n);

    return 0;
}