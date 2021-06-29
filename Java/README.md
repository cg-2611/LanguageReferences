# Java

## Contents
- [Language Basics](#language-basics)
    - [Entry Point](#entry-point)
    - [Comments](#comments)
    - [Variables and Constants](#variables-and-constants)
        - [Variables](#variables)
        - [Constants](#constants)
    - [Arrays](#arrays)
    - [Primitive Data Types](#primitive-data-types)
    - [Casting Primitive Types](#casting-primitive-types)
    - [Operators](#operators)
        - [Unary Operators](#unary-operators)
        - [Arithmetic Operators](#arithmetic-operators)
        - [Comparison Operators](#comparison-operators)
        - [Logical Operators](#logical-operators)
        - [Bitwise Operators](#bitwise-operators)
        - [Assignment Operators](#assignment-operators)
        - [Miscellaneous Operators](#miscellaneous-operators)
    - [Control Flow Statements](#control-flow-statements)
        - [Decision Making](#decision-making)
        - [Loop Control](#loop-control)
- [Classes and Objects](#classes-and-objects)
    - [Access Modifiers](#access-modifiers)
        - [Class Access Modifiers](#for-classes)
        - [Class Member Access Modifiers](#for-class-members)
    - [Classes](#classes)
        - [Declaring Classes](#declaring-classes)
        - [Constructor](#constructor)
        - [Instance Fields](#instance-fields)
        - [Instance Methods](#instance-methods)
        - [Referencing Current Object](#referencing-current-object)
        - [Class Fields](#class-fields)
        - [Class Methods](#class-methods)
        - [Nested Classes](#nested-classes)
    - [Objects](#objects)
        - [Object Creation](#object-creation)
        - [Accessing Members](#accessing-members)
    - [Interfaces](#interfaces)
        - [Declaring Interfaces](#declaring-interfaces)
        - [Implementing Interfaces](#implementing-interfaces)
        - [Extending Interfaces](#extending-interfaces)
        - [Default Methods](#default-methods)
    - [Abstract Classes](#abstract-classes)
        - [Declaring Abstract Classes](#declaring-abstract-classes)
        - [Using Abstract Classes](#using-abstract-classes)
- [Error Handling](#error-handling)
    - [Throwing Exceptions](#throwing-exceptions)
    - [Handling Exceptions](#handling-exceptions)
- [Executing Programs](#executing-programs)
    - [Compiling](#compiling)
    - [Creating `jar` Files](#creating-jar-files)
    - [Running](#running)
- [Javadoc](#javadoc)
    - [Writing](#writing)
    - [Generating](#generating)
- [Useful Links](#useful-links)
    - [Java Documentation](#java-documentation)
    - [Execution Documentation](#execution-documentation)
    - [Javadoc Documentation](#javadoc-documentation)
    - [General Information](#general-information)

## Language Basics
### Entry Point
---
```java
public static void main(String[] args) {
    // do something
}
```
### Comments
---
```java
// single line comment

/*
 * multi-line comment
 */

/**
 * javadoc comment
 */
```
### Variables and Constants
---
#### Variables:
```java
type identifier;         // has value of 'null' until initialised
type identifier = value; // has value of 'value'
```
#### Constants:
```java
static final type identifier = value;
```
### Arrays
---
```java
// declare array and allocate memory for n elements
type[] identifier = new type[n];

// declare and initialise array of 3 elements
type[] identifier = {element 1, element 2, element 3};
```
### Primitive Data Types
---
```java
byte    // 8 bits,  1 byte 
short   // 16 bits, 2 bytes
int	    // 32 bits, 4 bytes
long    // 64 bits, 8 bytes
float   // 32 bits, 4 bytes
double  // 64 bits, 8 bytes
char    // 16 bits, 2 bytes
boolean // 1 bit
```
### Casting Primitive Types
---
```java
// from a smaller type to a larger type:
int x = 4;
double y = x;

// from a larger type to a smaller type:
double x = 4.62;
int y = (int) x; // y has value 4
```
### Operators
---
### Unary Operators:
```java
+x  // positive value
-x  // negative value
x++ // postfix increment
++x // prefix increment
x-- // postfix decrement
--x // prefix decrement
```
#### Arithmetic Operators:
```java
x + y // addition
x - y // subtraction
x * y // multiplication
x / y // division
x % y // modulus
```
#### Comparison Operators:
```java
x == y // equal
x != y // not equal
x > y  // greater than
x < y  // less than
x >= y // greater than or equal to
x <= y // less than or equal to
```
#### Logical Operators:
```java
x && y // logical AND
x || y // logical OR
!x	   // logical NOT
```
#### Bitwise Operators:
```java
&   // binary AND
|   // binary OR
^   // binary XOR
~   // binary complement
<<  // binary left shift
>>  // binary right shift
>>> // binary shift right zero fill 
```
#### Assignment Operators:
```java
=   // simple assignment
+=  // add and assign
-=  // subtract and assign
*=  // multiply and assign
/=  // divide and assign
%=  // modulus and assign
<<= // left shift and assign
>>= // right shift and assign
&=  // bitwise AND and assign
|=  // bitwise OR and assign
^=  // bitwise XOR and assign
```
#### Miscellaneous Operators:
```java
?:         // conditional/ternary operator
instanceof // returns if an object is an instance of a given class
```
### Control Flow Statements
---
#### Decision Making:
```java
// if statement
if (condition) {
    // do something
} else if (another condition) {
    // do something else
} else {
    // do something if no conditions met
}

// conditional operator
(condition) ? (valueIfTrue) : (valueIfFalse);

// switch statement (breaks optional)
switch (expression) {
    case value 1:
        // do something and fall through
    case value 2: 
        // do something else
        break;
    default:
        // do something if no cases matched
        break;
}
```
#### Loop Control:
```java
// for loop
for (initialisation; condition; update) {
    // do something
}

// for-each loop
for (type object : array) {

}

// while loop
while (condition) {
    // do something
}

// do-while loop
do {
    // do something
} while (condition);
```

## Classes and Objects
### Access Modifiers
---
#### For Classes:
```java
public      // available to all other classes
no modifier // available to all classes in current package
```
#### For Class Members:
```java
public      // available to all other classes
protected   // available to classes within package or any subclasses
no modifier // available to classes within package only
private     // available to class only
```
### Classes
---
#### Declaring Classes:
```java
public class ClassName extends SuperClass {
    // class body

    @Override
    modifier type superClassMethod(type parameter 1) {
        // do something
    }
}
```
#### Constructor:
```java
modifier ClassName(type parameter1, type parameter2) {
    // do something
}
```
#### Instance Fields:
```java
modifiers type identifier;         // has value of 'null' until initialised
modifiers type identifier = value; // has value of 'value'
```
#### Instance Methods:
```java
modifiers type methodName(type parameter1, type parameter2) throws Exception {
    // method body
}
```
#### Referencing Current Object:
```java
this.field         // accesses field 'field' of current object
this.doSomething() // calls method 'doSomething' of current object
```
#### Class Fields:
```java
modifiers static type identifier;         // has value of 'null' until initialised
modifiers static type identifier = value; // has value of 'value'
```
#### Class Methods:
```java
modifiers static type methodName(type param1, type param2) throws Exception {
    // method body
}
```
#### Nested Classes:
```java
modifier class OuterClass {
    // outer class body

    modifier class InnerClass {
        // inner class body
    }
}
```
### Objects
---
#### Object Creation:
```java
ClassName identifier = new ClassName(argument1, argument2);
```
#### Accessing Members:
```java
object.field         // access field 'field' of object 'object'
object.doSomething() // calls method 'doSomething' of object 'object'
```
### Interfaces
---
#### Declaring Interfaces:
```java
public interface InterfaceName {
    // declare abstract methods
    modifiers type abstractMethod1();
    modifiers type abstractMethod2(type parameter1, type parameter2);
}
```
#### Implementing Interfaces:
```java
public class ClassName implements InterfaceOne, InterfaceTwo {
    // class body

    modifiers type interfaceOneMethod(type parameter1) {
        // method body
    }

    modifiers type interfaceTwoMethod(type parameter2) {

    }
}
```
#### Extending Interfaces:
```java
public interface InterfaceName extends SuperInterfaceOne, SuperInterfaceTwo {
    // interface body
}
```
#### Default Methods:
```java
public interface InterfaceName {
    // interface body

    default type defaultInterfaceMethodOne(type parameter1, type parameter2) {
        // method body
    }

    default type defaultInterfaceMethodTwo() {
        // method body
    }
}
```
### Abstract Classes:
---
#### Declaring Abstract Classes:
```java
public abstract class AbstractClassName {

    // abstract classes cannot be instantiated, but the constructor
    // can be called by subclasses
    public AbstractClassName() {
        // constructor body
    }

    modifiers abstract type methodOne(type parameter1);

    modifiers type methodTwo() {
        // method body
    }

}
```
#### Using Abstract Classes:
```java
modifiers class ClassName extends AbstractClassName {
    modifiers ClassName() {
        super() // calls constructor of AbstractClassName

        //constructor body
    }

    @Override
    modifiers type methodOne(type parameter1) {
        // method body
    }

    @Override
    modifiers type methodTwo() {
        // new method body
    }
}
```

## Error Handling
### Throwing Exceptions:
---
```java
throw new Exception(); // throws a new Exception object

// method that throws Exception1 and Exception2 that must be caught
public void doSomething() throws Exception1, Exception2 {
    // do something
}
```
### Handling Exceptions:
---
```java
try {
    // do something
} catch (Exception e) {
    // catch exceptions and deal with them
} finally {
    // executes no matter if there was an exception or not
}
```

## Executing Programs
### Compiling
---
To compile a java program using the `javac` command, run:
```
javac -cp path/to/src -d path/to/bin path/to/src/**/*.java
```
The `-cp` option specifies the classpath and `-d` specifies the output directory.

e.g. if the command is being run from the project root directory, run:
```
javac -cp ./src -d ./bin ./src/**/*.java
```
> Note: using `src/**/*.java` will maintain the package structure in the output directory specified by the `-d` option. 
### Creating `jar` Files
---
To compress a java program into a `jar` file using the `jar` command, run:
```
jar -c -f jar-name.jar -e MainClass -C path/to/class/files path/to/jar/location
```
The `-c` options specifies that the `jar` file is being created, `-f` specifies the name of the file, `-e` specifies 
the entry point of the program and `-C` specifies the location of the class files being packaged.

e.g. if the command is being run from the project root directory where the entry point is located in 
`./bin/main/HelloWorld.class`, and the `jar` is to be created in the project root directory, run:
```
jar -c -f JarName.jar -e main.MainClass -C ./bin .
```
> Note: if a `MANIFEST.MF` file is created and has the main class specified, the `-e` option should be replaced 
> with the `-m path/to/META-INF/MANIFEST.MF`. To specify the main class in the `MANIFEST.MF` file, add the 
> following (the blank line is important):
> ```
> Main-Class: main.MainClass
>
> ```
### Running
---
To run a compiled java program using the `java` command, run:
```
java -cp path/to/bin MainClass
```
The `-cp` option specifies the classpath.

e.g. if the command is being run from the project root directory where the entry point is located in 
`./bin/main/HelloWorld.class`, run:
```
java -cp ./bin main.HelloWorld
```
To run a `jar` file using the `java` command, run:
```
java -jar path/to/JarFile.jar
```
e.g. if the file `JarFile.jar` is located in the project root directory, run:
```
java -jar ./JarFile.jar
```

## Javadoc
### Writing
---
```java
/**
 * This is a javadoc comment.
 * Javadoc comments are used to generate a html page that
 * contains documentation about your program.
 * 
 * Tags such as {@link} (for linking to another class) and 
 * @param (for providing documentation about method parameters)
 * are supported.
 * /
```
### Generating
---
To generate the javadoc html from the javadoc comments in the source code, the `javadoc` command can be used, run:
```
javadoc -d path/to/output/dir path/to/src/**/*.java
```
e.g. if the command is being run from the project root directory, and the output files are to be placed in directory 
in  called doc, run:
```
javadoc -d ./doc ./src/**/*.java
```

## Useful Links
- #### Java Documentation:
    - JDK 11 documentation: <https://docs.oracle.com/en/java/javase/11/>
    - Java 11 API documentation: <https://docs.oracle.com/en/java/javase/11/docs/api/index.html>
- #### Execution Documentation:
    - `javac` command (for JDK 11): <https://docs.oracle.com/en/java/javase/11/tools/javac.html#GUID-AEEC9F07-CB49-4E96-8BC7-BCC2C7F725C9>
    - `jar` command (for JDK 11): <https://docs.oracle.com/en/java/javase/11/tools/jar.html#GUID-51C11B76-D9F6-4BC2-A805-3C847E857867>
    - `java` command (for JDK 11): <https://docs.oracle.com/en/java/javase/11/tools/java.html#GUID-3B1CE181-CD30-4178-9602-230B800D4FAE>
- #### Javadoc Documentation:
    - `javadoc` command (for JDK 11): <https://docs.oracle.com/en/java/javase/11/tools/javadoc.html>
    - Writing comments: <https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html>
- #### General Information:
    - <https://docs.oracle.com/javase/tutorial/>
    - <https://www.tutorialspoint.com/java/index.htm>
    - <https://www.w3schools.com/java/default.asp>
    - <https://www.programiz.com/java-programming>
    - <https://www.javatpoint.com/java-tutorial>
    - <https://www.baeldung.com/start-here>
    - <https://www.baeldung.com/category/java/>
    - <https://www.oracle.com/java/technologies/javase/codeconventions-introduction.html>