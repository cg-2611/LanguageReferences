import java.util.Stack;

public class StackExample {
	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();

		stack.push(122);
		stack.push(145);
		stack.push(109);
		stack.push(156);
		stack.push(134);

		System.out.print("Stack: ");
		for(int i = 0; i < stack.size(); i++) {
			System.out.print(stack.get(i) + " | ");
		}
		System.out.println("\tStack size: " + stack.size());

		stack.pop();
		stack.pop();

		System.out.print("\nStack: ");
		for(Integer i : stack) {
			System.out.print(i + " | ");
		}
		System.out.println("\tStack size: " + stack.size());

		stack.pop();
		stack.push(156);
		stack.push(117);

		System.out.print("\nStack: " + stack); // calls the toString() method
		System.out.println("\tStack size: " + stack.size() + "\n");

		System.out.println("Stack top: " + stack.peek());
		System.out.println("Stack empty: " + stack.isEmpty());
		stack.clear();
		System.out.println("\nCleared stack\n");
		System.out.println("Stack empty: " + stack.isEmpty());
	}
}
