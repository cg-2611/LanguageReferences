use std::rc::Rc;

#[derive(Debug)]
enum List {
    Cons(i32, Rc<List>),
    Nil,
}

fn main() {
    // Rc deals with immutable references only
    let a: Rc<List> = Rc::new(List::Cons(5, Rc::new(List::Cons(10, Rc::new(List::Nil)))));
    println!("references after creating a = {}", Rc::strong_count(&a));
    println!("a = {:?}", a);

    // could use a.clone() but using Rc::clone(&a) is more conventional as Rc::clone() does not make a
    // deep copy, where as .clone() generally does
    let b: List = List::Cons(3, Rc::clone(&a));
    println!("b = {:?}", b);

    // the list pointed to by a will have 2 references here, a and b
    println!("references after creating b = {}", Rc::strong_count(&a));

    {
        let c: List = List::Cons(4, Rc::clone(&a));
        println!("c = {:?}", c);

        // the list pointed to by a will have 3 references here, a, b, and c
        println!("references after creating c = {}", Rc::strong_count(&a));
    } // here c goes out of scope and so its reference to the listed pointed to by a will be dropped

    println!(
        "references after c goes out of scope = {}",
        Rc::strong_count(&a)
    );

    // using a strong reference will share the ownership of whatever is being pointed to,
    // however if used incorrectly, can lead to reference cycles and memory leaks

    // to overcome this, we can use Weak<T> smart pointers which do not express ownership, and their
    // count does not affect when an Rc<T> is cleaned up

    // to get a Weak<T> we can use Rc::downgrade()

    // because the Weak<T> smart pointer does not express ownership, it could potentially become a
    // dangling pointer, and so we must make sure the value still exists when doing anything with it,

    // we can do this by using Weak::upgrade() which returns an Option<Rc<T>> which will either have Some(Rc<T>)
    // which can be used or None indicating an invalid pointer that cannot be used
}
