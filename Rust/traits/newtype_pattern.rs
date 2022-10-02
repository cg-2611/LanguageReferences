use std::fmt;

// the newtype pattern involves creating a new type in a tuple struct that has one field and is a thin wrapper around
// the type we want to implement a trait for
// the wrapper type is then local to our crate, and we can implement the trait on the wrapper
// there is no runtime performance penalty for using this pattern, and the wrapper type is elided at compile time

// also, the newtype pattern is useful for including statically enforcing that values are never confused and indicating
// the units of a value

// newtype pattern is also a lightweight way to achieve encapsulation to hide implementation details

// here we want to implement Display on Vec<T>, which the orphan rule prevents us from doing directly because the
// Display trait and the Vec<T> type are defined outside our crate
// to get around this, we make a Wrapper struct that holds an instance of Vec<T>, then we can implement Display on
// Wrapper and use the Vec<T> value
struct Wrapper(Vec<String>);

impl fmt::Display for Wrapper {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "[{}]", self.0.join(", "))
    }
}

// the downside of this is that Wrapper is a new type, so it doesn’t have the methods of the value it’s holding
// and we would have to implement all the methods of Vec<T> directly on Wrapper such that the methods delegate
// to self.0, which would allow us to treat Wrapper exactly like a Vec<T>
// if we wanted the new type to have every method the inner type has, implementing the Deref trait on the Wrapper to
// return the inner type would be a solution

fn main() {
    let w: Wrapper = Wrapper(vec![String::from("hello"), String::from("world")]);
    println!("w = {}", w);
}
