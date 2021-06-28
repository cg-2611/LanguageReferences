import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BufferedReaderUserInput {
    
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            String userInputString;
            int userInputInteger;

            System.out.print("Enter string: ");
            userInputString = br.readLine();

            System.out.print("Enter integer: ");
            userInputInteger = Integer.parseInt(br.readLine());

            System.out.println("String entered: " + userInputString);
            System.out.println("Integer entered: " + userInputInteger);

            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}