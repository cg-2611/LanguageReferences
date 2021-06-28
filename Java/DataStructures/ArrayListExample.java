import java.util.ArrayList;

public class ArrayListExample {

    public static void main(String[] args) {
        // ArrayList is a dynamic data structure that behaves similarly to an array
        ArrayList<Integer> arrayList = new ArrayList<Integer>();

        arrayList.add(3); // append 3 to arrayList
        arrayList.add(2);
        arrayList.add(5);
        arrayList.add(7);
        arrayList.add(6);

        System.out.print("ArrayList: ");
        for (int i = 0; i < arrayList.size() ; i++) {
            System.out.print(arrayList.get(i) + " | ");
        }
        System.out.println("\tArrayList size: " + arrayList.size());

        arrayList.remove(2);                  // remove element at index 2
        arrayList.remove(Integer.valueOf(6)); // removes element with value 6

        System.out.print("\nArrayList: ");
        for (Integer i : arrayList) {
            System.out.print(i + " | ");
        }
        System.out.println("\tArrayList size: " + arrayList.size());

        arrayList.add(0, 5); // add 5 at index 0
        arrayList.add(1, 7); // add 7 at index 1
        arrayList.add(4, 6); // add 6 at index 4

        System.out.print("\nArrayList: " + arrayList); // calls the toString() method
        System.out.println("\tArrayList size: " + arrayList.size() + "\n");

        System.out.println("ArrayList contains 9: " + arrayList.contains(Integer.valueOf(9)));
        System.out.println("ArrayList contains 3: " + arrayList.contains(Integer.valueOf(3)));
        System.out.println("ArrayList index of 7: " + arrayList.indexOf(Integer.valueOf(7)));
        System.out.println("ArrayList last index of 7: " + arrayList.lastIndexOf(Integer.valueOf(7)));
        System.out.println("ArrayList sublist from index 2 to 5: " + arrayList.subList(2, 5));
        System.out.println("ArrayList empty: " + arrayList.isEmpty());
        arrayList.clear();
        System.out.println("\nCleared arrayList\n");
        System.out.println("ArrayList empty: " + arrayList.isEmpty());
    }
    
}