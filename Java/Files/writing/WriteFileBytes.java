package writing;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class WriteFileBytes {

    public static void writeBytesToFile(File file) {
        byte[] bytesToWrite = {65, 77, 97, 10, 9, 85, 103}; // String.getBytes() can also be used

        if(!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        try {
            FileOutputStream outputStream = new FileOutputStream(file);
            outputStream.write(bytesToWrite);

            outputStream.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        File fileToWrite = new File("./writing/bytes_output.txt");
        writeBytesToFile(fileToWrite);
    }

}
