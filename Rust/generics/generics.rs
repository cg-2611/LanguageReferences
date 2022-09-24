// in functions
// return the largest element of a slice of elements of type T
// restrict T to only types that have the PartialOrd trait so they can be compared
fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest: &T = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

// in structs
// a point with x and y being the same type
struct Point_<T> {
    x: T,
    y: T,
}

// a point with x and y being different or the same type
struct Point<T, U> {
    x: T,
    y: U,
}

// in methods
impl<T, U> Point<T, U> {
    fn x(&self) -> &T {
        &self.x
    }

    fn y(&self) -> &U {
        &self.y
    }
}

impl Point<i32, f64> {
    fn print(&self) {
        println!("x is i32: {}", self.x);
        println!("y is f64: {}", self.y);
    }
}

// in enums
#[derive(Debug)]
enum Enum<T> {
    Value1(T),
    Value2,
}

fn get_enum<T: std::cmp::PartialOrd>(x: T, y: T) -> Enum<T> {
    if x > y {
        Enum::Value1(x)
    } else {
        Enum::Value2
    }
}

fn main() {
    let i32_vector: Vec<i32> = vec![12, 76, 33, 96, 47];

    let largest_i32: &i32 = largest(&i32_vector);
    println!("largest i32 is: {}", largest_i32);

    let char_vector: Vec<char> = vec!['b', 'm', 'p', 'x', 'q'];

    let largest_char: &char = largest(&char_vector);
    println!("largest char is: {}", largest_char);

    let i32_point: Point_<i32> = Point_ { x: 3, y: 9 };
    let f64_point: Point_<f64> = Point_ { x: 6.5, y: 8.0 };
    // let mix: Point_<i32> = { x:7, y: 5.0 }; // error

    println!("({}, {})", i32_point.x, i32_point.y);
    println!("({}, {})", f64_point.x, f64_point.y);

    let both_i32: Point<i32, i32> = Point { x: 6, y: 13 };
    let both_f64: Point<f64, f64> = Point { x: 2.1, y: 4.8 };
    let mix: Point<i32, f64> = Point { x: 2, y: 3.6 };

    println!("({}, {})", both_i32.x, both_i32.y);
    println!("({}, {})", both_f64.x, both_f64.y);
    println!("({}, {})", mix.x, mix.y);

    println!("({}, {})", both_i32.x(), both_i32.y());
    println!("({}, {})", both_f64.x(), both_f64.y());
    println!("({}, {})", mix.x(), mix.y());

    mix.print();

    let value1: Enum<i32> = get_enum(17, 13);
    let value2: Enum<i32> = get_enum(12, 15);

    println!("{:?}", value1);
    println!("{:?}", value2);
}
