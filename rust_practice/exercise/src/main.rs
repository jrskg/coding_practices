// use std::io;
mod my_modules;

struct User {
    name: String,
    email: String,
    password: String,
    is_verified: bool,
}

fn main() {
    // let mut users: [Option<User>; 5] = Default::default();
    // for i in 0..users.len() {
    //     let mut name = String::new();
    //     let mut email = String::new();
    //     let mut password = String::new();
    //     let mut is_verified = String::new();

    //     println!("Enter name of {} th user : ", i + 1);
    //     io::stdin()
    //         .read_line(&mut name)
    //         .expect("Failed to get name!");

    //     println!("Enter email of {} th user : ", i + 1);
    //     io::stdin()
    //         .read_line(&mut email)
    //         .expect("Failed to get email!");

    //     println!("Enter password of {} th user : ", i + 1);
    //     io::stdin()
    //         .read_line(&mut password)
    //         .expect("Failed to get password!");

    //     println!(
    //         "Is user {} is verified (1 for verified | 2 for not verified) : ",
    //         i + 1
    //     );
    //     io::stdin()
    //         .read_line(&mut is_verified)
    //         .expect("Failed to get verification!");

    //     let is_verified: u8 = is_verified
    //         .trim()
    //         .parse()
    //         .expect("Failed to parse verificaton");

    //     users[i] = Some(User {
    //         name: name.trim().to_string(),
    //         email: email.trim().to_string(),
    //         password,
    //         is_verified: if is_verified == 1 { true } else { false },
    //     });
    // }

    // for i in 0..users.len() {
    //     println!("User {} details", i + 1);
    //     match &users[i] {
    //         Some(u) => print_user(u),
    //         None => println!("No user found at index {}", i),
    //     }
    //     println!();
    // }
    // let mut n = String::new();
    // println!("Enter a number ");
    // io::stdin()
    //     .read_line(&mut n).expect("Failed to get input");
    // let n:u32 = n.trim().parse().expect("Failed to parse n");
    // let ans = factorial(n);
    // println!("The factorial of {} is {}", n, ans);

    let mut st:my_modules::stack::Stack<i32> = my_modules::stack::Stack::new(5);
    st.push(340);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    match st.top() {
        Some(num) => println!("{}", num),
        None => {}
    }
    st.pop();
    st.push(100);
    match st.top() {
        Some(num) => println!("{}", num),
        None => {}
    }
}

fn _print_user(user: &User) {
    println!("Name : {}", user.name);
    println!("Email : {}", user.email);
    println!("Password : {}", user.password);
    println!("Is Verified : {}", user.is_verified);
}
fn _factorial(n: u32) -> u32 {
    if n <= 1 {
        return 1;
    }
    n * _factorial(n - 1)
}
