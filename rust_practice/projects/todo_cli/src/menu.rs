use std::io::{self, Write};

pub fn show_menu() {
    println!("\n== To-Do List Menu ==");
    println!("1. Show all tasks");
    println!("2. Add a new task");
    println!("3. Update task status");
    println!("4. Delete a task");
    println!("5. Exit");
    print!("Enter your choice: ");
    io::stdout().flush().unwrap(); // Flush the prompt
}

pub fn get_input(prompt: &str) -> String {
    print!("{}", prompt);
    io::stdout().flush().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}