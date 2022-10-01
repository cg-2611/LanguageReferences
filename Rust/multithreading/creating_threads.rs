use std::thread::{self, JoinHandle};
use std::time::Duration;

fn main() {
    let thread1: JoinHandle<()> = thread::spawn(|| {
        for i in 1..10 {
            println!("from thread1: {}", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    let vector: Vec<i32> = vec![11, 12, 13, 14, 15];

    // we must specify that the closure moves and takes ownership of the captured environment
    // because otherwise, the closure will infer that the vector only needs to be borrowed as println! only
    // needs a reference to the vector and if the vector is borrowed, then it's lifetime cannot be determined
    // because we do not know how long the thread will run and so we do not know if the reference to the vector
    // would always be valid
    let thread2: JoinHandle<()> = thread::spawn(move || {
        for x in vector {
            println!("from thread2: {}", x)
        }
    });

    // if we put thread1.join().unwrap() here, the the spawned thread will block th email thread until it
    // has finished executing, and then the main thread can execute its own loop

    for i in 1..5 {
        println!("from main thread: {}", i);
        thread::sleep(Duration::from_millis(1));
    }

    // the join method waits for the thread to finish
    // calling join here blocks the mean thread exiting until the spawned thread has completed
    thread1.join().unwrap();

    thread2.join().unwrap();

    // when the main thread has completed, all spawned threads are joined even if they have not
    // finished running
}
