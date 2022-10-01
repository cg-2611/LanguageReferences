// patterns consists of some combination of:
//  - Literals
//  - Destructured arrays, enums, structs, or tuples
//  - Variables
//  - Wildcards
//  - Placeholders

// using a pattern involves comparing it to some value; if the pattern matches the value, we use the value in our code

// _  is the wildcard pattern and will match anything but never binds to a value
// .. can be used to ignore the remaining parts of a value, that is it  ignores any parts of a value that we haven’t
//    explicitly matched in the rest of the pattern
//    using .. must be unambiguous

// the @ operator lets us create a variable that holds a value at the same time as we’re testing that value for
// a pattern match

// there are 2 forms of patterns:
//  - refutable: e.g. Some(x) in the expression if let Some(x) = v because if the value in the v variable is None
//               rather than Some, the Some(x) pattern will not match
//
//  - irrefutable: e.g. let x = 5; x is an irrefutable pattern because it matches anything and cannot fail to match

// function parameters, let statements, and for loops can only accept irrefutable patterns, because the program
// cannot do anything meaningful when values don’t match

// if let and while let expressions accept refutable and irrefutable patterns, but the compiler warns against
// irrefutable patterns because by definition they’re intended to handle possible failure

// match expression arms must all be refutable patterns apart from the last arm, which must be an irrefutable pattern
// so that it is exhaustive

// in match expressions we can use:
//  - | as an or operator e.g.: a | b | c => // do something
//  - ..= to match aan inclusive range of values e.g.: - 1..=5 => // do something for values 1, 2, 3, 4, or 5
//                                                     - 'a'..='d' => // do something for values 'a', 'b', 'c', or 'd'

// patterns can be used to destructure enums, tuples and structs as well as nested ones too

fn main() {
    // match expression (compiler checks exhaustiveness)
    let x: Option<i32> = Some(4);
    let y: Option<i32> = match x {
        None => None,
        Some(i) => Some(i + 1),
    };

    println!("x = {:?}, y = {:?}", x, y);

    // if let expression (compiler does not check exhaustiveness)
    let optional_string: Option<&str> = None;
    let boolean_value = false;
    let result_i32: Result<i32, _> = "34".parse();

    if let Some(string) = optional_string {
        println!("the value of optional_string is: {}", string);
    } else if boolean_value {
        println!("optional_string has no value boolean_value is true");
    } else if let Ok(result_i32) = result_i32 {
        if result_i32 > 30 {
            println!("optional_string has no value and result_i32 has value > 30");
        } else {
            println!("optional_string has no value and result_i32 has value <= 30");
        }
    } else {
        println!("optional_string and result_i32 have no value and boolean_value is false");
    }

    // while let loop
    let mut stack: Vec<i32> = Vec::new();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    // if the vector is empty pop() returns None, when this happens, the loop stops
    while let Some(top) = stack.pop() {
        println!("{}", top);
    }

    // for loop
    let v: Vec<char> = vec!['a', 'b', 'c'];

    // in a for loop, the value that directly follows the for keyword is a pattern
    for (index, value) in v.iter().enumerate() {
        println!("index {}: {}", index, value);
    }

    // let statements
    // here x is a pattern that means "bind what matches here to variable x", but because x is the whole
    // pattern, this statements effectively means "bind everything to variable x, whatever the value"
    let _x: i32 = 5;

    // here we match a tuple against a pattern
    // the patterns matches the tuple values so i is bind to a, 2 to b and 3 to c
    // if the pattern did not match the tuple then there would be a compiler error
    let (_a, _b, _c): (i32, i32, i32) = (1, 2, 3);

    // function parameters
    // here the x parameter is a pattern and matches a similar way to let statements
    fn _function(_x: i32) {
        // do something
    }

    fn function(&(x, y): &(i32, i32)) {
        println!("x = {}, y = {}", x, y);
    }

    // here &(3, 5) match the pattern &(x, y)
    let pair: (i32, i32) = (3, 5);
    function(&pair);
}
