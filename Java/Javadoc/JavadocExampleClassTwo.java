/**
 * JavadocExampleClassTwo extends the {@link JavadocExampleClassOne} class and stores a name.
 */
public class JavadocExampleClassTwo extends JavadocExampleClassOne{

    /**
     * The name of the object.
     */
    private String name;

    /**
     * Creates a new instance of JavadocExampleClassTwo.
     * @param value the value of the object
     * @param name the name of the object
     */
    public JavadocExampleClassTwo(int value, String name) {
        super(value);
        this.name = name;
    }

    /**
     * Sets {@code name} to a new value.
     * @param name the new value for {@code name}
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Gets the name of the object.
     * @return the name of the object.
     */
    public String getName() {
        return name;
    }

}
