#[derive(Debug)]
enum Example1 {
    VALUE1,
    VALUE2,
    VALUE3,
    VALUE4
}

// enum with 4 variants with different types
#[derive(Debug)]
enum Example2 {
    VALUE1,
    VALUE2 { x: i32, y: i32 },
    VALUE3(String),
    VALUE4(i32, i32, i32)
}

impl Example2 {
    fn function(&self) {
        println!("{:?}", self);
    }
}

fn main() {
    let value3: Example1 = Example1::VALUE3;
    println!("Example1: {:?} {:?} {:?} {:?}", Example1::VALUE1, Example1::VALUE2, value3, Example1::VALUE4);

    println!("Example2: ");
    let value2: Example2 = Example2::VALUE2 { x: 1, y: 1 };
    Example2::VALUE1.function();
    value2.function();
    Example2::VALUE2 { x: 4, y: 4 }.function();
    Example2::VALUE3("example string".to_string()).function();
    Example2::VALUE4(9, 10, 11).function();

}
