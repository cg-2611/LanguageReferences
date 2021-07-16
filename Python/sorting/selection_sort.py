def selection_sort(array):
    for i in range(len(array) - 2):
        smallest_index = i

        for j in range(i + 1, len(array)):
            if array[j] < array[smallest_index]:
                smallest_index = j

        array[i], array[smallest_index] = array[smallest_index], array[i]
        print(array)

unsorted_array = [9, 3, 2, 7, 1, 4, 5, 8, 6]
print("Unsorted Array:", unsorted_array)
print("Selection Sort:")
selection_sort(unsorted_array)
