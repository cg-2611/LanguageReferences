use std::collections::HashMap;

fn main() {
    let mut example_map: HashMap<String, i32> = HashMap::new();

    // for types that implement the Copy trait, like i32, the values are copied into the hash map
    // for owned values, like String, the values are moved into the hash map and the hash map will own the values
    example_map.insert(String::from("key 1"), 1);
    example_map.insert(String::from("key 2"), 2);
    example_map.insert(String::from("key 3"), 3);
    example_map.insert(String::from("key 4"), 4);

    let key_2: String = String::from("key 2");
    let value_2: Option<&i32> = example_map.get(&key_2);

    println!("{:?}", value_2);

    println!("{:?}", example_map);

    for (key, value) in &example_map {
        println!("{}: {}", key, value);
    }

    example_map.insert(String::from("key 2"), 6); // update the value of key 2

    let key_2: String = String::from("key 2");
    let value_2: Option<&i32> = example_map.get(&key_2);

    println!("{:?}", value_2);

    // get the entry of key 5 or insert it with the value 5 if it is not already in the hash map
    let value_5: &mut i32 = example_map.entry(String::from("key 5")).or_insert(5);
    println!("{:?}", value_5);

    // does nothing as key is already
    let value_4: &mut i32 = example_map.entry(String::from("key 4")).or_insert(5);
    println!("{:?}", value_4);
}
