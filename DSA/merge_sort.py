import array as arr

# Function to merge the two smaller arrays in a sorted form
def merge(low, mid, high, A):
    C = arr.array('i', A)
    i = low
    j = mid+1
    k = low
    while (i <= mid and j <= high):
        if A[i] < A[j]:
            C[k] = A[i]
            i = i + 1
        else:
            C[k] = A[j]
            j = j + 1
        k = k + 1
    
    while (i <= mid):
        C[k] = A[i]
        k+=1
        i+=1
    
    while (j <= high):
        C[k] = A[j]
        k+=1
        j+=1
    
    copier = low
    while (copier <= high):
        A[copier] = C[copier]
        copier+=1

# Primary mergesort function
def mergeSort(low, high, A):
    if (low < high):
        mid = (int)((low + high)/2)
        mergeSort(low, mid, A)
        mergeSort(mid+1, high, A)
        
        merge(low, mid, high, A)

# Function to read array from a text file
def read_array(A):
    arrayfile = open("unsorted_array.txt", "r")
    lines = arrayfile.readlines()
    
    for line in lines:
        nolist=[]
        for val in line.split():
            A.append((int)(val))

    print(f"Input Array: {A}")
    print(f"Array Length: {len(A)}")
    return A, len(A)

A = arr.array('i',[])
sz = 0
A, sz = read_array(A)
mergeSort(0, sz-1, A)

print(f"Sorted Array: {A}")