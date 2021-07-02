public class InsertionSort {

    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    private static void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int elementToInsert = array[i];
            int previous = i - 1;

            while ((previous >= 0) && (array[previous] > elementToInsert)) {
                array[previous + 1] = array[previous];
                previous--;
            }

            array[previous + 1] = elementToInsert;
            printArray(array);
        }
    }

    public static void main(String[] args) {
        int[] unsortedArray  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("Unsorted Array: ");
        printArray(unsortedArray);

        System.out.println("\nInsertion Sort:");
        insertionSort(unsortedArray);
    }

}
