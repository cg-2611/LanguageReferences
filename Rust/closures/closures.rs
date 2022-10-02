// the following functions are all equivalent and demonstrate how the types of closures are inferred
// fn  add_one   (x: u32) -> u32 { x + 1 }  >> function
// let add_one = |x: u32| -> u32 { x + 1 }; >> explicitly typed closure with explicit body
// let add_one = |x|             { x + 1 }; >> type inferred closure with explicit body
// let add_one = |x|               x + 1  ; >> type inferred closure with implicit body

// the following example results in a compiler error because the type of the closure is inferred as String
// and so when called on an int, there is a type mismatch
// let example_closure = |x| x;

// let s = example_closure(String::from("hello"));
// let n = example_closure(5);

// print prints the value of an Option<i32> if it is Some or the closure captures the dummy parameter and
// prints it if the Option<i32> is None
fn print(option: Option<i32>, dummy: i32) {
    // trait bound specified on the type of the closure is FnOnce() -> T, which means the closure must be able to be
    // called once, take no arguments, and return a T
    // using FnOnce in the trait bound expresses the constraint that unwrap_or_else
    // is only going to call the closure at most one time
    let value: i32 = option.unwrap_or_else(|| dummy);
    println!("option {:?} has value: {}", option, value);
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let some_i32: Option<i32> = Some(4);
    let none_i32: Option<i32> = None;

    print(some_i32, -1);
    print(none_i32, -1);

    // this example shows a closure that captures an immutable reference to a vector because it only needs an
    // immutable reference to print the value
    // also a variable can bind to a closure definition, and we can later call the
    // closure by using the variable name
    // because we can have multiple immutable references to list at the same time, the list is still accessible from
    // the code before the closure definition, after the closure definition but before the closure is called, and after
    // the closure is called
    let list: Vec<i32> = vec![1, 2, 3];
    println!("before defining closure: {:?}", list);

    let only_borrows = || println!("inside closure: {:?}", list);

    println!("before calling closure: {:?}", list);
    only_borrows();
    println!("after calling closure: {:?}", list);

    // this example shows a closure that captures a mutable reference to a vector
    // the closure is not used after it is called, so the mutable borrow ends
    // between the closure definition and the closure call, an immutable borrow to print isn’t allowed because the
    // list is already borrowed mutably, and no other borrows are allowed when a mutable borrow has occurred
    let mut list: Vec<i32> = vec![1, 2, 3];
    println!("before defining closure: {:?}", list);

    let mut borrows_mutably = || list.push(4);

    borrows_mutably();
    println!("after calling closure: {:?}", list);

    // to make the closure take ownership of the values it uses in the environment, then the
    // move keyword can be used: move || {};

    // sorting a list of rectangles by width
    let mut list: [Rectangle; 3] = [
        Rectangle {
            width: 10,
            height: 1,
        },
        Rectangle {
            width: 3,
            height: 5,
        },
        Rectangle {
            width: 7,
            height: 12,
        },
    ];

    // immutable borrow of the argument rectangle
    // sort_by_key is defined to take an FnMut closure is that it calls the closure multiple times: once for each
    // item in the list
    // the closure |r| r.width doesn’t capture, mutate, or move out anything from its environment,
    // so it meets the trait bound requirements
    list.sort_by_key(|r: &Rectangle| r.width);
    println!("{:#?}", list);

    let mut list: [Rectangle; 3] = [
        Rectangle {
            width: 10,
            height: 1,
        },
        Rectangle {
            width: 3,
            height: 5,
        },
        Rectangle {
            width: 7,
            height: 12,
        },
    ];

    // counting the number of operations this way works because the closure does not move any values
    // out of the environment, only a mutable reference to count is taken
    let mut count: i32 = 0;
    list.sort_by_key(|r: &Rectangle| {
        count += 1;
        r.width
    });
    println!("{:#?}, sorted in {} operations", list, count);
}

// to return a closure from a function, we must use a Box as Rust cannot determine the size of the closure
// fn returns_closure() -> Box<dyn Fn(i32) -> i32> {
//     Box::new(|x| x + 1)
// }
