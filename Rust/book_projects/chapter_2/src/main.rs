use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=100);

    loop {
        println!("Input guess:");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("Guess: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Guess is less than secret number"),
            Ordering::Greater => println!("Guess is greater than secret number"),
            Ordering::Equal => {
                println!("Guess is correct");
                break;
            }
        }
    }
}
