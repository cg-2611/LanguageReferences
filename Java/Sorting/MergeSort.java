public class MergeSort {

    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    private static void merge(int[] array, int[] left, int[] right, int leftIndex, int rightIndex) {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < leftIndex && j < rightIndex) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        while (i < leftIndex) {
            array[k++] = left[i++];
        }

        while (j < rightIndex) {
            array[k++] = right[j++];
        }

        printArray(array);
    }

    private static void mergeSort(int[] array, int length) {
        if (length < 2) {
            return;
        }

        int mid = length / 2;
        int[] left = new int[mid];
        int[] right = new int[length - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = array[i];
        }
        for (int i = mid; i < length; i++) {
            right[i - mid] = array[i];
        }
        mergeSort(left, mid);
        mergeSort(right, length - mid);

        merge(array, left, right, mid, length - mid);
    }

    public static void main(String[] args) {
        int[] unsortedArray  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("Unsorted Array: ");
        printArray(unsortedArray);

        System.out.println("\nQuick Sort:");
        mergeSort(unsortedArray, unsortedArray.length);
    }

}
