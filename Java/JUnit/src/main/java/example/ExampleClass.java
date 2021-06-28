package example;

public class ExampleClass {

    private int value;

    public ExampleClass(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public double getSquareValue() {
        return Math.pow(value, 2);
    }

    // causes tests to fail
    // public double getSquareRootValue() {
    // 	return Math.sqrt(value);
    // }

    // passes previously failed tests
    public double getSquareRootValue() {
        return value >= 0 ? Math.sqrt(value) : -1;
    }

    // causes tests to fail
    // public double getLogValue() {
    // 	return Math.log(value);
    // }

    // passes previously failed tests
    public double getLogValue() {
        return value >= 1 ? Math.log(value) : -1;
    }
    
}