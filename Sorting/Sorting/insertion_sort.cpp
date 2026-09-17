#include <bits/stdc++.h>
using namespace std;

//here after assuming sorted and unsorted part of the array
//always we compare current element with 
//all elements of the sorted part of the array
 
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];//in curr = first element of unsorted part  
        int prev = i - 1;//unsorted part 
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev+ 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;//placing the curr eement in it's correct position
    }
}
int main()
{
    int n = 6;
    int arr[] = {5 , 9 , 8 , 1 , 2 , 10};
    insertionSort(arr , n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
}