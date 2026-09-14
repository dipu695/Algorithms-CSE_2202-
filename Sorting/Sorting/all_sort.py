import numpy as np

elements = input("Enter numbers: ")
data = [int(x) for x in elements.split()]

def bubble_sort(arr):
    arr = np.array(arr)
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] >arr[j + 1]:
                arr[j] , arr[j + 1] = arr[j + 1] , arr[j]
    return arr

def selection_sort(arr):
    arr = np.array(arr)
    n = len(arr)

    for i in range(n):
        min_idx = i
        for j in range(i + 1 , n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i] , arr[min_idx] = arr[min_idx] , arr[i]
    return arr

def insertion_sort(arr):
    arr = np.array(arr)

    for i in range(1 , len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
            arr[j + 1]  = key
    return arr


def merge_Sort(arr):
    arr = np.array(arr)
    if len(arr) <= 1:
        return np.array(arr)
    mid = len(arr) // 2
    left = merge_Sort(arr[:mid])
    right = merge_Sort(arr[mid:])

    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged.extend(left[i:])
    merged.extend(right[j:])
    return np.array(merged)

def heap_Sort(arr):
    arr = np.array(arr)
    n = len(arr)
    def heapify(arr , n , i):
         largesy = i
         


print("Bubble sort: " , bubble_sort(data))
print("Selection sort: ",selection_sort(data))
print("Insertion sort: " , insertion_sort(data))
print("Merge sort: " , merge_Sort(data))