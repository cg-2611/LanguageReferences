use std::{
    sync::{mpsc, Arc, Mutex},
    thread,
};

pub struct ThreadPool {
    workers: Vec<Worker>,
    sender: Option<mpsc::Sender<Job>>,
}

type Job = Box<dyn FnOnce() + Send + 'static>;

impl ThreadPool {
    pub fn new(size: usize) -> ThreadPool {
        assert!(size > 0);

        let (sender, receiver): (
            mpsc::Sender<Box<dyn FnOnce() + Send>>,
            mpsc::Receiver<Box<dyn FnOnce() + Send>>,
        ) = mpsc::channel();

        let receiver: Arc<Mutex<mpsc::Receiver<Box<dyn FnOnce() + Send>>>> =
            Arc::new(Mutex::new(receiver));

        let mut workers: Vec<Worker> = Vec::with_capacity(size);

        for id in 0..size {
            workers.push(Worker::new(id, Arc::clone(&receiver)));
        }

        ThreadPool {
            workers,
            sender: Some(sender),
        }
    }

    pub fn execute<F>(&self, f: F)
    where
        F: FnOnce() + Send + 'static,
    {
        let job: Box<F> = Box::new(f);

        self.sender.as_ref().unwrap().send(job).unwrap();
    }
}

impl Drop for ThreadPool {
    fn drop(&mut self) {
        drop(self.sender.take());

        for worker in &mut self.workers {
            println!("shutting down worker {}", worker.id);

            if let Some(thread) = worker.thread.take() {
                thread.join().unwrap();
            }
        }
    }
}

struct Worker {
    id: usize,
    thread: Option<thread::JoinHandle<()>>,
}

impl Worker {
    fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Job>>>) -> Worker {
        let thread: thread::JoinHandle<()> = thread::spawn(move || loop {
            let message: Result<Box<dyn FnOnce() + Send>, mpsc::RecvError> =
                receiver.lock().unwrap().recv();

            match message {
                Ok(job) => {
                    println!("worker {id} got a job; executing...");

                    job();
                }
                Err(_) => {
                    println!("worker {id} disconnected; shutting down");
                    break;
                }
            }
        });

        Worker {
            id,
            thread: Some(thread),
        }
    }
}
