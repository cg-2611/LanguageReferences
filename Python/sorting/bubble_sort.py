def bubble_sort(array):
    for i in range(len(array) - 1):
        for j in range(len(array) - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

        print(array)

def optimized_bubble_sort(array):
    i = 0
    swapped = True

    while (swapped == True) and (i < len(array)):
        swapped = False

        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True

        i += 1
        print(array)

if __name__ == "__main__":
    unsorted_array1 = [9, 3, 2, 7, 1, 4, 5, 8, 6]
    print("Unsorted Array 1:", unsorted_array1)
    print("Bubble Sort:")
    bubble_sort(unsorted_array1)

    print()

    unsorted_array2 = [9, 3, 2, 7, 1, 4, 5, 8, 6]
    print("Unsorted Array 2:", unsorted_array2)
    print("Optimized Bubble Sort:")
    optimized_bubble_sort(unsorted_array2)
