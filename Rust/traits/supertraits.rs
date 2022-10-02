use std::fmt;

// here we specify that OutlinePrint requires the fmt::Display trait to be implemented
// we can say that fmt::Display is the supertrait of OutlinePrint
trait OutlinePrint: fmt::Display {
    fn outline_print(&self) {
        let output: String = self.to_string();
        let len: usize = output.len();
        println!("{}", "*".repeat(len + 4));
        println!("*{}*", " ".repeat(len + 2));
        println!("* {} *", output);
        println!("*{}*", " ".repeat(len + 2));
        println!("{}", "*".repeat(len + 4));
    }
}

struct Point {
    x: i32,
    y: i32,
}

// we must implement fmt::Display trait to be able to implement the OutlinePrint trait or Point
impl fmt::Display for Point {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

impl OutlinePrint for Point {}

fn main() {
    let p: Point = Point { x: 7, y: 2 };

    p.outline_print();
}
