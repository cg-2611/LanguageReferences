def binary_search(array, target, low, high):
    mid = low + ((high - low) // 2)

    if high < low:
        return -1

    if target == array[mid]:
        return mid
    elif target < array[mid]:
        return binary_search(array, target, low, mid - 1)
    else:
        return binary_search(array, target, mid + 1, high)

if __name__ == "__main__":
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    print("7 found at index:", binary_search(array, 7, 0, len(array) - 1))
    print("12 found at index:", binary_search(array, 12, 0, len(array) - 1))
