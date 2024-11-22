use db::{get_books, get_users};
use library::actions;
use utils::get_input;

mod library;
mod utils;
mod db;
fn main() {
    let mut books = get_books();
    let mut users = get_users();

    loop{
        println!("Library Management System");
        println!("1. List Books");
        println!("2. List Users");
        println!("3. Borrow Book");
        println!("4. Return  Book");
        println!("5. See Book Details");
        println!("6. See User Details");
        println!("7. Exit");

        let choice = get_input("Enter your choice : ");

        match choice.as_str() {
            "1" => {
                for book in &books {
                    println!("{:?}", book)
                }
            }
            "2" => {
                for user in &users {
                    println!("{:?}", user)
                } 
            }
            "3" => {
                let user_id: u32 = get_input("Enter user id : ").parse().unwrap();
                let book_id: u32 = get_input("Enter book id : ").parse().unwrap();
                let user = users.iter_mut().find(|u| u.id == user_id);
                let book = books.iter_mut().find(|b| b.id == book_id);
                match (user, book) {
                    (Some(user), Some(book)) => {
                        match actions::borrow_book(user, book) {
                            Ok(_) => println!("Book {} borrowed successfully to {}", book.title, user.name),
                            Err(err) =>println!("{}", err)
                        }   
                    }
                    _ => println!("Invalid userId or bookId")
                }
            }
            "4" => {
                let user_id: u32 = get_input("Enter user id : ").parse().unwrap();
                let book_id: u32 = get_input("Enter book id : ").parse().unwrap();
                let user = users.iter_mut().find(|u| u.id == user_id);
                let book = books.iter_mut().find(|b| b.id == book_id);

                match (user, book) {
                    (Some(user), Some(book)) => {
                        match actions::return_book(user, book) {
                            Ok(_) => println!("Book {} returned successfully from {}", book.title, user.name),
                            Err(err) => println!("{}", err)
                        }
                    }   
                    _ => println!("Invalid userId or bookId")
                }
            }
            "5" => {
                let book_id: u32 = get_input("Enter book id : ").parse().unwrap();
                let book = books.iter().find(|b| b.id == book_id);
                match book {
                    Some(book) => {
                        actions::display_book(book);
                    }
                    _ => println!("Invalid bookId")
                }
            }
            "6" => {
                let user_id: u32 = get_input("Enter user id : ").parse().unwrap();
                let user = users.iter().find(|u| u.id == user_id);
                match user {
                    Some(user) => {
                        actions::display_user(user);
                    }
                    _ => println!("Invalid userId")
                }
            }
            "7" => {
                break;
            }
            _=>{
                println!("Invalid choice");
            }
        }
    }
}
