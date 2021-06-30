public class Casting {

    public static void main(String[] args) {
        // this program contains just a few examples
        // all primitive types have wrapper objects and so can be cast in similar ways

        Integer integer = 3;
        Float floatValue = 4.62f;
        Double doubleValue = 7.56;
        Character character = 'c';

        // casting integer to float using wrapper objects
        Float floatFromInteger = integer.floatValue();
        System.out.println("Integer = " + integer + " -> Float = " + floatFromInteger);

        System.out.println();

        // casting float to integer using wrapper objects
        Integer integerFromFloat;
        integerFromFloat = (int)floatValue.floatValue();
        System.out.println("Method 1: Float = " + floatValue + " -> Integer = " + integerFromFloat);

        integerFromFloat = Math.round(floatValue);
        System.out.println("Method 2: Float = " + floatValue + " -> Integer = " + integerFromFloat);

        System.out.println();

        // casting integer to double using wrapper objects
        Double doubleFromInteger = integer.doubleValue();
        System.out.println("Integer = " + integer + " -> Double = " + doubleFromInteger);

        System.out.println();

        // casting double to integer using wrapper objects
        Integer integerFromDouble;
        integerFromDouble = (int)doubleValue.doubleValue();
        System.out.println("Method 1: Double = " + doubleValue + " -> Integer = " + integerFromDouble);

        integerFromDouble = (int)Math.round(doubleValue);
        System.out.println("Method 2: Double = " + doubleValue + " -> Integer = " + integerFromDouble);

        System.out.println();

        // casting to String using wrapper objects
        String stringFromInteger = String.valueOf(integer);
        String stringFromFloat = String.valueOf(floatValue);
        String stringFromDouble = String.valueOf(doubleValue);
        String stringFromCharacter = String.valueOf(character);

        System.out.println(stringFromInteger + " is String? " + (stringFromInteger instanceof String));
        System.out.println(stringFromFloat + " is String? " + (stringFromFloat instanceof String));
        System.out.println(stringFromDouble + " is String? " + (stringFromDouble instanceof String));
        System.out.println(stringFromCharacter + " is String? " + (stringFromCharacter instanceof String));

        System.out.println();

        // casting from String using wrapper objects
        Integer integerFromString = Integer.parseInt("6");
        Float floatFromString = Float.parseFloat("2.98");
        Double doubleFromString = Double.parseDouble("8.12");

        System.out.println(integerFromString + " is Integer? " + (integerFromString instanceof Integer));
        System.out.println(floatFromString + " is Float? " + (floatFromString instanceof Float));
        System.out.println(doubleFromString + " is Double? " + (doubleFromString instanceof Double));
    }
    
}
