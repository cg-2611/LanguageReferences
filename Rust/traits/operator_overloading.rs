use std::ops::Add;

// operator overloading can be achieved by using default generic type parameters
// when we use generic type parameters, we can specify a default concrete type for the generic type eliminating
// the need for implementers of the trait to specify a concrete type if the default type works

// rust does not allow the creation  of custom operators or overload arbitrary operators, however, you can overload
// the operations and corresponding traits listed in std::ops by implementing the traits associated with the operator

#[derive(Debug, Copy, Clone, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

// here we can see that the Add trait has a default generic type parameter of Self wick is used for
// the right hand side of the addition
// there is also an associated type that is used for the output of the addition
// trait Add<Rhs=Self> {
//     type Output;

//     fn add(self, rhs: Rhs) -> Self::Output;
// }

// here we do not override the default generic type parameter so we are adding 2 points
impl Add for Point {
    type Output = Point;

    fn add(self, other: Point) -> Point {
        Point {
            x: self.x + other.x,
            y: self.y + other.y,
        }
    }
}

// here we do override the default type parameter so we can add an i32 to the point
// the implementation here chooses to add the value of other to both the x and y fields
impl Add<i32> for Point {
    type Output = Point;

    fn add(self, other: i32) -> Point {
        Point {
            x: self.x + other,
            y: self.y + other,
        }
    }
}

fn main() {
    assert_eq!(
        Point { x: 1, y: 0 } + Point { x: 2, y: 3 },
        Point { x: 3, y: 3 }
    );

    assert_eq!(Point { x: 4, y: 7 } + 10, Point { x: 14, y: 17 },);
}
