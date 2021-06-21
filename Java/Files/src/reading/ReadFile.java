package reading;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ReadFile {

    public static void readFileWithScanner(File file) {
        try {
            Scanner reader = new Scanner(file);
            String line;

            while(reader.hasNextLine()) {
                line = reader.nextLine();
                System.out.println(line);
            }

            reader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void readFileWithBufferedReader(File file) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));

            String line;

            while((line = br.readLine()) != null) {
                System.out.println(line);
            }

            br.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        File fileToRead = new File("./src/reading/file.txt");

        System.out.println("Read Using Scanner:");
        readFileWithScanner(fileToRead);
        System.out.println();

        System.out.println("Read Using BufferedReader: ");
        readFileWithBufferedReader(fileToRead);
        System.out.println();
    }
}