// macro refers to a family of features in Rust: declarative macros with macro_rules! and three kinds
// of procedural macros:
//  - custom #[derive] macros that specify code added with the derive attribute used on structs and enums
//  - attribute-like macros that define custom attributes usable on any item
//  - function-like macros that look like function calls but operate on the tokens specified as their argument

// macros are a way of writing code that writes other code, i.e. metaprogramming

// macros can take a variable number of parameters and are expanded before the compiler interprets the
// meaning of the code, so a macro can, for example, implement a trait on a given type (a function can’t, because it
// gets called at runtime and a trait needs to be implemented at compile time)

// macros must be defined or brought into scope before use

// declarative macro
// here we define a simplified version of the vector! macro
// #[macro_export] indicates that this macro should be made available whenever the crate in which the macro is defined
// is brought into scope
// then we say that vector is the name of the macro
// then we have a pattern that if matches, emits the associated block of code
// any pattern that does not match any specified patterns will result in an error
// more complex macros can have more than one arm
#[macro_export]
macro_rules! vector {
    // $ is used to declare a variable in the macro system that will contain the Rust code matching the pattern
    // then a set of parentheses that captures values that match the pattern within the parentheses for use in the
    // replacement code
    // within $() is $x:expr, which matches any Rust expression and gives the expression the name $x
    // then, the comma following $() indicates that a literal comma separator character could optionally appear after
    // the code that matches the code in $()
    // the * specifies that the pattern matches zero or more of whatever precedes the *
    // when the macro is called like vector!(1, 2, 3);, the $x pattern matches three times with the three
    // expressions 1, 2, and 3
    ( $( $x:expr ),* ) => {
        // this body then evaluates to (when called like vector!(1, 2, 3);)
        // {
        //     let mut temp_vector = vector::new();
        //     temp_vector.push(1);
        //     temp_vector.push(2);
        //     temp_vector.push(3);
        //     temp_vector
        // }
        {
            let mut temp_vector = Vec::new();
            $(
                temp_vector.push($x);
            )*
            temp_vector
        }
    };
}

// procedural macro
// here we define a procedural macro that takes an TokenStream as input and outputs an TokenStream
// the TokenStream is provided by thr proc_macro crate and represents a sequence of tokens
// use proc_macro;
// #[some_attribute]
// fn some_name(input: TokenStream) -> TokenStream {}

// see the rust book for how to write custom derive macros, attribute-like macros, and function-like macros

fn main() {
    let vector: Vec<i32> = vector!(1, 2, 3);
    println!("{:?}", vector);
}
