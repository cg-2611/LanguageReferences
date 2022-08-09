// regular struct
struct Point {
    x: i32,
    y: i32
}

// tuple struct
#[derive(Debug)] // so struct can be printed using {:?}
struct Colour(i32, i32, i32);

fn get_approximate_mid_point(p1: &Point, p2: &Point) -> Point {
    Point {
        x: (p1.x + p2.x) / 2,
        y: (p1.y + p2.y) / 2
    }
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32
}

// Rectangle implementation
impl Rectangle {
    fn square(size: u32) -> Rectangle {
        Rectangle { width: size, height: size } // return a rectangle with equal width and height
    }

    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

fn main() {
    let point1: Point = Point { x: 2, y: 3 };
    println!("point1: ({}, {})", point1.x, point1.y);

    let mut point2: Point = Point { x: 5, y: 9 };
    println!("point2: ({}, {})", point2.x, point2.y);

    point2.x = 7;
    println!("point2: ({}, {})", point2.x, point2.y);

    let mid_point: Point = get_approximate_mid_point(&point1, &point2);
    println!("mid_point: ({}, {})", mid_point.x, mid_point.y);

    // ..mid_point will use rest of values for pointer3 from mid_point
    // in this case it is just the value for y as x is already defined in point3, however,
    // if there were a z field, then that would also be used
    let point3: Point = Point { x: 1, ..mid_point };
    println!("point3: ({}, {})", point3.x, point3.y);

    let white: Colour = Colour(255, 255, 255);
    let black: Colour = Colour(0, 0, 0);

    println!("white: {:?}", white);
    println!("black: {:?}", black);

    let rectangle: Rectangle = Rectangle { width: 10, height: 4 };
    println!("rectangle area = {}", rectangle.area());

    let square: Rectangle = Rectangle::square(7);
    println!("square dimensions = {}x{}", square.width, square.height);

    let small_rectangle: Rectangle = Rectangle { width: 3, height: 5 };
    let large_rectangle: Rectangle = Rectangle { width: 30, height: 50 };

    println!("small_rectangle can fit in large_rectangle? {}", large_rectangle.can_hold(&small_rectangle));
    println!("large_rectangle can fit in small_rectangle? {}", small_rectangle.can_hold(&large_rectangle));

}
