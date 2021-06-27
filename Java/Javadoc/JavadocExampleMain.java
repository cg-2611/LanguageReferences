/**
 * Class that contains the main method for the example.
 */
public class JavadocExampleMain {
	public static void main(String[] args) {
		JavadocExampleClassOne classOne = new JavadocExampleClassOne(11);
		JavadocExampleClassTwo classTwo = new JavadocExampleClassTwo(14, "Class 2");

		System.out.println(classOne.getValue());
		System.out.println(classTwo.getValue());
		System.out.println(classTwo.getName());
		classTwo.setName("Class Two");
		System.out.println(classTwo.getName());
	}
}