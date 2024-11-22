struct User{
  name: String,
  user_name: String,
  email: String,
  password: String,
  role: String,
  is_verified: bool
}

fn main(){
  let user1 = User{
    name: String::from("Suraj Gupta"),
    user_name: String::from("skg_suraj"),
    email: String::from("suraj@gmail.com"),
    password: String::from("Suraj@123"),
    role: String::from("Developer"),
    is_verified: true
  };

  print_user(&user1);

}

fn print_user(user: &User){
  println!("Name : {}", user.name);
  println!("User Name : {}", user.user_name);
  println!("Email : {}", user.email);
  println!("Password : {}", user.password);
  println!("Role : {}", user.role);
  println!("Is Verified : {}", user.is_verified);
}