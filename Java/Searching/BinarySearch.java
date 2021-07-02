public class BinarySearch {

    private static int binarySearch(int[] array, int target, int low, int high) {
        int mid = low  + ((high - low) / 2);

        if (high < low) {
            return -1;
        }

        if (target == array[mid]) {
            return mid;
        } else if (target < array[mid]) {
            return binarySearch(array, target, low, mid - 1);
        } else {
            return binarySearch(array, target, mid + 1, high);
        }
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        System.out.println("7 found at index: " + binarySearch(array, 7, 0, array.length - 1));
        System.out.println("12 found at index: " + binarySearch(array, 12, 0, array.length - 1));
    }

}
