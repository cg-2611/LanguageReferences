public class BubbleSort {

    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    private static void bubbleSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length  - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }

            printArray(array);
        }
    }

    private static void optimizedBubbleSort(int[] array) {
        int i = 0;
        boolean swapped = true;

        while ((swapped == true) && (i < array.length)) {
            swapped = false;
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true;
                }

            }
            i++;
            printArray(array);
        }
    }

    public static void main(String[] args) {
        int[] unsortedArray1  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("Unsorted Array 1: ");
        printArray(unsortedArray1);

        System.out.println("\nBubble Sort:");
        bubbleSort(unsortedArray1);

        int[] unsortedArray2  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("\nUnsorted Array 2: ");
        printArray(unsortedArray2);

        System.out.println("\nOptimized Bubble Sort:");
        optimizedBubbleSort(unsortedArray2);
    }

}
