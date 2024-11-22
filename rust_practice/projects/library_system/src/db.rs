use crate::library::{book::Book, user::User};

pub fn get_books() -> Vec<Book>{
  vec![
    Book::new(1, "The DSA Buster", "John Doe"),
    Book::new(2, "JAVA Programming", "Json Nichard"),
    Book::new(3, "RUST Boom", "Suxpis Okaich"),
  ]
}

pub fn get_users() -> Vec<User>{
  vec![
    User::new(1, "Suraj Gupta"),
    User::new(2, "Arbind Das"),
  ]
}