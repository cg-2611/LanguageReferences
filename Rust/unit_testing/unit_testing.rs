// to test the equality of Rectangle instances, the rectangle must implement the PartialEq and Debug traits
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn new(width: u32, height: u32) -> Self {
        Self { width, height }
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

// this attribute tells cargo to only build the tests when cargo test is run
#[cfg(test)]
mod tests {
    // bring outer scope into tests module
    use super::*;

    // use #[test] to signify that the following function is a test
    // use #[ignore] to ignore a test
    // #[should_panic] can be used to indicate that the test should panic
    // a test with this attribute will fail if the function does not panic and will pass if the function panics
    // for whatever reason
    // #[should_panic(expected = "expected substring")] can be used to
    // make the test only pass for a specific panic that has the expected substring as a substring of the panic message
    #[test]
    fn larger_can_hold_smaller() {
        let larger: Rectangle = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller: Rectangle = Rectangle {
            width: 5,
            height: 1,
        };

        // can also use assert_eq!(true, larger.can_hold(&smaller)); or assert_ne!(false, larger.can_hold(&smaller));
        assert!(larger.can_hold(&smaller));
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger: Rectangle = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller: Rectangle = Rectangle {
            width: 5,
            height: 1,
        };

        // can also use assert_eq!(false, smaller.can_hold(&larger)); or assert_ne!(true, smaller.can_hold(&larger));
        assert!(!smaller.can_hold(&larger));
    }

    #[test]
    fn rectangle_created_correctly() {
        let width: u32 = 5;
        let height: u32 = 6;
        let rectangle: Rectangle = Rectangle::new(width, height);

        // example message to show on failure, the message is a format string that can take further arguments
        // to sbstitute into the string
        assert_eq!(width, rectangle.width, "width does not match");
        assert_eq!(height, rectangle.height, "height does not hatch");
    }

    // instead of a test panicking when it fails, we can use a Result instead
    // #[should_panic] cannot be used on tests that return Result
    // to assert that an operation returns an Err, don’t use the question mark operator
    // use assert!(value.is_err()) instead
    #[test]
    fn rectangle_created_correctly_result() -> Result<(), String> {
        let width: u32 = 5;
        let height: u32 = 6;
        let rectangle: Rectangle = Rectangle::new(width, height);

        if width == rectangle.width && height == rectangle.height {
            Ok(())
        } else {
            Err(String::from("width and height do not match expected"))
        }
    }
}
