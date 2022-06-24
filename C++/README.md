# C++

## Contents
- [Language Basics](#language-basics)
    - [Entry Point](#entry-point)
    - [Comments](#comments)
    - [Variables and Constants](#variables-and-constants)
        - [Variables](#variables)
        - [Constants](#constants)
    - [Arrays](#arrays)
    - [Primitive Data Types](#primitive-data-types)
      - [Types](#types)
      - [Macro Constants](#macro-constants)
    - [Casting](#casting)
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
    - [Functions](#functions)
    - [Preprocessor Directives](#preprocessor-directives)
- [Classes and Objects](#classes-and-objects)
    - [Access Modifiers](#access-modifiers)
    - [Classes](#classes)
        - [Declaring Classes](#declaring-classes)
        - [Constructor](#constructor)
        - [Destructor](#destructor)
        - [Instance Fields](#instance-fields)
        - [Instance Methods](#instance-methods)
        - [Referencing Current Object](#referencing-current-object)
        - [Class Fields](#class-fields)
        - [Class Methods](#class-methods)
        - [Nested Classes](#nested-classes)
    - [Objects](#objects)
        - [Object Creation](#object-creation)
        - [Accessing Members](#accessing-members)
    - [Abstract Classes](#abstract-classes)
        - [Declaring Abstract Classes](#declaring-abstract-classes)
        - [Using Abstract Classes](#using-abstract-classes)
- [Error Handling](#error-handling)
    - [Throwing Exceptions](#throwing-exceptions)
    - [Handling Exceptions](#handling-exceptions)
- [Executing Programs](#executing-programs)
    - [Compiling](#compiling)
    - [Running](#running)
- [Useful Links](#useful-links)
    - [C++ Documentation](#c++-documentation)
    - [Execution Documentation](#execution-documentation)
    - [General Information](#general-information)

> There is a significant amount of similarity between C and C++, and so because of this refer to C for the following topics:
> - Pointers
> - Preprocessors
> - Header Files
> - Bit Manipulation
> - Structures
> - Unions
> - Memory Padding
> - Function Pointers and Passing by Reference
> - Static Variables
> - External variables
> - Static Functions

## Language Basics
### Entry Point
```c++
int main(int argc, char const *argv[])
{
    // do something

    return 0;
}
```
### Comments
---
```c++
// single line comment

/*
 * multi-line comment
 */
```
### Variables and Constants
---
#### Variables:
```c++
type identifier; // declaration (memory allocated), default initialization rules apply

// initialization (memory allocated and value stored)
type identifier{value}; // value initialization, does not allow narrowing/coercion, does zero-initialization if no value is provided
type identifier(value); // direct initialization, does allow narrowing/coercion, does not do zero-initialization if no value is provided
type identifier = value; // copy initialization, does allow narrowing/coercion, does not do zero-initialization if no value is provided
```
#### Constants:
```c++
const type identifier = value;
```
### Arrays
---
```c++
// declare array of size n (memory allocated)
type identifier[n];

// initialize array of 3 elements (memory allocated and values stored)
type identifier{element 1, element 2, element 3}; // list initialization
type identifier[3] =  {element 1, element 2, element 3}; // aggregate initialization
type &identifier = array[0] // reference initialization
```
### Primitive Data Types
---
#### Types
```c++
bool                   // 8 bits, 1 byte
char                   // 8 bits, 1 byte, %c
signed char            // 8 bits, 1 byte, %c or %hhi
unsigned char          // 8 bits, 1 byte, %c or %hhu
int                    // 32 bits, 4 bytes, %d or %i
unsigned int           // 32 bits, 4 bytes, %u
short int              // 16 bits, 2 bytes, %hd or %hi
unsigned short int     // 16 bits, 2 bytes, %hu
long int               // 64 bits, 8 bytes, %ld or %li
unsigned long int      // 64 bits, 8 bytes, %lu
long long int          // 64 bits, 8 bytes, %lld or %lli
unsigned long long int // 64 bits, 8 bytes, %llu
float                  // 32 bits, 4 bytes, %f
double                 // 64 bits, 8 bytes, %lf
long double            // 128 bits, 16 bytes, %Lf
```
#### Macro Constants
```c++
// char
CHAR_BIT    // number of bits in a char
MB_LEN_MAX  // maximum number of bytes in a multi-byte character
CHAR_MIN    // minimum value for char
CHAR_MAX    // maximum value for char
SCHAR_MIN   // minimum value for signed char
SCHAR_MAX   //  maximum value for signed char
UCHAR_MAX   // maximum value for unsigned char

// int
SHRT_MIN    // minimum value for short int
SHRT_MAX    // maximum value for short int
USHRT_MAX   // maximum value for unsigned short int
INT_MIN     // minimum value for int
INT_MAX     // maximum value for int
UINT_MAX    // maximum value for unsigned int
LONG_MIN    // minimum value for long int
LONG_MAX    // maximum value for long int
LLONG_MIN   // minimum value for long long int
LLONG_MAX   // maximum value for long long int
ULONG_MAX   // maximum value for unsigned long int
ULLONG_MAX  // maximum value for unsigned long long int
```
### Casting
---
```c++
(type) expression; // casts the expression to type 'type'
```
### Operators
---
#### Unary Operators:
```c++
+x  // positive value
-x  // negative value
x++ // postfix increment
++x // prefix increment
x-- // postfix decrement
--x // prefix decrement
```
#### Arithmetic Operators:
```c++
x + y // addition
x - y // subtraction
x * y // multiplication
x / y // division
x % y // modulus
```
#### Comparison Operators:
```c++
x == y // equal
x != y // not equal
x > y  // greater than
x < y  // less than
x >= y // greater than or equal to
x <= y // less than or equal to
```
#### Logical Operators:
```c++
x && y // logical AND
x || y // logical OR
!x     // logical NOT
```
#### Bitwise Operators:
```c++
&  // binary AND
|  // binary OR
^  // binary XOR
~  // binary complement
<< // binary left shift
>> // binary right shift
```
#### Assignment Operators:
```c++
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
```c++
sizeof(x) // returns the size of variable x
&x        // returns the address of x
*x        // pointer to x
?:        // conditional operator
x.y       // access member y of class x
x->y      // access member y of class x when y is pointer
<< x      // print value x (used with std::cout)
>> x      // read value x (used with std:cin)
```
### Control Flow Statements:
---
#### Decision Making:
```c++
// if statement
if (condition)
{
    // do something
}
else if (another condition)
{
    // do something else
}
else
{
    // do something if no conditions met
}

// conditional operator
(condition) ? (valueIfTrue) : (valueIfFalse);

// switch statement (breaks optional)
switch (expression)
{
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
```c++
// for loop
for (initialization; condition; update)
{
    // do something
}

// for iterator loop
for (type object : iterator)
{
    // do something
}

// while loop
while (condition)
{
    // do something
}

// do-while loop
do
{
    // do something
}
while (condition);
```
### Functions
---
```c++
// function declaration
type function_name(type parameter1, type parameter2);

// function definition
type function_name(type parameter1, type parameter2)
{
    // do something
}
```
### Preprocessor Directives
---
```c
#include // inserts a header from another file
#define  // defines a preprocessor macro
#undef   // undefines a previously defined preprocessor macro
#ifdef   // returns true if the macro is defined
#ifndef  // returns true is the macro is not defined
#if      // returns true if condition is true
#else    // executes when #if not true
#elif    // combination of #else and #if
#endif   // indicates end of conditional statement
#error   // prints error message on stderr
#pragma  // issues standardized commands to the compiler
```

## Classes and Objects
### Access Modifiers
---
```c++
public      // available to all other classes and functions
protected   // available to class only or any subclasses
private     // available to class only, or friend classes and functions (default if not specified)
```
### Classes
---
#### Declaring Classes:
```c++
class ClassName: public SuperClass
{
    private:
        // private class members

    public:
        // public class members
        // methods can be defined inside the class, or declared inside the class and defined outside
}
```
#### Constructor:
```c++
class ClassName
{
    public:
        ClassName(type parameter1, type parameter2)
        {
            // do something
        }
}
```
#### Destructor:
```c++
class ClassName
{
    public:
        ~ClassName()
        {
            // do something
        }
}
```
#### Instance Fields:
```c++
modifier:
    type identifier;         // has undefined value
    type identifier = value; // has value of 'value'
```
#### Instance Methods:
```c++
modifier:
    type methodName(type parameter1, type parameter2)
    {
        // method body
    }
```
#### Referencing Current Object:
```c++
this->field          // accesses field 'field' of current object (-> needed as 'this' is a pointer)
this->doSomething()  // calls method 'doSomething' of current object (-> needed as 'this' is a pointer)
```
#### Class Fields:
```c++
modifier:
    static type identifier;         // has undefined value
    static type identifier = value; // has value of 'value'
```
#### Class Methods:
```c++
modifier:
    static type methodName(type parameter1, type parameter2)
    {
        // method body
    }
```
#### Nested Classes:
```c++
class OuterClass
{
    // outer class body

    modifier:
        class InnerClass
        {
            // inner class body
        }
}
```
### Objects
---
#### Object Creation:
```c++
// stack allocation
ClassName identifier = ClassName(argument1, argument2);

// heap dynamic allocation
ClassName *identifier = new ClassName(argument1, argument2);
delete identifier; // required after use to deallocate memory
```
#### Accessing Members:
```c++
object.field         // access field 'field' of object 'object'
object.doSomething() // calls method 'doSomething' of object 'object'

// when object is a pointer
object->field           // access field 'field' of object 'object'
object->doSomething() // calls method 'doSomething' of object 'object'
```
### Abstract Classes:
---
#### Declaring Abstract Classes:
```c++
class AbstractClassName
{
    public:
        AbstractClassName(type parameter1)
        {
            // do something
        }

        // methodOne is abstract as it is a pure virtual method, i.e., it is virtual ... = 0
        virtual type methodOne(type parameter1) = 0;

        virtual type methodTwo()
        {
            // do something
        }

    // class body
}
```
#### Using Abstract Classes:
```c++
class ClassName: public AbstractClassName
{
    public:
        // calls constructor of AbstractClassName
        ClassName(type parameter1, type parameter2) : AbstractClassName(parameter1)
        {
            //constructor body
        }

    modifier:
        type methodOne(type parameter1) override
        {
            // method body
        }

        type methodTwo() override
        {
            // new method body
        }
}
```

## Error Handling
### Throwing Exceptions:
---
```c++
throw "exception message" // throws an exception
```
### Handling Exceptions:
---
```c++
try
{
    // do something
}
catch (ExceptionName e)
{
    // catch exception ExceptionName and deal with it
}

try
{
    // do something
}
catch (...)
{
    // catch all exceptions and deal with them
}
```

## Executing Programs
### Compiling
---
To compile a C++ program using the `clang++` command, run:
```
clang++ file.cpp
```
this will create an executable file `a.out` in the current directory.

To specify an output file name and/or location for the executable, use the `-o` option nad run:
```
clang++ -o output/path/file_name file.cpp
```
e.g. to compile a `hello_world.cpp` source file into a `bin` directory with a name different to `a.out`, run:
```
clang++ -o ./bin/hello_world hello_world.cpp
```
> Note: A path is not required however a file name is. If a path is used, `clang++` will not create given directories,
> they must already exist.

Other options can be passed to the `clang++` command other than just `-o`. for example, using `-Wall` will display all
warnings generated by the program being compiled. An example usage:
```
clang++ -Wall -o file file.cpp
```
To make the compiled C++ program suitable for debugging, use the `-g` option:
```
clang++ -g file.cpp
```
> Note: `-o` was not specified in this example and so the output file will be called `a.out`.

To compile a C++ program into an object file, use the `-c` option:
```
clang++ -c file.cpp
```
> Note: this will produce a file called `file.o`.

To compile a C++ program into assembly, use the `-S` option:
```
clang++ -S file.cpp
```
> Note: this will produce a file called `file.s`.
### Running
---
To run a compiled C++ program in the terminal, run:
```
path/to/compiled_file_name
```
e.g. if no `-o` option was used when compiling the program, run:
```
./a.out
```
If the `-o` option was used, e.g. the compiled file is called `hello_world` and the file was compiled into the current
directory, run:
```
./hello_world
```
If a path was also provided during compilation e.g. the option `-o ./bin/hello_world` was used, then either navigate
to the directory containing the executable:
```
cd ./bin
./hello_world
```
or include the path in the executed command:
```
./bin/hello_wold
```

## Useful Links
- #### C++ Documentation:
    - C++ Standard (draft): <https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3797.pdf>
    - Microsoft C++ Documentation: <https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-170>
    - Devdocs (not official): <https://devdocs.io/cpp/>
    - cppreference (not official): <https://en.cppreference.com/w/cpp>
    - cplusplus (not official): <https://cplusplus.com/>
- #### Execution Documentation:
    - `clang` command documentation: <https://clang.llvm.org/docs/index.html>
    - extra `clang` tools documentation: <https://clang.llvm.org/extra/index.html>
- #### General Information:
    - <https://isocpp.org/>
    - <https://www.tutorialspoint.com/cplusplus/index.htm>
    - <https://www.learn-cpp.org/>
    - <https://www.programiz.com/cpp-programming>
    - <https://www.cprogramming.com/tutorial/c++-tutorial.html?inl=nv>
    - <https://www.w3schools.com/CPP/default.asp>

