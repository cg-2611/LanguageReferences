fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn main() {
    // string slice
    let example_string: String = String::from("example string");

    // let example: &example string tr = &s[0..7]; // slice of string from index 0 (inclusive) to index 7 (exclusive)
    // or equivalent:
    let example_slice: &str = &example_string[..7]; // slice of string from start to index 7 (exclusive)
    let string_slice: &str = &example_string[8..]; // slice of string from index 8 (inclusive) to the end
    let example_string_slice: &str = &&example_string[..]; // slices whole string

    println!("{}", example_slice);
    println!("{}", string_slice);
    println!("{}", example_string_slice);

    let first: &str = first_word(&example_string);

    println!("{}", first);

    // array slice
    let array: [i32; 9] = [1, 2, 3, 4, 5, 6, 7, 8, 9];

    let slice: &[i32] = &array[2..8];

    println!("{:?}", slice);
}
