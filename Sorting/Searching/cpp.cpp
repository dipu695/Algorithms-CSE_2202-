#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int x)
{
    int first = 0;
    int last = arr.size() - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (x == arr[mid])
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of the elements: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int x;
    cout << "Enter target: ";
    cin >> x;

    int result = binarySearch(arr, x);
    if (result == -1)
    {
        cout << "Not found!\n";
    }
    else
    {
        cout << result << "th index";
    }

    return 0;
}