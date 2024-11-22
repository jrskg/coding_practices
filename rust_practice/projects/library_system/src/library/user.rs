#[derive(Debug)]
pub struct User{
  pub id: u32,
  pub name: String,
  pub borrowed_books: Vec<u32>
}

impl User{
  pub fn new(id: u32, name: &str) -> Self{
    Self{
      id,
      name: name.to_string(),
      borrowed_books: Vec::new()
    }
  }
}