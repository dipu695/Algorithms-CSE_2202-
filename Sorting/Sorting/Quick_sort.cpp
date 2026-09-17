//1.pick the pivot
//2.partion
//pivot [<=__less than "pivot" greater than >]

#include<bits/stdc++.h>
using namespace std;

int make_part(vector<int>&arr , int st , int end)
{
    int idx = st - 1 , pivot = arr[end];
    for(int j = st ; j < end ; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j] , arr[idx]);
        }
    }
    idx++;
    swap(arr[end] , arr[idx]);
    return idx;
}
void quickSort(vector<int>&arr , int st , int end)
{
    if(st < end){
      int pivotIdx =  make_part(arr , st , end);
      quickSort(arr , st , pivotIdx - 1);//left half
      quickSort(arr , pivotIdx + 1 , end);//right half

    }
}
int main()
{
    vector<int>arr = {1 , 5 , 9 , 7 , 3 , 5 , 0};
    quickSort(arr , 0 , arr.size() - 1);
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
}