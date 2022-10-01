use std::sync::mpsc::{self, Receiver, Sender}; // mpsc stands for multiple producer, single consumer
use std::thread;
use std::time::Duration;

fn main() {
    // the first value in the tuple is the transmitter
    // the second value in the tuple is the receiver
    let (tx1, rx1): (Sender<i32>, Receiver<i32>) = mpsc::channel();

    let tx2: Sender<i32> = tx1.clone();

    thread::spawn(move || {
        let xs: Vec<i32> = vec![101, 102, 103, 104, 105];

        for x in xs {
            // send() takes ownership of its arguments, so trying to use them after calling send() will
            // lead to a compiler error
            tx1.send(x).unwrap(); // using unwrap here for simplicity, better to handle the error
            thread::sleep(Duration::from_secs(1));
        }
    });

    thread::spawn(move || {
        let xs: Vec<i32> = vec![201, 202, 203, 204, 205];

        for x in xs {
            tx2.send(x).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    // recv() will block on the main thread and wait until a value is sent down the channel
    // once a value is sent, recv() will return it in a Result<T, E>
    // when the transmitter closes, recv() will return an error to signal that no more values to receive
    // an alternative is to use try_recv() which does not block and instead returns a Result<T, E> immediately
    // with an Ok() value holding the message, or an Err if there was not a message tor receive
    // here, for simplicity, using recv() is fine as the main thread is not doing anything else,
    // however, using try_recv() is a better choice as we can poll and handle the message of it is there
    // or continue with other things until we poll again if no message

    for received in rx1 {
        println!("received: {}", received);
    }
}
