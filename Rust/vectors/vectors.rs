fn main() {
    // creates an empty vector of i32s
    let empty_vector: Vec<i32> = Vec::new();
    println!("{:?}", empty_vector);

    // the following is similar to:
    //     let mut vector: Vec<i32> = Vec::new();
    //     vector.push(5);
    //     vector.push(6);
    //     vector.push(7);
    //     vector.push(8);

    let vector: Vec<i32> = vec![5, 6, 7, 8];
    println!("{:?}", vector);

    // access second element of vector
    let second: &i32 = &vector[1];
    println!("{}", second);

    let second: Option<&i32> = vector.get(1);
    match second {
        Some(second) => println!("{}", second),
        None => println!("no second element"),
    }

    // when accessing out of range, using Vec<T>.get() does not panic as it returns an Option, however.
    // when using [] to access an out of range element, then this panics

    let mut vector2: Vec<i32> = vec![1, 2, 3];
    println!("{:?}", vector2);
    vector2.push(4);
    println!("{:?}", vector2);

    // the following does not compile as the vector is immutably borrowed before the vector is mutable
    // borrowed when new value is pushed:
    //     let first: &i32 = &vector2[0]; <- immutable borrow
    //     vector2.push(9); <- mutable borrow

    // iterating over immutable vector
    let vector3: Vec<i32> = vec![12, 13, 14, 15];
    println!("{:?}", vector3);
    for i in &vector3 {
        println!("{}", i);
    }

    // iterating over mutable references to elements in a mutable vector
    // here we add 200 to each element in vector4
    let mut vector4: Vec<i32> = vec![4, 5, 6];
    println!("{:?}", vector4);
    for i in &mut vector4 {
        *i += 200;
    }
    println!("{:?}", vector4);
}
