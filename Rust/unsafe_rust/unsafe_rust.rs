use std::slice;

// unsafe rust allows the following:
//  - dereference a raw pointer
//  - call an unsafe function or method
//  - access or modify a mutable static variable
//  - implement an unsafe trait
//  - access fields of unions

// unsafe does not turn off the borrow checker or disable any other safety checks: if you use a reference in
// unsafe code, it will still be checked, there is still some degree of safety in an unsafe block

// unsafe only gives access to the five features that are then not checked by the compiler for memory safety

// raw pointers:
//  - are allowed to ignore the borrowing rules by having both immutable and mutable pointers or multiple mutable
//    pointers to the same location
//  - aren’t guaranteed to point to valid memory
//  - are allowed to be null
//  - don’t implement any automatic clean-up

unsafe fn dangerous() {
    // do something unsafe
}

// "C" defines which application binary interface the external function uses
// the ABI defines how to call the function at the assembly level
// the "C" ABI follows the ABI of the C programming language
extern "C" {
    fn abs(n: i32) -> i32;
}

// wrap unsafe function calls in safe abstraction
fn split_at_mut(values: &mut [i32], mid: usize) -> (&mut [i32], &mut [i32]) {
    let len: usize = values.len();
    let ptr: *mut i32 = values.as_mut_ptr();

    assert!(mid <= len);

    unsafe {
        (
            slice::from_raw_parts_mut(ptr, mid),
            slice::from_raw_parts_mut(ptr.add(mid), len - mid),
        )
    }
}

// static variables can only store references with the 'static lifetime
// accessing an immutable static variable is safe
// a subtle difference between constants and immutable static variables is that values in a static variable have a
// fixed address in memory; i.e. using the value will always access the same data
// constants, on the other hand, are allowed to duplicate their data whenever they’re used
// another difference is that static variables can be mutable, however accessing and modifying mutable static variables
// is unsafe because having multiple threads access and mutate a static variable can result in data races
static mut COUNTER: u32 = 0;

fn add_to_count(inc: u32) {
    unsafe {
        COUNTER += inc;
    }
}

// a trait must be marked unsafe when at least one of the methods has an unsafe invariant
unsafe trait Foo {
    // methods go here
}

// using unsafe impl, we’re promising that we’ll uphold the invariants that the compiler cannot verify
unsafe impl Foo for i32 {
    // method implementations go here
}

fn main() {
    // creating raw pointers is safe in rust, we only need the unsafe block to dereference them
    let mut x: i32 = 5;

    // immutable pointer to x
    let x_p1: *const i32 = &x as *const i32; // cast an immutable reference to immutable pointer

    // mutable pointer to x
    let x_p2: *mut i32 = &mut x as *mut i32; // cast a mutable reference to a mutable pointer

    // needed to dereference them
    unsafe {
        println!("before mutation x_p1 = {}", *x_p2);
        println!("before mutation x_p2 = {}", *x_p1);

        *x_p2 += 10;

        println!("after mutation x_p1 = {}", *x_p2);
        println!("after mutation x_p2 = {}", *x_p1);

        dangerous(); // must be called in an unsafe block
    }

    let mut v: Vec<i32> = vec![1, 2, 3, 4, 5, 6];

    let r: &mut [i32] = &mut v[..];

    let (a, b): (&mut [i32], &mut [i32]) = split_at_mut(r, 3);

    assert_eq!(a, &mut [1, 2, 3]);
    assert_eq!(b, &mut [4, 5, 6]);

    unsafe {
        println!("abs(-3) C function: {}", abs(-3));
    }

    add_to_count(3);

    unsafe {
        println!("COUNTER: {}", COUNTER);
    }
}
