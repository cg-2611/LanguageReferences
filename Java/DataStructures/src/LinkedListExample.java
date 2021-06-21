import java.util.LinkedList;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        
        linkedList.add(11);
        linkedList.add(14);
        linkedList.add(16);
        linkedList.add(12);
        linkedList.add(13);

        System.out.print("LinkedList: ");
        for (int i = 0; i < linkedList.size() ; i++) {
            System.out.print(linkedList.get(i) + " | ");
        }
        System.out.println("\tLinkedList size: " + linkedList.size());

        linkedList.removeLast();  // removes tail of linkedList
        linkedList.removeFirst(); // removes head of linkedList

        System.out.print("\nLinkedList: ");
        for (Integer i : linkedList) {
            System.out.print(i + " | ");
        }
        System.out.println("\tLinkedList size: " + linkedList.size());

        linkedList.addFirst(Integer.valueOf(13)); // add 13 to head of linkedList
        linkedList.addLast(Integer.valueOf(18));  // add 18 to tail of linkedList
        linkedList.add(4, Integer.valueOf(11));   // add 11 to index 4 of linkedList

        System.out.print("\nLinkedList: " + linkedList); // calls the toString() method
        System.out.println("\tLinkedList size: " + linkedList.size() + "\n");

        System.out.println("LinkedList contains 9: " + linkedList.contains(Integer.valueOf(9)));
        System.out.println("LinkedList contains 14: " + linkedList.contains(Integer.valueOf(14)));
        System.out.println("LinkedList head: " + linkedList.getFirst());
        System.out.println("LinkedList tail: " + linkedList.getLast());
        System.out.println("LinkedList empty: " + linkedList.isEmpty());
        System.out.println("LinkedList index of 16: " + linkedList.indexOf(Integer.valueOf(16)));
        System.out.println("LinkedList sublist from index 2 to 5: " + linkedList.subList(2, 5));
        linkedList.clear();
        System.out.println("\nCleared linkedList\n");
        System.out.println("LinkedList empty: " + linkedList.isEmpty());

    }
}