#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[] , int n)
{
    for(int i = 0 ; i < n- 1 ; i++)
    {
        int smallidx = i;//assuming small is unsorted part starting
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[j] < arr[smallidx])
            {
                smallidx = j;
            }
        }

        swap(arr[i] , arr[smallidx]);
    }
}


int main()
{
    int n = 5;
    int arr[] = {4 , 6 , 2 , 9 , 1};
    selectionSort(arr , n);
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}