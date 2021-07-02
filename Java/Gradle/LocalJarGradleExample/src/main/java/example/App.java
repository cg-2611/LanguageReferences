package example;

import example.library.one.ExampleClassOne;
import example.library.two.ExampleClassTwo;

public class App {

    public static void main(String[] args) {
        ExampleClassOne classOne = new ExampleClassOne(2);
        ExampleClassTwo classTwo = new ExampleClassTwo("string");

        System.out.println(classOne.getValue());
        System.out.println(classTwo.getString());

        classOne.setValue(4);
        classTwo.setString("new string");

        System.out.println(classOne.getValue());
        System.out.println(classTwo.getString());
    }

}
