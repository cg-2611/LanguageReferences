# Rust

## Contents
- [Language Basics](#language-basics)
    - [Entry Point](#entry-point)
    - [Comments](#comments)
    - [Variables and Constants](#variables-and-constants)
        - [Variables](#variables)
        - [Constants](#constants)
    - [Arrays](#arrays)
    - [Tuples](#tuples)
    - [Primitive Data Types](#primitive-data-types)
    - [Operators](#operators)
    - [Control Flow Statements](#control-flow-statements)
        - [Decision Making](#decision-making)
        - [Loop Control](#loop-control)
    - [Functions](#functions)
- [Executing Programs](#executing-programs)
    - [Compiling](#compiling)
    - [Running](#running)
- [Useful Links](#useful-links)
    - [Rust Documentation](#rust-documentation)
    - [Execution Documentation](#execution-documentation)
    - [General Information](#general-information)

## Language Basics
### Entry Point
---
```rust
fn main() {
    // do something
}
```
### Comments
---
```rust
// single line comment
```
### Variables and Constants
---
#### Variables:
```rust
let identifier: type = value;     // definition of immutable variable
let mut identifier: type;         // declaration of mutable variable
let mut identifier: type = value; // definition of mutable variable
```
#### Constants:
```rust
const identifier: type = value;
```
### Arrays
---
```rust
// declare array of size n
let identifier: [type; n];

// initialize array of 3 elements with values
let identifier: [type: 3] =  [element 1, element 2, element 3];

// initialize an array of n elements of value m with type type
let identifier: [type; n] = [m; n]
```
### Tuples
---
```rust
// declare a tuple of 3 elements with respective types
let identifier: (type1, type2, type3);

// initialize a tuple of 3 elements with values
let identifier: (type1, type2, type3) =  (element 1, element 2, element 3);
```
### Primitive Data Types
---
```rust
i8    // 8-bit signed integer
u8    // 8-bit unsigned integer
i16   // 16-bit signed integer
u16   // 16-bit unsigned integer
i32   // 32-bit signed integer
u32   // 32-bit unsigned integer
i64   // 64-bit signed integer
u64   // 64-bit unsigned integer
i128  // 128-bit signed integer
u128  // 128-bit unsigned integer
isize // signed integer of system architecture size
usize // unsigned integer of system architecture size
f32   // 32-bit floating point number
f64   // 64-bit floating point number (double precision)
char  // character type (4 bytes)
bool  // boolean type (1 byte)
```
### Operators
---
### Control Flow Statements:
---
#### Decision Making:
```rust
// if statement
if condition {
    // do something
} else if another condition {
    // do something else
} else {
    // do something if no conditions met
}
```
#### Loop Control:
```rust
// for loop
for element in collection {
    // do something
}

// while loop
while condition {
    // do something
}

// loop (name is optional and can be used to break or continue in nested loops)
'name: loop {
    // do something
}
```
### Functions
---
```rust
// function definition
fn function_name(parameter1: type, parameter2: type) -> type {
    //do something
}
```

## Executing Programs
### Compiling
---
To compile a Rust program using the `rustc` command, run:
```
rustc file.rs
```
this will create an executable file `file` in the current directory.
### Running
---
To run a compiled Rust program in the terminal, run:
```
path/to/compiled_file_name
```

## Useful Links
- #### Rust Documentation:
    - Rust Standard Library: <https://doc.rust-lang.org/std/index.html>
    - Rust Book: <https://doc.rust-lang.org/book/>
    - Rust by Example: <https://doc.rust-lang.org/stable/rust-by-example/>
    - The Rustonomicon: <https://doc.rust-lang.org/nomicon/intro.html>
- #### Execution Documentation:
    - `rustc` Book: <https://doc.rust-lang.org/rustc/index.html>
- #### General Information:
    - Rust Book Github: <https://github.com/rust-lang/book/tree/main/src>
