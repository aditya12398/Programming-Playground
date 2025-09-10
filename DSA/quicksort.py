import array as arr
import math

def read_array(A):
    arrayfile = open("unsorted_array.txt", "r")
    lines = arrayfile.readlines()
    
    for line in lines:
        nolist=[]
        for val in line.split():
            A.append((int)(val))

    print(f"Input Array: {A}")
    print(f"Array Length: {len(A)}")
    A.append(math.inf)
    return A, len(A)

def partition(low, high, A):
    j = high
    i = low
    pivot = A[i]
    while (i < j):
        i = i + 1
        while (A[i] < pivot):
            i = i + 1
        
        j = j - 1
        while (A[j] > pivot):
            j = j - 1
        
        if (i < j):
            A[j], A[i] = A[i], A[j]
    A[j], A[low] = A[low], A[j]
    return j

def quickSort(low, high, A):
    if (low < high):
        j = partition(low, high, A)
        quickSort(low, j, A)
        quickSort(j+1, high, A)

A = arr.array('f',[])
sz = 0
A, sz = read_array(A)

quickSort(0, sz-1, A)
A.pop()
print(f"Sorted Array: {A}")