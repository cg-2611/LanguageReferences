public class Overloading {

    public static void printMethodArgs(String arg) {
        System.out.println("Method arguments: " + arg);
    }

    public static void printMethodArgs(String arg1, String arg2) {
        System.out.println("Method arguments: " + arg1 + " and " + arg2);
    }

    public static void printMethodArgs(String arg1, String arg2, String arg3) {
        System.out.println("Method arguments: " + arg1 + ", " + arg2 + " and " + arg3);
    }

    // use ... to support multiple arguments without needing an array
    public static void printMethodArgs(String... args) {
        System.out.print("Method arguments: ");
        for (String arg: args) {
            System.out.print(arg + ", ");
        }
    }

    public static void main(String[] args) {
        printMethodArgs("Argument 1");
        printMethodArgs("Argument 1", "Argument 2");
        printMethodArgs("Argument 1", "Argument 2", "Argument 3");
        printMethodArgs("Argument 1", "Argument 2", "Argument 3", "Argument 4", "Argument 5", "Argument 6");
    }
    
}