#[derive(Debug)]
enum List {
    Cons(i32, Box<List>), // Box is needed here to create indirection and avoid infinite recursion
    Nil,
}

fn main() {
    let list: List = List::Cons(
        1,
        Box::new(List::Cons(2, Box::new(List::Cons(3, Box::new(List::Nil))))),
    );

    println!("{:?}", list);

    // the boxed_i32 is a smart pointer to an owned value 5
    let boxed_i32: Box<i32> = Box::new(5);

    // Box<T> implemented the Deref trait allowing it to be treated like a regular reference
    println!("boxed_i32 = {}", boxed_i32);

    // the pointer is deallocated at the end of the scope of main
    // the deallocation happens for both the box and the value it points to
}
