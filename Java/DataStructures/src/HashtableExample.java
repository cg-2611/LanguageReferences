import java.util.Hashtable;

public class HashtableExample {
    public static void main(String[] args) {
        // Hashtable is similar to a HashMap, but is thread safe and doesn't allow null values or keys
        Hashtable<String, String> hashtable = new Hashtable<String, String>();

        hashtable.put("key1", "value1");
        hashtable.put("key4", "value4");
        hashtable.put("key3", "value3");
        hashtable.put("key5", "value5");
        hashtable.put("key2", "value2");

        System.out.println("Hashtable: " + hashtable + "\tHashtable size: " + hashtable.size());
        
        System.out.println("\nHashtable value of \"key1\": " + hashtable.get("key1"));
        System.out.println("Hashtable value of \"key3\": " + hashtable.get("key3"));
        
        // hashtable.get("key6") will return null as not in hashtable
        System.out.println("Hashtable value of \"key6\": " + hashtable.get("key6"));
        
        hashtable.remove("key5");
        System.out.println("Removed \"key5\"");
        
        System.out.println("\nHashtable: " + hashtable + "\tHashtable size: " + hashtable.size());

        System.out.println();
        System.out.println("Hashtable contains key \"key6\": " + hashtable.containsKey("key6"));
        System.out.println("Hashtable contains value \"value6\": " + hashtable.containsValue("value6"));
        System.out.println("Hashtable contains key \"key2\": " + hashtable.containsKey("key2"));
        System.out.println("Hashtable contains value \"value2\": " + hashtable.containsValue("value2"));
        System.out.println("Hashtable empty: " + hashtable.isEmpty());
        hashtable.clear();
        System.out.println("\nCleared hashtable\n");
        System.out.println("Hashtable empty: " + hashtable.isEmpty());
        
    }
}
