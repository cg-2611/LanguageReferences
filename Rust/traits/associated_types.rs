// associated types connect a type placeholder with a trait such that the trait method definitions can use
// these placeholder types in their signatures
// the implementer of a trait will specify the concrete type to be used instead of the placeholder type for
// the particular implementation
// associated types also become part of the trait’s contract: implementers of the trait must provide a type to stand
// in for the associated type placeholder
// associated types often have a name that describes how the type will be used, and documenting the associated type
// in the API documentation is good practice

// here Item is an associated type
pub trait Iterator {
    type Item;

    fn next(&mut self) -> Option<Self::Item>;
}

// if we were to use generics, we would have to annotate the types in each implementation
// with associated types, we do not need to annotate types because we cannot implement a trait on a type multiple times
// pub trait Iterator<T> {
//     fn next(&mut self) -> Option<T>;
// }

struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    // a default type can be specified too, e.g. type Item = u32
    // this states that the default type of Item is a u32
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        // --snip--
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

fn main() {}
