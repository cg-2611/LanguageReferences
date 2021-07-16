def partition(array, start, end):
    pivot = array[end]
    index = start - 1

    for j in range(start, end):
        if array[j] <= pivot:
            index += 1
            array[index], array[j] = array[j], array[index]

    array[index + 1], array[end] = array[end], array[index + 1]
    print(array)

    return index + 1

def quick_sort(array, start, end):
    if start < end:
        partition_index = partition(array, start, end)

        quick_sort(array, start, partition_index - 1)
        quick_sort(array, partition_index + 1, end)

unsorted_array = [9, 3, 2, 7, 1, 4, 5, 8, 6]
print("Unsorted Array:", unsorted_array)
print("Quick Sort:")
quick_sort(unsorted_array, 0, len(unsorted_array) - 1)
