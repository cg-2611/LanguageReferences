Java
====
Contents
--------
- [Language Basics](#language-basics)
    - [Comments](#comments)
    - [Operators](#operators)
        - [Arithmetic Operators](#arithmetic-operators)
        - [Comaprison Operators](#comparison-operators)
        - [Logical Operators](#logical-operators)
        - [Bitwise Operators](#bitwise-operators)
        - [Assignment Operators](#assignment-operators)
        - [Miscellaneous Operators](#miscellaneous-operators)
    - [Control Flow Statements](#control-flow-statements)
        - [Decision Making](#decision-making)
        - [Loop Control](#loop-control)
    - [Primitive Data Types](#primitive-data-types)
    - [Casting Primitive Types](#casting-primitive-types)
- [Executing Programs](#executing-programs)
    - [Compiling](#compiling)
    - [Running](#running)
- [Useful Links](#useful-links)
    - [Execution Links](#execution-links)
    - [General Information Links](#general-information-links)

Language Basics
--------------
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
### Operators
---
#### Arithmetic Operators:
```java
x + y // addition
x - y // subtraction
x * y // multiplication
x / y // division
x % y // modulus
x++   // increment
x--   // decrement
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
!x     // logical NOT
```
#### Bitwise Operators:
```java
&   // binary AND
|   // binary OR
^   // binary XOR
~   // binary one's complement
<<  // binary left shift
>>  // binary right shift
>>> // binary shift right zerro fill 
```
#### Assignment Operators:
```java
=   // simple assignment
+=  // add and assign
-=  // subtract and assign
*=  // multiply and assing
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
instanceof // returns if an onject is an instance of a given class
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
#### Loop Control
```java
// for loop
for (initialisation; condition; update) {
    // do something
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
### Primitive Data Types
---
```java
byte    // 8 bits,  1 byte 
short   // 16 bits, 2 bytes
int     // 32 bits, 4 bytes
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

Executing Programs
----------
### Compiling
---
To compile a java program using the `javac` command, run:
```
javac -cp path/to/src -d path/to/bin path/to/src/**/*.java
```

e.g. if the command is being run from the project root directory, run:
```
javac -cp ./src -d ./bin ./src/**/*.java
```
> Note: using `src/**/*.java` will maintain the package structure in the output directory specified by the `-d` option. 

### Running
---
To run a compiled java program using the `java` command, run:
```
java -cp path/to/bin mainpackage.MainClass
```
e.g. if the command is being run from the project root directory where the entry point is located in `./bin/mainpackage/HelloWorld.class`, run:
```
java -cp ./bin mainpackage.HelloWorld
```

Useful Links
------------
- #### Execution Links:
    - `javac` command documentation (for java version 11):
<https://docs.oracle.com/en/java/javase/11/tools/javac.html#GUID-AEEC9F07-CB49-4E96-8BC7-BCC2C7F725C9>
    - `java` command documentation (for java verion 11):
<https://docs.oracle.com/en/java/javase/11/tools/java.html#GUID-3B1CE181-CD30-4178-9602-230B800D4FAE>

- #### General Information Links:
    - <https://docs.oracle.com/javase/tutorial/>
    - <https://www.tutorialspoint.com/java/index.htm>
    - <https://www.w3schools.com/java/default.asp>
    - <https://www.oracle.com/java/technologies/javase/codeconventions-introduction.html>

TODO
----
- [x] Strings
- [ ] User Input
- [ ] Files
- [ ] Command Line Arguments
- [ ] Arrays
- [ ] Casting
- [ ] Objects
- [ ] Utils
- [ ] Data Structures
- [ ] Exceptions
- [ ] Enums
- [ ] Interfaces
- [ ] Abstract Classes
- [ ] System Properties
- [ ] Threads
- [ ] GUI
- [ ] Unit Testing
- [ ] Maven
- [ ] Gradle
- [ ] Date and Time
- [ ] Networking
- [ ] Javadoc

- [ ] Overloading and Polymorphism
- [ ] Generics
- [ ] Serialisation
- [ ] Lambda Expressions