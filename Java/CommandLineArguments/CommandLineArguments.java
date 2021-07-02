public class CommandLineArguments {

    public static void main(String[] args) {
        if (args.length > 0) {
            System.out.println("Number of arguments provided: " + args.length + "\n");

            System.out.println("Provided arguments: ");
            for (String arg : args) {
                System.out.println(arg);
            }

            System.out.println();

            System.out.println("First argument provided: " + args[0]);
            System.out.println("Final argument provided: " + args[args.length - 1]);
        } else {
            System.out.println("No arguments provided");
        }
    }

}
