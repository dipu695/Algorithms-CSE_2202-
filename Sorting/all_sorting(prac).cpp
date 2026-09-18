#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int end)
{
    vector<int> temp;

    int i = st;
    int j = mid + 1;

    // Compare elements from both halves
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining elements of left half
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining elements of right half
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy temp back to original array
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);       // left half
        mergeSort(arr, mid + 1, end);  // right half

        merge(arr, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {2, 3, 8, 4, 1};

    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}