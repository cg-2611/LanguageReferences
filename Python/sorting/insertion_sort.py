def insertion_sort(array):
    for i in range(1, len(array)):
        element_to_insert = array[i]
        previous = i - 1

        while (previous >= 0) and (array[previous] > element_to_insert):
            array[previous + 1] = array[previous]
            previous -= 1

        array[previous + 1] = element_to_insert
        print(array)

if __name__ == "__main__":
    unsorted_array = [9, 3, 2, 7, 1, 4, 5, 8, 6]
    print("Unsorted Array:", unsorted_array)
    print("Insertion Sort:")
    insertion_sort(unsorted_array)
