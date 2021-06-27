public class BoundedGeneric<T extends Number, S> {

	private T value1;
	private S value2;

	public BoundedGeneric(T value1, S value2) {
		this.value1 = value1;
		this.value2 = value2;
	}

	public T getValue1() {
		return value1;
	}

	public int getValue1AsInt() {
		return value1.intValue();
	}

	public S getValue2() {
		return value2;
	}

}
