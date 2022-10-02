fn add_one(x: i32) -> i32 {
    x + 1
}

// here we specify that the do_twice function takes a function, that takes an i32 and returns an i32, and i32 and
// returns an i32
// fn is a function pointer
// function pointers implement all three of the closure traits: Fn, FnMut, and FnOnce,  meaning you can always pass a
// function pointer as an argument for a function that expects a closure
fn do_twice(f: fn(i32) -> i32, arg: i32) -> i32 {
    f(arg) + f(arg)
}

fn main() {
    // the result evaluates to 12 because add_one is called on 5, returning 6 and this is added to the result of
    // calling add_one again on 5, which again returns 6, adding 6 and 6 give 12
    let result: i32 = do_twice(add_one, 5);

    println!("{}", result);
}
