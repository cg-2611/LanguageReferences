public class InterpolationSearch {

    private static int interpolationSearch(int[] array, int target) {
        int low = 0;
        int high = array.length - 1;
        int mid;

        while ((array[high] != array[low]) && (target >= array[low]) && (target <= array[high])) {

            mid = low + ((target - array[low]) * (high - low)) / (array[high] - array[low]);

            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                return mid;
            }
        }

        if (target == array[low]) {
            return low;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        System.out.println("7 found at index: " + interpolationSearch(array, 7));
        System.out.println("12 found at index: " + interpolationSearch(array, 12));
    }

}
