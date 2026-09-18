#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float capacity , maxProfit = 0;

    cout <<"Enter the number of items and capacity: ";
    cin >> n >> capacity;

    vector<int> weight(n) , profit(n) , ratio(n) , x(n , 0.0);

    cout <<"Enter the weight and profit : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> weight[i] >> profit[i];
        ratio[i] = weight[i]/profit[i];
    }

    for(int i = 0; i < n - 1 ; i++)
    {
        for(int j = i + 1 ; i < n ; i++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(ratio[i] , ratio[j]);
                swap(weight[i] , weight[j]);
                swap(profit[i] , profit[j]);
            }
        }
    }

    for(int i = 0 ; i < n and capacity > 0 ; i++)
    {
        if(weight[i] <= capacity)
        {
            x[i] = 1.00;
            maxProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            x[i] = capacity/weight[i];
            maxProfit += x[i] * profit[i];
            capacity = 0;
        }
    }

    cout <<"\nMaximum Profit: " << maxProfit << endl;

    return 0;
}