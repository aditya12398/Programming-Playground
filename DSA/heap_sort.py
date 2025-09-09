# This is heap sort without using recursion in python

import array as arr

def heap_sort(unsorted, h_size):
    while(h_size > 1):
        i = 1
        parent = i - 1
        child1 = i * 2 - 1
        child2 = child1 + 1
        deleted = unsorted[parent]
        unsorted[parent] = unsorted[h_size - 1]
        h_size = h_size - 1
        while(child1 < h_size):
            if unsorted[child1] > unsorted[child2] or child2 > (h_size):
                unsorted[parent],unsorted[child1] = unsorted[child1],unsorted[parent]
                parent = child1
                child1 = parent * 2 + 1
                child2 = child1 + 1
            else:
                unsorted[parent],unsorted[child2] = unsorted[child2],unsorted[parent]
                parent = child2
                child1 = parent * 2 + 1
                child2 = child1 + 1
        unsorted[h_size] = deleted
    return unsorted

# Array to take input from a text file
def read_array():
    arrayfile = open("unsorted_array.txt", "r")
    lines = arrayfile.readlines()
    heap = arr.array('i',[])
    
    heap_size = 0
    for line in lines:
        nolist=[]
        for val in line.split():
            heap.append((int)(val))

            i = heap_size + 1
            while (i > 1):
                parent = (int)(i / 2)
                if heap[parent - 1] < heap[i - 1]:
                    heap[parent - 1], heap[i - 1] = heap[i - 1], heap[parent - 1]
                    i = (int)(i / 2)
                else:
                    break
            heap_size = heap_size + 1
    print(f"Heap Created: {heap}")
    print(f"Length of the array: {len(heap)}")
    return heap, len(heap)

read_array()

heaped_array, n = read_array()

sorted_array = heap_sort(heaped_array, n)
print(f"Sorted Array: {sorted_array}")