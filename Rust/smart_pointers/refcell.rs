use std::cell::RefCell;
use std::rc::Rc;

// interior mutability is a design pattern in Rust that allows data to be mutated even when there are
// immutable references to it, RefCell<T> allows this

// RefCell<T> represents single ownership of the data it holds, however, unlike Box<T>, the invariants
// of the borrowing rules are enforced at runtime, rather than compile time, and if any rules
// are broken, the the program panics

// doing the enforcement at runtime allows certain memory-safe scenarios to be allowed that would not be
// allowed during static analysis

// a common way to use RefCell<T> is with Rc<T>

// if we wanted shared ownership of the List, then using an Rc<List> would not allow any mutations
// of the list, however, by using a RefCell as the data in the list, we can maintain the shared ownership, but also
// have the ability to mutate the values in the list

#[derive(Debug)]
enum List {
    Cons(Rc<RefCell<i32>>, Rc<List>),
    Nil,
}

fn main() {
    let value: Rc<RefCell<i32>> = Rc::new(RefCell::new(5));

    let a: Rc<List> = Rc::new(List::Cons(Rc::clone(&value), Rc::new(List::Nil)));

    let b: List = List::Cons(Rc::new(RefCell::new(3)), Rc::clone(&a));
    let c: List = List::Cons(Rc::new(RefCell::new(4)), Rc::clone(&a));

    // after creating the lists in a, b, and c, we mutate the value;
    // the borrow_mut method uses the automatic dereferencing to dereference the Rc<T> to the
    // inner RefCell<T> value
    // the borrow_mut method returns a RefMut<T> smart pointer, and we use the dereference it and change the value
    *value.borrow_mut() += 10;

    println!("a after = {:?}", a);
    println!("b after = {:?}", b);
    println!("c after = {:?}", c);
}
