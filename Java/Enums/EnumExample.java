public class EnumExample {

    public static void main(String[] args) {
        System.out.println(Value.VALUE1 + "has value: " + Value.VALUE1.getValue());

        Value value2 = Value.VALUE2;
        System.out.println(value2 + "has value: " + value2.getValue());

        System.out.println("\nIterate through Value enum: ");
        for(Value value: Value.values()) {
            System.out.println(value + " = " + value.getValue());
        }
    }

}
