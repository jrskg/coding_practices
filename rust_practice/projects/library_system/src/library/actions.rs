use crate::library::{user::User, book::Book};
pub fn borrow_book(user: &mut User, book: &mut Book) -> Result<(), String>{
  if book.is_borrowed{
    return Err(format!("Book {} is already borrowed!", book.title));
  }
  book.is_borrowed = true;
  user.borrowed_books.push(book.id);
  Ok(())
}

pub fn return_book(user: &mut User, book: &mut Book) -> Result<(), String>{
  if !book.is_borrowed{
    return Err(format!("Book {} was not borrowed!", book.title));
  }
  if let Some(pos) = user.borrowed_books.iter().position(|&p| p == book.id){
    user.borrowed_books.remove(pos);
    book.is_borrowed = false;
    Ok(())
  }else{
    Err("This user didn't borrow this book".to_string())
  }
}

pub fn display_book(book:&Book){
  println!("Book ID : {}", book.id);
  println!("Book Title : {}", book.title);
  println!("Book Author : {}", book.author);
  let status = if book.is_borrowed {"This book has been borrowed"} else {"This book has not been borrowed"};
  println!("{}", status);
}
pub fn display_user(user:&User){
  println!("User ID : {}", user.id);
  println!("User Name : {}", user.name);
  println!("Borrowed Books IDs : {:?}", user.borrowed_books);
  
}