package example;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class ExampleClassTest {

    private static ExampleClass exampleObject;
    private static int i;

    @BeforeAll
    static void announceAllTestStartAndInitialiseExampleObject() {
        exampleObject = new ExampleClass(4);
        i = 1;
        System.out.println("Starting tests on ExampleClass...");
    }

    @BeforeEach
    void announceEachTestStart() {
        System.out.println("Executing test " + i + ":");
    }

    @Test
    @DisplayName("The value passed to the constructor is stored by the object")
    void valueIsSetProperlyInConstructor() {
        Assertions.assertEquals(4, exampleObject.getValue());
    }

    @Test
    @DisplayName("The value is squared correctly")
    void valueIsSquaredCorrectly() {
        Assertions.assertEquals(16, exampleObject.getSquareValue());
    }

    @Test
    @DisplayName("The value is square rooted correctly when > 0")
    void valueIsSquareRootedCorrectlyWithAPositiveInteger() {
        Assertions.assertEquals(2, exampleObject.getSquareRootValue());
    }

    @Test
    @DisplayName("The value is square rooted correctly when = 0")
    void valueIsSquareRootedCorrectlyWhenEqualToZero() {
        ExampleClass zeroExampleObject = new ExampleClass(0);
        Assertions.assertEquals(0, zeroExampleObject.getSquareRootValue());
    }

    @Test
    @DisplayName("The returned square root of the value is -1 when < 0")
    void  valueIsSquareRootedCorrectlyWithANegativeInteger() {
        ExampleClass negativeExampleObject = new ExampleClass(-4);
        Assertions.assertEquals(-1, negativeExampleObject.getSquareRootValue());
    }

    @Test
    @DisplayName("The returned natural log of the value is correct when > 1")
    void valueLogIsCorrectWithPositiveIntegerGreaterThanOne() {
        Assertions.assertEquals(1.3862943611198906, exampleObject.getLogValue());
    }

    @Test
    @DisplayName("The returned natural log of the value is correct when = 1")
    void valueLogIsCorrectWithPositiveIntegerEqualToOne() {
        ExampleClass oneExampleObject = new ExampleClass(1);
        Assertions.assertEquals(0, oneExampleObject.getLogValue());
    }

    @Test
    @DisplayName("The returned natural log of the value is -1 when = 0")
    void valueLogIsCorrectWithIntegerEqualToZero() {
        ExampleClass zeroExampleObject = new ExampleClass(0);
        Assertions.assertEquals(-1, zeroExampleObject.getLogValue());
    }

    @Test
    @DisplayName("The returned natural log of the value is -1 when < 0")
    void valueLogIsCorrectWithPositiveInteger() {
        ExampleClass negativeExampleObject = new ExampleClass(-4);
        Assertions.assertEquals(-1, negativeExampleObject.getLogValue());
    }

    @AfterEach
    void announceEachTestEnd() {
        System.out.println("Finished test " + i);
        i++;
    }

    @AfterAll
    static void announceAllTestEnd() {
        System.out.println("Finished tests on ExampleClass");
    }

}
