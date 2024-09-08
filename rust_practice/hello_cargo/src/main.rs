use std::io::{self, Write};

fn main() {
    // match_example();
    // let data: (i32, String, i32, String) = tuple_example();
    // println!("\nThe Details are : ");
    // println!("ID : {}", data.0);
    // println!("Name : {}", data.1);
    // println!("Salary : {}", data.2);
    // println!("Role : {}", data.3);

    ownership();
}

fn _match_example(){
    let mut a = String::new();
    println!("Enter a number : ");
    io::stdin().read_line(&mut a).expect("Failed to take input");
    let a:i8 = match a.trim().parse(){
        Ok(num) => num,
        Err(err)=> {
            println!("Error : {err}");
            return;
        },
    };
    println!("You entered {a}");
}

fn _tuple_example() -> (i32, String, i32, String){
    let mut person: (i32, String, i32, String) = (1, String::new(), -1, String::new());
    let mut str = String::new();
    print!("Enter ID : ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut str).expect("Failed to get ID");
    person.0 = str.trim().parse().expect("Invalid ID given");

    str.clear();
    print!("Enter Name : ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut str).expect("Failed to get name");
    person.1 = str.trim().to_string();

    str.clear();
    print!("Enter Salary : ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut str).expect("Failed to get salary");
    person.2 = str.trim().parse().expect("Invalid Salary Given");

    str.clear();
    print!("Enter Role : ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut str).expect("Failed to get role");
    person.3 = str.trim().to_string();
    str.clear();

    person

}

fn ownership(){
    // let a = 90;
    // let b = a;
    // println!("A = {a}");
    // println!("B = {b}");

    let a = String::from("Hello");
    let a = another(a);
    println!("A = {a}");
}

fn another(s: String) -> String{
    println!("Using inise the function s = {s}");
    s
}