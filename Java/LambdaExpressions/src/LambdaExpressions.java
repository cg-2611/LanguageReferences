import java.util.ArrayList;
import java.util.function.Consumer;

public class LambdaExpressions {

    public static void printString(FunctionalInterfaceExample stringInterface) {
        System.out.println(stringInterface.getString());
    }

    public static void main(String[] args) {
        FunctionalInterfaceExample functionalInterface;
        functionalInterface = () -> { return "String"; };
        System.out.println(functionalInterface.getString());

        System.out.println();
        printString(functionalInterface = () -> { return "New String"; });

        System.out.println();
        ArrayList<Integer> array = new ArrayList<Integer>();
        array.add(3);
        array.add(2);
        array.add(5);
        array.add(1);
        array.add(4);
        array.forEach( (n) -> { System.out.println(n); } );

        System.out.println();
        Consumer<Integer> outputElement = (n) -> { System.out.println(n); };
        array.forEach(outputElement);

        System.out.println();
        Consumer<Integer> outputElementFactorial = (n) -> {
            int factorial = 1;
            for (int i = 1; i <= n; i++) {
                factorial *= i;
            }
            
            System.out.println(factorial);
        };
        array.forEach(outputElementFactorial);

    }
}