use std::{
    fs,
    io::prelude::*,
    net::{TcpListener, TcpStream},
    thread,
    time::Duration,
};

use chapter_20::ThreadPool;

fn main() {
    let listener: TcpListener = TcpListener::bind("127.0.0.1:7878").unwrap();
    let pool: ThreadPool = ThreadPool::new(4);

    for stream in listener.incoming().take(2) {
        let stream: TcpStream = stream.unwrap();

        pool.execute(|| {
            handle_connection(stream);
        });
    }

    println!("shutting down");
}

fn handle_connection(mut stream: TcpStream) {
    let mut buffer: [u8; 1024] = [0; 1024];
    stream.read(&mut buffer).unwrap();

    let get: &[u8; 16] = b"GET / HTTP/1.1\r\n";
    let sleep: &[u8; 21] = b"GET /sleep HTTP/1.1\r\n";

    let (status_line, filename): (&str, &str) = if buffer.starts_with(get) {
        ("HTTP/1.1 200 OK", "hello.html")
    } else if buffer.starts_with(sleep) {
        thread::sleep(Duration::from_secs(5));
        ("HTTP/1.1 200 OK", "hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND", "404.html")
    };

    let contents: String = fs::read_to_string(filename).unwrap();

    let response: String = format!(
        "{}\r\nContent-Length: {}\r\n\r\n{}",
        status_line,
        contents.len(),
        contents
    );

    stream.write_all(response.as_bytes()).unwrap();
    stream.flush().unwrap();
}
