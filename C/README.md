# C

## Contents
- [Language Basics](#language-basics)
    - [Entry Point](#entry-point)
    - [Comments](#comments)
    - [Variables and Constants](#variables-and-constants)
        - [Variables](#variables)
        - [Constants](#constants)
    - [Arrays](#arrays)
    - [Primitive Data Types](#primitive-data-types)
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
- [Executing Programs](#executing-programs)
    - [Compiling](#compiling)
    - [Running](#running)
- [Useful Links](#useful-links)
    - [C Documentation](#c-documentation)
    - [Execution Documentation](#execution-documentation)
    - [General Information](#general-information)

## Language Basics
### Entry Point
---
```c
int main(int argc, char *argv[])
{
    // do something

    return 0;
}
```
### Comments
---
```c
// single line comment

/*
 * multi-line comment
 */
```
### Variables and Constants
---
#### Variables:
```c
type identifier;         // declaration (memory allocated)
type identifier = value; // initialization (memory allocated and value stored)
```
#### Constants:
```c
const type identifier = value;
```
### Arrays
---
```c
// declare array of size n (memory allocated)
type identifier[n];

// initialize array of 3 elements (memory allocated and values stored)
type identifier[3] =  {element 1, element 2, element 3};
```
### Primitive Data Types
---
```c
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
### Casting
---
```c
(type) expression; // casts the expression to type 'type'
```
### Operators
---
#### Unary Operators:
```c
+x  // positive value
-x  // negative value
x++ // postfix increment
++x // prefix increment
x-- // postfix decrement
--x // prefix decrement
```
#### Arithmetic Operators:
```c
x + y // addition
x - y // subtraction
x * y // multiplication
x / y // division
x % y // modulus
```
#### Comparison Operators:
```c
x == y // equal
x != y // not equal
x > y  // greater than
x < y  // less than
x >= y // greater than or equal to
x <= y // less than or equal to
```
#### Logical Operators:
```c
x && y // logical AND
x || y // logical OR
!x     // logical NOT
```
#### Bitwise Operators:
```c
&  // binary AND
|  // binary OR
^  // binary XOR
~  // binary complement
<< // binary left shift
>> // binary right shift
```
#### Assignment Operators:
```c
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
```c
sizeof(x) // returns the size of variable x
&x        // returns the address of x
*x        // pointer to x
?:        // conditional operator
x.y       // access member y of struct x
x->y      // access member y of struct x when y is pointer
```
### Control Flow Statements:
---
#### Decision Making:
```c
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
```c
// for loop
for (initialization; condition; update)
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
```c
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

## Executing Programs
### Compiling
---
To compile a C program using the `clang` command, run:
```
clang file.c
```
this will create an executable file `a.out` in the current directory.

To specify an output file name and/or location for the executable, use the `-o` option nad run:
```
clang -o output/path/file_name file.c
```
e.g. to compile a `hello_world.c` source file into a `bin` directory with a name different to `a.out`, run:
```
clang -o ./bin/hello_world hello_world.c
```
> Note: A path is not required however a file name is. If a path is used, `clang` will not create given directories,
> they must already exist.

Other options can be passed to the `clang` command other than just `-o`. for example, using `-Wall` will display all
warnings generated by the program being compiled. An example usage:
```
clang -Wall -o file file.c
```
To make the compiled C program suitable for debugging, use the `-g` option:
```
clang -g file.c
```
> Note: `-o` was not specified in this example and so the output file will be called `a.out`.

To compile a C program into an object file, use the `-c` option:
```
clang -c file.c
```
> Note: this will produce a file called `file.o`.

To compile a C program into assembly, use the `-S` option:
```
clang -S file.c
```
> Note: this will produce a file called `file.s`.
### Running
---
To run a compiled C program in the terminal, run:
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
- #### C Documentation:
    - C Standard: <http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf>
    - man pages: <https://man7.org/linux/man-pages/dir_all_alphabetic.html>
    - Microsoft C Documentation: <https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-160>
    - Open Group docs: <https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/>
    - Devdocs (not official): <https://devdocs.io/c/>
    - cppreference (not official): <https://en.cppreference.com/w/c>
    - cplusplus (not official): <https://www.cplusplus.com/reference/clibrary/>
- #### Execution Documentation:
    - `clang` command documentation: <https://clang.llvm.org/docs/index.html>
    - extra `clang` tools documentation: <https://clang.llvm.org/extra/index.html>
- #### General Information:
    - <https://www.tutorialspoint.com/cprogramming/index.htm>
    - <https://www.learn-c.org/>
    - <https://www.programiz.com/c-programming>
    - <https://www.cprogramming.com/tutorial/c-tutorial.html>
    - <https://www.w3schools.com/c/index.php>
    - <https://code-vault.net/>
