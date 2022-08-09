fn main() {
    // shadowing is different from marking a variable as mut, we will get a compile time error if we try to reassign
    // without using let

    /* x1 */ let x: i32 = 5;     // initialize variable x with value 5
    /* x2 */ let x: i32 = x + 1; // shadow x1 - initialize x and assign it a value of x1 + 1

    {
        /* x3 */ let x: i32 = x * 2; // shadow x2 - initialize x and assign it a value of x2 * 2
        println!("inner scope x = {x}");
    }

    println!("x = {x}");
}