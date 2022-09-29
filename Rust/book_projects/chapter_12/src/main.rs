use std::env;
use std::process;

use chapter_12::Config;

fn main() {
    let config: Config = Config::build(env::args()).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {err}");
        process::exit(1);
    });

    if let Err(e) = chapter_12::run(config) {
        eprintln!("error: {e}");
        process::exit(1);
    }
}
