use rand::Rng;
use std::{cmp::Ordering, io};

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=100);
    println!("Guess The Number");
    loop {
        let mut guess = String::new();
        println!("Please input your guess : ");
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");
        let guess: i32 = match guess.trim().parse(){
            Ok(num) => num,
            Err(_) => {
                println!("Invalid number");
                continue;
            },
        };

        match guess.cmp(&secret_number) {
            Ordering::Less =>  println!("Too Small"),
            Ordering::Equal => {
                println!("You Won");
                break;
            }
            Ordering::Greater => println!("Too Big")
        }
    }
}
