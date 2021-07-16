def merge(array, left, right):
    i = 0
    j = 0
    k = 0

    while (i < len(left)) and (j < len(right)):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1

        k += 1

    while i < len(left):
        array[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        array[k] = right[j]
        j += 1
        k += 1

    print(array)

def merge_sort(array):
    if len(array) < 2:
        return

    mid = len(array) // 2
    left = array[mid:]
    right = array[:mid]

    merge_sort(left)
    merge_sort(right)

    merge(array, left, right)

if __name__ == "__main__":
    unsorted_array = [9, 3, 2, 7, 1, 4, 5, 8, 6]
    print("Unsorted Array:", unsorted_array)
    print("Merge Sort:")
    merge_sort(unsorted_array)
