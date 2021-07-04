public class QuickSort {

    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    private static int partition(int[] array, int start, int end) {
        int pivot = array[end];
        int index = start - 1;

        for (int j = start; j < end; j++) {
            if (array[j] <= pivot) {
                index++;

                int temp = array[index];
                array[index] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[index + 1];
        array[index + 1] = array[end];
        array[end] = temp;

        printArray(array);

        return index + 1;
    }

    private static void quickSort(int[] array, int start, int end) {
        if (start < end) {
            int partitionIndex = partition(array, start, end);

            quickSort(array, start, partitionIndex - 1);
            quickSort(array, partitionIndex + 1, end);
        }
    }

    public static void main(String[] args) {
        int[] unsortedArray  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("Unsorted Array: ");
        printArray(unsortedArray);

        System.out.println("\nQuick Sort:");
        quickSort(unsortedArray, 0, unsortedArray.length - 1);
    }

}
