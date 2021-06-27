public class Generics {

	public static <T> void genericMethod(T parameter) {
		System.out.println("Parameter " + parameter + " class = " + parameter.getClass().getName());
	}

	public static void main(String[] args) {
		SingleTypeGeneric<Integer> intGeneric = new SingleTypeGeneric<Integer>(2);
		System.out.println("intGeneric value = " + intGeneric.getValue());

		SingleTypeGeneric<String> stringGeneric = new SingleTypeGeneric<String>("string");
		System.out.println("stringGeneric value = " + stringGeneric.getValue());

		MultiTypeGeneric<Integer, String> multiTypeGeneric= new MultiTypeGeneric<Integer, String>(42, "Value 2");
		System.out.println("multiTypeGeneric value1 = " + multiTypeGeneric.getValue1());
		System.out.println("multiTypeGeneric value2 = " + multiTypeGeneric.getValue2());

		// BoundedGeneric<String, String> would throw an exception
		BoundedGeneric<Float, String> boundedGeneric = new BoundedGeneric<Float,String>(7.65f, "Unbounded type");
		System.out.println("boundedGeneric value1 = " + boundedGeneric.getValue1());
		System.out.println("boundedGeneric value1AsInt = " + boundedGeneric.getValue1AsInt());
		System.out.println("boundedGeneric value2 = " + boundedGeneric.getValue2());

		Generics.<Integer>genericMethod(4);
		Generics.<String>genericMethod("generic");
		Generics.genericMethod(5.44f);
		Generics.genericMethod(6);
	}
}