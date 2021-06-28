package information;

import java.io.File;

public class FileInformation {

    public static void main(String[] args) {
        File file = new File("./information/file.txt");

        System.out.println("File path: " + file.getPath());
        System.out.println("File absolute path: " + file.getAbsolutePath());
        System.out.println("File name: " + file.getName());
        System.out.println("File total space: " + file.getTotalSpace() + " bytes");
        System.out.println("File usable space: " + file.getUsableSpace() + " bytes");
        System.out.println("File free space: " + file.getFreeSpace() + " bytes");
        System.out.println("File length: " + file.length() + " bytes");
        System.out.println("File last modified: " + file.lastModified());
        System.out.println("File can execute: " + file.canExecute());
        System.out.println("File can read: " + file.canRead());
        System.out.println("File can write: " + file.canWrite());
        System.out.println("File is absolute: " + file.isAbsolute());
        System.out.println("File is directory: " + file.isDirectory());
        System.out.println("File is file: " + file.isFile());
        System.out.println("File is hidden: " + file.isHidden());
    }
    
}