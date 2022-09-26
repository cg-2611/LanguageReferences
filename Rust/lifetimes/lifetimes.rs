use std::fmt::Display;

// this function has lifetime annotation of 'a which specifies that
// the references passed to the function live at least as long as lifetime 'a
// and the returned reference will also have a lifetime at least as long as 'a
fn longest_str<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

// the lifetime annotation here means that the SliceOwner cannot outlive the slice member
struct SliceOwner<'a> {
    slice: &'a str,
}

// an example of where lifetime elision rules applied
impl<'a> SliceOwner<'a> {
    fn print_arg_string_and_return_slice(&self, string: &str) -> &str {
        println!("{}", string);
        self.slice
    }
}

fn longest_with_arg_display<'a, T>(x: &'a str, y: &'a str, arg: T) -> &'a str
where
    T: Display,
{
    println!("{}", arg);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let string1: String = String::from("longer string"); // this string is valid until the end of the scope of main
    {
        // this string is valid until the end of the scope of the nested block
        let string2: &str = "string";
        // the result is also valid until the end o the scope of the nested block
        // as string1 outlives the result, this is fine
        // if however, the longest variable was declared in the scope of main, then there would be
        // a compiler error because the borrowed string2 would not live long enough to be used in the scope of main
        let longest: &str = longest_str(string1.as_str(), string2);
        println!("longest: {}", longest);
    }

    // example_slice live until the end of the scope of main
    // all string literals have a 'static lifetime meaning that the reference will live as long as the program
    let example_slice: &str = "example string slice";
    // so does slice_owner, therefore this is fine,
    // if however, slice_owner were to outlive the example_slice then there would be problems
    let slice_owner: SliceOwner = SliceOwner {
        slice: example_slice,
    };

    println!("{}", slice_owner.slice);
    slice_owner.print_arg_string_and_return_slice("another string");

    let longest = longest_with_arg_display("abcedf", "xyz", "display string");
    println!("longest: {}", longest);
}
