import math

def jump_search(array, target):
    jump = math.sqrt(len(array))
    low = 0
    high = jump

    while (array[int(min(high, len(array))) - 1]) < target:
        low = high
        high += jump

        if low >= len(array):
            return -1

    while array[int(low)] < target:
        low += 1

        if low == min(high, len(array)):
            return -1

    if array[int(low)] == target:
        return int(low)
    else:
        return -1

if __name__ == "__main__":
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    print("7 found at index:", jump_search(array, 7))
    print("12 found at index:", jump_search(array, 12))
