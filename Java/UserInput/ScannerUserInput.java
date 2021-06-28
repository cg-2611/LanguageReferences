import java.util.Scanner;

public class ScannerUserInput {
    
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String userInputString;
        int userInputInteger;

        System.out.print("Enter string: ");
        userInputString = reader.nextLine();

        System.out.print("Enter integer: ");
        userInputInteger = reader.nextInt();

        System.out.println("String entered: " + userInputString);
        System.out.println("Integer entered: " + userInputInteger);

        reader.close();
    }

}