use std::fs::{read_to_string, File};
use std::io::Read;
use std::io::{Error, ErrorKind};

// we can propagate errors with the ? operator from functions that return Result or Option

// these function is only for a demonstration and could be refactored to
// just implicitly return the result of read_to_string()

// fn read_file_contents(path: &str) -> Result<String, Error> {
//     let mut file: File = File::open(&path)?; // propagate Err to caller if open() fails
//     let mut contents: String = String::new();
//     file.read_to_string(&mut contents)?; // propagate Err to caller if read_to_string() fails
//     Ok(contents)
// }

fn read_file_contents(path: &str) -> Result<String, Error> {
    let mut contents: String = String::new();
    File::open(&path)?.read_to_string(&mut contents)?; // propagate Err to caller if open or read_to_string() fail
    Ok(contents)
}

fn main() {
    // for unrecoverable errors, use panic! to perform stack unwinding
    // the backtrace is displayed too
    // panic!("message to display");

    // for recoverable errors use Result<T, E> or Option<T>
    // matching on all errors
    let path: &str = "./file_that_does_not_exist.txt";

    let read_result: Result<String, Error> = read_to_string(path);
    let _contents: String = match read_result {
        Ok(string) => string,
        Err(error) => panic!("error reading file {}: {:?}", path, error),
    };

    // matching on multiple errors
    let read_result: Result<String, Error> = read_to_string(path);
    let _contents: String = match read_result {
        Ok(string) => string,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => panic!("error reading file {}: not found", path),
            other_error => panic!("error reading file {}: {:?}", path, other_error),
        },
    };

    // we can use Result.unwrap() (or Option.unwrap()) to get the value of the Ok variant (or the Some variant))
    // if we try to unwrap an Err variant (or a None variant) then unwrap() will panic
    // e.g. let contents: String = read_to_string(path).unwrap();
    // the expect() method can be used to provide a message for the panic instead
    // e.g. let contents: String = read_to_string(path).expect("the provided path should lead to a file that exists");

    // using closures instead of pattern matching on Result
    let read_result: Result<String, Error> = read_to_string(path);
    let _contents: String = read_result.unwrap_or_else(|error: Error| {
        if error.kind() == ErrorKind::NotFound {
            panic!("error reading file {}: not found", path);
        } else {
            panic!("error reading file {}: {:?}", path, error);
        }
    });

    // we must handle propagated errors
    let read_result = read_file_contents(path);
    let _contents = match read_result {
        Ok(string) => string,
        Err(error) => panic!("error reading file {}, {:?}", path, error),
    };
}
