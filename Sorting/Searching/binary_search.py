import numpy as np
def binary_search(arr , x):
    arr = np.array(arr)

    first = 0
    last = len(arr) - 1
    while(first <= last):
        mid =(first + last)//2

        if x == arr[mid]:
            return mid
        elif x < arr[mid]:
            last = mid - 1
        else:
            first = mid +1
    if(first > last):
        print("Not found!!")

elements = input("Enter numbers: ")
data = [int(x) for x in elements.split()]

x = int(input("Enter target data: "))

if binary_search(data , x) == -1:
    print("Not found")
else:
    print("Got it: ",binary_search(data , x) + 1 ,"th index")
