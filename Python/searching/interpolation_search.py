def interpolation_search(array, target):
    low = 0
    high = len(array) - 1

    while (array[high] != array[low]) and (target >= array[low]) and (target <= array[high]):
        mid = low + (((target - array[low]) * (high - low)) // (array[high] - array[low]))

        if target > array[mid]:
            low = mid + 1
        elif target < array[mid]:
            high = mid - 1
        else:
            return mid

    if target == array[low]:
        return low
    else:
        return -1

if __name__ == "__main__":
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    print("7 found at index:", interpolation_search(array, 7))
    print("12 found at index:", interpolation_search(array, 12))
