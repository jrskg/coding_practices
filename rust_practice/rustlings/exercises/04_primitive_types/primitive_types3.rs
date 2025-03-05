fn main() {
    // TODO: Create an array called `a` with at least 100 elements in it.
    // let a = ???

    let a: [i32; 100] = [
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,
        1,2,3,4,4,5,5,55,5,5
    ];

    if a.len() >= 100 {
        println!("Wow, that's a big array!");
    } else {
        println!("Meh, I eat arrays like that for breakfast.");
        panic!("Array not big enough, more elements needed");
    }
}
