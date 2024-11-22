#[derive(Debug)]
pub struct Book{
  pub id:u32,
  pub title: String,
  pub author: String,
  pub is_borrowed: bool
}

impl Book{
  pub fn new(id:u32, title:&str, author:&str) -> Self{
    Self{
      id,
      title: title.to_string(),
      author: author.to_string(),
      is_borrowed: false
    }
  }
}