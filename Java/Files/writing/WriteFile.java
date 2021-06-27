package writing;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class WriteFile {

	public static void writeFileWithBufferedWriter(File file) {
		String textToWrite = "This is\n\n\tA\nTest string";
		String textToAppend = "This string\n\twas\nappended";

		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(file));
			bw.write(textToWrite);
			bw.append(textToAppend);

			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static void main(String[] args) {
		File fileToWrite = new File("./writing/output.txt");
		writeFileWithBufferedWriter(fileToWrite);
	}
}
