import numpy as np
def bubbleSort(arr):
    arr = np.array(arr)
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j] , arr[j + 1] = arr[j + 1] , arr[j]
    return arr

elements = input('Enter numbers: ')
data = [int(x) for x in elements.split()]

sorted_array = bubbleSort(data)
print("Sorted array: " , sorted_array)
