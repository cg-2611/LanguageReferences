use std::fmt::Display;

trait Printable {
    // default print method, can be overridden in implementations
    fn print(&self) {
        println!("{}", self.to_string());
    }

    fn to_string(&self) -> String;
}

struct Point {
    x: i32,
    y: i32,
}

impl Point {
    fn new(x: i32, y: i32) -> Self {
        Self { x, y }
    }
}

impl Printable for Point {
    fn to_string(&self) -> String {
        String::from(format!("({}, {})", self.x, self.y))
    }
}

// pass something that is Printable to a function
fn print(printable: &impl Printable) {
    printable.print();
}

// the previous function is syntactic sugar for te following:
// fn print<T: Printable>(printable: &T) {
//     printable.print();
// }

// the following function can also be used:
// fn print<T>(printable: &T)
// where
//     T: Printable,
// {
//     printable.print();
// }

// we can also use the impl keyword to define return types for functions that implement traits:
// fn return_printable(...) -> impl Printable { ... }

struct Pair<T> {
    fst: T,
    snd: T,
}

impl<T> Pair<T> {
    fn new(fst: T, snd: T) -> Self {
        Self { fst, snd }
    }
}

// restrict T to be a type that implements the Display and PartialOrd traits
impl<T: Display + PartialOrd> Pair<T> {
    fn print_largest(&self) {
        print!("largest is: ");
        if self.fst >= self.snd {
            println!("fst = {}", self.fst);
        } else {
            println!("snd = {}", self.snd);
        }
    }
}

fn main() {
    let point: Point = Point::new(3, 7);

    point.print();
    print(&point);

    let pair: Pair<f64> = Pair::new(1.1, 6.7);
    pair.print_largest();
}
