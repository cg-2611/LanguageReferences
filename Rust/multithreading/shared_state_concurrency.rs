use std::sync::{Arc, Mutex, MutexGuard};
use std::thread::{self, JoinHandle};

fn main() {
    // Mutex<T> is a smart pointer
    let mutex: Mutex<i32> = Mutex::new(5);

    {
        // lock() acquires the lock and fails if another thread holding the lock panics
        // using unwrap() here means that if another thread panics with the lock, so does this thread
        // MutexGuard<T> is a smart pointer and lock() wraps it in a LockResult that is handled with an unwrap() here, value
        // is a mutable reference to the data inside
        // when the MutexGuard<t> smart pointer goes out of scope, its Drop implementation releases the lock
        let mut value: MutexGuard<i32> = mutex.lock().unwrap();
        *value = 6;

        // here the MutexGuard<T> releases the lock as it goes out of scope
    }

    println!("m = {:?}", mutex);

    // here we must use atomic reference count (Arc) to share ownership of the counter between the thread
    // we cannot move the counter into each thread as the first thread would take ownership adn the remaining threads
    // could not, we would still have single ownership
    // we cannot use an Rc<T> because is no thread safe; when Rc<T> manages the reference count, it increments the count
    // for each clone() and decrements from the count when each clone is dropped, however, it doesn’t use any
    // concurrency primitives to make sure that changes to the count connote be interrupted by another thread
    // this means that we must use an Arc<T>
    // atomics work like primitive types, however, they are safe to share across threads
    // similarly to a RefCell<T>, a Mutex<T> provides interior mutability, and so we see a similar idiom to the
    // combination or Rc<T> and RefCell<T> here with Arc<T> and Mutex<T>, where the Mutex<T> allows us to
    // mutate the contents of the Arc<T>
    // aloes, similarly to how Rc<T> does not protect you from reference cycles, Mutex<T> does not protect
    // you from deadlocks
    let counter: Arc<Mutex<i32>> = Arc::new(Mutex::new(0));
    let mut handles: Vec<JoinHandle<()>> = vec![];

    for _ in 0..10 {
        let counter: Arc<Mutex<i32>> = Arc::clone(&counter);
        let handle: JoinHandle<()> = thread::spawn(move || {
            let mut count: MutexGuard<i32> = counter.lock().unwrap();

            *count += 1;
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("count = {}", *counter.lock().unwrap());
}
