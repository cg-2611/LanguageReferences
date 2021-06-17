public class Strings {

    public static void main(String[] args) {
        String str = "This is a string.";
        
        System.out.println("String value: " + str);
        System.out.println("String length: " + str.length());
        System.out.println("String to lowercase: " + str.toLowerCase());
        System.out.println("String to uppercase: " + str.toUpperCase());
        System.out.println("String character at 5th index: " + str.charAt(5));
        System.out.println("String index of \'a\': " + str.indexOf('a'));
        System.out.println("String index of \'z\': " + str.indexOf('z'));
        System.out.println("String index of \"string\": " + str.indexOf("string"));
        System.out.println("String first index of \'i\': " + str.indexOf('i'));
        System.out.println("String last index of \'i\': " + str.lastIndexOf('i'));
        System.out.println("String from index 3: " + str.substring(3));
        System.out.println("String substring between index 3 and 12: " + str.substring(3, 12));
        System.out.println("String starts with \"The\": " + str.startsWith("The"));
        System.out.println("String starts with \"This\": " + str.startsWith("This"));
        System.out.println("String ends with \"string\": " + str.endsWith("string"));
        System.out.println("String ends with \".\": " + str.endsWith("."));

        System.out.println("\n");

        System.out.println("Each word in string: ");

        String[] strWords = str.split(" ");
        for (int i = 0; i < strWords.length; i++) {
            System.out.println(strWords[i]);
        }

        System.out.println("\n");

        System.out.println("Each character in string: ");

        char[] strCharacters = str.toCharArray();
        for (int i = 0; i < strCharacters.length; i++) {
            System.out.print(strCharacters[i] + "  ");
        }

        System.out.println("\n");

        String oldStr = str;
        str = str.replace("string", "java string");

        System.out.println("New string value: " + str);
        System.out.println("New string length: " + str.length()); 

        System.out.println("\n");

        System.out.print("Lexicographical difference between old string \"" + oldStr + "\" and new string \"" + str + "\": ");
        System.out.println(oldStr.compareTo(str));
    }
}