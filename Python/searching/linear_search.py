def linear_search(array, target):
    for i in range(len(array)):
        if array[i] == target:
            return i

    return -1

if __name__ == "__main__":
    array = [9, 3, 2, 7, 1, 4, 5, 8, 6]

    print("7 found at index:", linear_search(array, 7))
    print("12 found at index:", linear_search(array, 12))
