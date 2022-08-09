enum Example {
    VALUE1,
    VALUE2,
    VALUE3,
    VALUE4
}

// error if a case is missing
fn enum_to_int(e: Example) -> u32 {
    match e {
        Example::VALUE1 => 1,
        Example::VALUE2 => {
            // do something
            2
        },
        Example::VALUE3 => 3,
        Example::VALUE4 => 4,
    }
}

fn enum_to_string(e: Example) -> String {
    match e {
        Example::VALUE1 => "enum is value1".to_string(),
        _ => "enum is not value1".to_string() // match all remaining unmatched cases
    }
}

fn plus_one (x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1)
    }
}

fn main() {
    println!("VALUE1 = {}", enum_to_int(Example::VALUE1));
    println!("VALUE2 = {}", enum_to_int(Example::VALUE2));
    println!("VALUE3 = {}", enum_to_int(Example::VALUE3));
    println!("VALUE4 = {}", enum_to_int(Example::VALUE4));

    println!("VALUE1 = {}", enum_to_string(Example::VALUE1));
    println!("VALUE2 = {}", enum_to_string(Example::VALUE2));
    println!("VALUE3 = {}", enum_to_string(Example::VALUE3));
    println!("VALUE4 = {}", enum_to_string(Example::VALUE4));

    let five: Option<i32> = Some(5);
    let six: Option<i32> = plus_one(five);
    let none: Option<i32> = plus_one(None);

    println!("{:?}", five);
    println!("{:?}", six);
    println!("{:?}", none);

    // if let:
    //
    // let value: Option<i32> = Some(15);
    // match value {
    //     Some(x) => println!("the matched value is {}", x),
    //     _ => () // () is called unit is similar to void
    // }
    //
    // can be converted to:

    let value: Option<i32> = Some(15);
    if let Some(x) = value {
        println!("the matched value is {}", x);
    }

    // let mut count: u32 = 0;
    // match value {
    //     Some(x) => println!("matched value = {}, count = {}", x, count),
    //     _ => count += 1,
    // }
    // can be converted to

    let value: Option<i32> = Some(15);
    let mut count: u32 = 0;
    if let Some(x) = value {
        println!("matched value = {}, count = {}", x, count);
    } else {
        count += 1;
    }
    println!("count = {}", count)
}
