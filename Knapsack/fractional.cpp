#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float capacity, maxProfit = 0;

    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;

    // Dynamically sized vectors based on input 'n'
    vector<float> weight(n), profit(n), ratio(n), x(n, 0.0);

    cout << "Enter weight and profit for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> profit[i];
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    // Greedy choice
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            x[i] = 1.0;
            maxProfit += profit[i];
            capacity -= weight[i];
        } else {
            x[i] = capacity / weight[i];
            maxProfit += x[i] * profit[i];
            capacity = 0;
        }
    }

    cout << "\nResult vector: ";
    for (int i = 0; i < n; i++) cout << x[i] << " ";
    cout << "\nMaximum profit: " << maxProfit << endl;

    return 0;
}