use std::env;
use std::process;

use chapter_12::Config;

fn main() {
    let args: Vec<String> = env::args().collect();

    let config: Config = Config::build(&args).unwrap_or_else(|err: &str| {
        eprintln!("error parsing arguments: {err}");
        process::exit(1);
    });

    if let Err(e) = chapter_12::run(config) {
        eprintln!("error: {e}");
        process::exit(1);
    }
}
