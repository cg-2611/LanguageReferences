public class LinearSearch {

    private static int linearSearch(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] array = {9, 3, 2, 7, 1, 4, 5, 8, 6};

        System.out.println("7 found at index: " + linearSearch(array, 7));
        System.out.println("12 found at index: " + linearSearch(array, 12));
    }

}
