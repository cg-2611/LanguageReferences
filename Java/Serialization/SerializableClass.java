import java.io.Serializable;

public class SerializableClass implements Serializable {

    private int intValue;
    private String stringValue;

    // transient fields will not be serialized
    private transient int transientInt;
    private transient String transientString;

    // final transient will get serialized
    public final transient int finalTransientInt = 10;
    public final transient String finalTransientString = "final transient string";

    public SerializableClass(int intValue, String stringValue, int transientInt, String transientString) {
        this.intValue = intValue;
        this.stringValue = stringValue;
        this.transientInt = transientInt;
        this.transientString = transientString;
    }

    public int getIntValue() {
        return intValue;
    }

    public String getStringValue() {
        return stringValue;
    }

    public int getTransientInt() {
        return transientInt;
    }

    public String getTransientString() {
        return transientString;
    }

}
