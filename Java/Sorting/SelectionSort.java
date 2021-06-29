public class SelectionSort {
    
    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    private static void selectionSort(int[] array) {
        for (int i = 0; i < array.length - 2; i++) {
            int smallestIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[smallestIndex]) {
                    smallestIndex = j;
                }
            }

            int temp = array[i];
            array[i] = array[smallestIndex];
            array[smallestIndex] = temp;

            printArray(array);
        }
    }
    
    public static void main(String[] args) {
        int[] unsortedArray  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
        System.out.println("Unsorted Array: ");
        printArray(unsortedArray);
        
        System.out.println("\nSelection Sort:");
        selectionSort(unsortedArray);
    }

}