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
int main(int argc, char *argv[]) {
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
type identifier[3] =  {element 1, element 2, element 3, ...};
```
### Primitive Data Types
---
```c
char               // 8 bits, 1 byte, %c
signed char        // 8 bits, 1 byte, %c or %hhi
unsigned char      // 8 bits, 1 byte, %c or %hhu
int                // 32 bits, 4 bytes, %d or %i
unsigned int       // 32 bits, 4 bytes, %u
short              // 16 bits, 2 bytes, %hd or %hi
unsigned short     // 16 bits, 2 bytes, %hu
long               // 64 bits, 8 bytes, %ld or %li
unsigned long      // 64 bits, 8 bytes, %lu
long long          // 64 bits, 8 bytes, %lld or %lli
unsigned long long // 64 bits, 8 bytes, %llu
float              // 32 bits, 4 bytes, %f
double             // 64 bits, 8 bytes, %lf
long double        // 128 bits, 16 bytes, %Lf
```
### Operators
---
### Unary Operators:
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
!x	   // logical NOT
```
#### Bitwise Operators:
```c
&   // binary AND
|   // binary OR
^   // binary XOR
~   // binary complement
<<  // binary left shift
>>  // binary right shift
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
```
### Control Flow Statements:
---
#### Decision Making:
```c
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
```c
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
### Functions
---
```c
// function declaration
type function_name(type parameter1, type parameter2);

// function definition
type function_name(type parameter1, type parameter2) {
    // do something
}
```

## Executing Programs
### Compiling
---
To compile a C program using the `gcc` command, run:
```
gcc file.c
```
this will create an executable file `a.out` in the current directory.

To specify an output file name and/or location for the executable, use the `-o` option nad run:
```
gcc -o output/path/file_name file.c
```
e.g. to compile a `hello_world.c` source file into a `bin` directory with a name different to `a.out`, run:
```
gcc -o ./bin/hello_world hello_world.c
```
> Note: A path is not required however a file name is. If a path is used, `gcc` will not create given directories, 
> they must already exist.

Other options can be passed to the `gcc` command other than just `-o`. for example, using `-Wall` will display all warnings generated by the program being compiled. An example usage:
```
gcc -Wall -o file file.c
```
To make the compiled C program suitable for debugging, use the `-g` option:
```
gcc -g file.c
```
> Note: `-o` was not specified in this example and so the output file will be called `a.out`.
To compile a C program into an object file, use the `-c` option:
```
gcc -c file.c
```
> Note: this will produce a file called `file.o`.
To compile a C program into assembly, use the `-S` option:
```
gcc -S file.c
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
    - Devdocs (not official): <https://devdocs.io/c/>
    - cppreference (not official): <https://en.cppreference.com/w/c>
- #### Execution Documentation:
    - `gcc` command documentation: <https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html>
- #### General Information:
    - <https://www.tutorialspoint.com/cprogramming/index.htm>
    - <https://www.learn-c.org/>
    - <https://www.programiz.com/c-programming>
    - <https://www.cprogramming.com/tutorial/c-tutorial.html>
    - <https://code-vault.net/>