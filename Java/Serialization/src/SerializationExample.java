import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class SerializationExample {

    public static void serializeObject(SerializableClass object, File file) {
        try {
            if(!file.exists()) {
                file.createNewFile();
            }

            ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream(file));

            objectOutputStream.writeObject(object);

            objectOutputStream.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static SerializableClass deserializeObject(File file) {
        SerializableClass object = null;

        try {
            ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(file));

            object = (SerializableClass) inputStream.readObject();

            inputStream.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        return object;
    }

    public static void printFields(SerializableClass object) {
        System.out.println("intValue = " + object.getIntValue());
        System.out.println("stringValue = " + object.getStringValue());
        System.out.println("transientInt = " + object.getTransientInt());
        System.out.println("transientString = " + object.getTransientString());
        System.out.println("finalTransientInt = " + object.finalTransientInt);
        System.out.println("finalTransientString = " + object.finalTransientString);
    }

    public static void main(String[] args) {
        File outputFile = new File("./src/serialized_object.bin");

        SerializableClass serializableObject = new SerializableClass(3, "string", 5, "transient string");

        System.out.println("Before Serialization: ");
        printFields(serializableObject);

        serializeObject(serializableObject, outputFile);

        SerializableClass objectRead = deserializeObject(outputFile);

        System.out.println("\nAfter Serialization: ");
        printFields(objectRead);
    }
}