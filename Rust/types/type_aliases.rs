use std::fmt;

// here we use a type alias to remove the repetition of Error in Result<T, E. types
type Result<T> = std::result::Result<T, std::io::Error>;

pub trait Write {
    fn write(&mut self, buf: &[u8]) -> Result<usize>;
    fn flush(&mut self) -> Result<()>;

    fn write_all(&mut self, buf: &[u8]) -> Result<()>;
    fn write_fmt(&mut self, fmt: fmt::Arguments) -> Result<()>;
}

fn main() {
    // here Kilometres is a type alias for an i32
    // this means that we can substitute an i32 for a Kilometre and they are treated the same
    type Kilometres = i32;

    let x: i32 = 5;
    let y: Kilometres = 5;

    println!("x + y = {}", x + y);
}
