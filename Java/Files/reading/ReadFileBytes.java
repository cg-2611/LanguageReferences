package reading;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class ReadFileBytes {

	public static void readBytesFromFile(File file) {
		byte[] buffer = new byte[1024];

		try {
			FileInputStream inputStream = new FileInputStream(file);

			int totalBytesRead = 0;
			int currentBytesRead = 0;
			while((currentBytesRead = inputStream.read(buffer)) != -1) {
				System.out.println("Read " + currentBytesRead + " bytes: ");

				for (int i = 0; i < currentBytesRead; i++) {
					System.out.print(buffer[i] + " ");
				}

				System.out.println("\nBytes as string: \n" + new String(buffer, "UTF-8"));

				totalBytesRead += currentBytesRead;
			}

			inputStream.close();

			System.out.println("\nRead " + totalBytesRead + " total bytes.");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		File fileToRead = new File("./reading/file.txt");

		readBytesFromFile(fileToRead);
	}
}
