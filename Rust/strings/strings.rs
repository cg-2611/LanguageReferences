use std::ops::Add;

fn main() {
    // rust String supports utf-8 encoded strings

    // creates an empty string
    let empty_string: String = String::new();
    println!("empty_string: {}", empty_string);

    // create a string from an str literal
    // can also use String::from("This is a string.");
    let string: String = "This is a string.".to_string();
    println!("string: {}", string);
    println!("string length: {}", string.len());
    println!("string capacity: {}", string.capacity());
    println!("string to lowercase: {}", string.to_lowercase());
    println!("string to uppercase: {}", string.to_uppercase());

    // cannot index into a String as it is UTF-8 encoded, however we can take a slice
    // if we try to slice only some of a characters bytes, then the program will panic
    let fifth: &str = &string[5..6];
    println!("string character at 5th index: {}", fifth);

    // good practice to handle the returned Option properly
    println!("string index of 'a': {:?}", string.find('a'));
    println!("string index of 'z': {:?}", string.find('z'));
    println!("string index of \"string\": {:?}", string.find("string"));
    println!("string first index of 'i': {:?}", string.find('i'));
    println!("string last index of 'i': {:?}", string.rfind('i'));

    println!("string from index 3: {}", &string[3..]);
    println!("string up to index 12: {}", &string[..12]);
    println!("string between index 3 and 12: {}", &string[3..12]);

    println!("string starts with \"The\": {}", string.starts_with("The"));
    println!(
        "string starts with \"This\": {}",
        string.starts_with("This")
    );
    println!(
        "string ends with \"string\": {}",
        string.ends_with("string")
    );
    println!("string ends with \".\": {}", string.ends_with("."));

    println!("\neach word in string:");
    for word in string.split(" ") {
        println!("{}", word);
    }

    println!("\neach character in string:");
    for character in string.chars() {
        println!("{}", character);
    }

    let new_string: String = string.replace("string", "rust string");
    println!("\nnew_string: {}", new_string);

    println!("string == new_string: {}", string == new_string);
    println!("string < new_string: {}", string < new_string);
    println!("string > new_string: {}", string > new_string);

    let mut mut_string = string.clone();
    mut_string += " This has been appended to mut_string.";
    println!("\nmut_string: {}", mut_string);

    // shadow new_string with result of concatenation as add borrows new_string
    let new_string: String = new_string.add(" This has been appended to new_string.");
    println!("new_string: {}", new_string);
}
