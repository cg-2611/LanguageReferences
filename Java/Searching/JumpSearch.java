public class JumpSearch {

    private static int jumpSearch(int[] array, int target) {
        double jump = Math.sqrt(array.length);
        double low = 0;
        double high = jump;

        while (array[(int) Math.min(high, array.length) - 1] < target) {
            low = high;
            high += jump;

            if (low >= array.length) {
                return -1;
            }
        }

        while (array[(int)low] < target) {
            low++;

            if (low == Math.min(high, array.length)) {
                return -1;
            }
        }

        if (array[(int)low] == target) {
            return (int)low;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        System.out.println("7 found at index: " + jumpSearch(array, 7));
        System.out.println("12 found at index: " + jumpSearch(array, 12));
    }

}
