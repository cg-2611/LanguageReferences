// iterators are lazy, meaning they have no effect until you call methods that consume the iterator to use it up
fn main() {
    let v1: Vec<i32> = vec![1, 2, 3];

    // iter method produces an iterator over immutable references
    let v1_iter = v1.iter();

    // the values we get from the iterator are immutable references
    for element in v1_iter {
        println!("v1 element: {}", element);
    }

    let v2: Vec<i32> = vec![4, 5, 6];

    // into_iter method takes ownership of the the vector and returns owned values
    let v2_iter = v2.into_iter();

    // the values we get from this iterator are owned values
    for element in v2_iter {
        println!("v2 element: {}", element);
    }

    let mut v3: Vec<i32> = vec![4, 5, 6];

    // iter_mut method produces an iterator over mutable references
    let v3_iter = v3.iter_mut();

    // the values we get from the iterator are mutable references
    for element in v3_iter {
        *element += 3; // add 3 to each element before printing
        println!("v3 element: {}", element);
    }
}

#[cfg(test)]
#[test]
fn iterator_demonstration() {
    let v: Vec<i32> = vec![1, 2, 3];

    let mut v_iter = v.iter();

    assert_eq!(v_iter.next(), Some(&1));
    assert_eq!(v_iter.next(), Some(&2));
    assert_eq!(v_iter.next(), Some(&3));
    assert_eq!(v_iter.next(), None);
}

#[test]
fn iterator_sum() {
    let v: Vec<i32> = vec![1, 2, 3];

    let v_iter = v.iter();

    // methods that call Iterator.next() are called consumption adaptors, because
    // calling them uses up the iterator
    // the sum method takes ownership of the iterator and iterates through the
    // items by calling next
    let total: i32 = v_iter.sum();

    // we cannot use v_iter here because sum takes ownership of it

    assert_eq!(total, 6);
}

#[test]
fn iterator_map() {
    let v1: Vec<i32> = vec![1, 2, 3];

    // iterator adaptors do not consume the iterator, instead, they produce different iterators by changing some
    // aspect of the original iterator
    // the map method takes a closure to call on each item as the items are iterated through and returns a new iterator
    // that produces the modified items
    // the collect method is needed here to consume the iterator and collect the values into a collection
    let v2: Vec<i32> = v1.iter().map(|x: &i32| x + 1).collect();

    assert_eq!(v2, vec![2, 3, 4]);
}

#[test]
fn iterator_filter() {
    let v1: Vec<i32> = vec![1, 2, 3, 4, 5];

    // the filter method takes a closure that returns bool to call on each item as the items are iterated through and
    // returns a new iterator that produces the items that resulted in the closure returning true
    // the collect method is needed here to consume the iterator and collect the values into a collection
    let v2: Vec<i32> = v1.into_iter().filter(|x: &i32| x % 2 != 0).collect();

    assert_eq!(v2, vec![1, 3, 5]);
}
