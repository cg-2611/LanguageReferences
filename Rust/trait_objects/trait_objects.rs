pub trait Print {
    fn print(&self);
}

pub struct Printer {
    // structs is a vector of Box<T> smart pointers to types that implement the Print trait
    // here Box<dyn Print> is called a trait object, and the dyn keyword highlights that calls to
    // methods on the associated trait are dynamically dispatched
    pub structs: Vec<Box<dyn Print>>,
}

// the following code is not equivalent because this states that all the elements in thee
// vector must be the same type and that type must implement the Print trait
// pub struct Printer<T: Print> {
//     pub structs: Vec<T>,
// }

// impl<T> Printer<T>
// where
//     T: Print,
// {
//     pub fn print_each(&self) {
//         for s in self.structs.iter() {
//             s.print();
//         }
//     }
// }

impl Printer {
    pub fn print_each(&self) {
        for s in self.structs.iter() {
            s.print();
        }
    }
}

pub struct Struct1 {
    value: i32,
}

impl Print for Struct1 {
    fn print(&self) {
        println!("struct1 value: {}", self.value);
    }
}

struct Struct2 {
    string: String,
}

impl Print for Struct2 {
    fn print(&self) {
        println!("struct2 string: {}", self.string);
    }
}

fn main() {
    let printer: Printer = Printer {
        structs: vec![
            Box::new(Struct2 {
                string: String::from("example string"),
            }),
            Box::new(Struct1 { value: 19 }),
        ],
    };

    printer.print_each();
}
