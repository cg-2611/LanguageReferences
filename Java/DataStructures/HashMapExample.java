import java.util.concurrent.ConcurrentHashMap;

public class HashMapExample {

    public static void main(String[] args) {
        // ConcurrentHashMap is a thread-safe HashMap
        ConcurrentHashMap<String, String> hashMap = new ConcurrentHashMap<String, String>();

        hashMap.put("key1", "value1");
        hashMap.put("key4", "value4");
        hashMap.put("key3", "value3");
        hashMap.put("key5", "value5");
        hashMap.put("key2", "value2");

        System.out.println("HashMap: " + hashMap + "\tHashMap size: " + hashMap.size());

        System.out.println("\nHashMap value of \"key1\": " + hashMap.get("key1"));
        System.out.println("HashMap value of \"key3\": " + hashMap.get("key3"));

        // hashMap.get("key6") will return null as not in hashMap
        System.out.println("HashMap value of \"key6\": " + hashMap.get("key6"));

        hashMap.remove("key5");
        System.out.println("Removed \"key5\"");

        System.out.println("\nHashMap: " + hashMap + "\tHashMap size: " + hashMap.size());

        System.out.println();
        System.out.println("HashMap contains key \"key6\": " + hashMap.containsKey("key6"));
        System.out.println("HashMap contains value \"value6\": " + hashMap.containsValue("value6"));
        System.out.println("HashMap contains key \"key2\": " + hashMap.containsKey("key2"));
        System.out.println("HashMap contains value \"value2\": " + hashMap.containsValue("value2"));
        System.out.println("HashMap empty: " + hashMap.isEmpty());
        hashMap.clear();
        System.out.println("\nCleared hashMap\n");
        System.out.println("HashMap empty: " + hashMap.isEmpty());

    }

}
