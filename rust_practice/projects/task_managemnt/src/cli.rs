use crate::task::{ status::TaskStatus, task::Task};

pub fn show_menu(){
  println!("Task Manager");
  println!("1. List Tasks");
  println!("2. Add Task");
  println!("3. Complete Task");
  println!("4. Exit");
}

pub fn get_input(prompt: &str) -> String{
  use std::io::{self, Write};
  print!("{}", prompt);
  io::stdout().flush().unwrap();
  let mut input = String::new();
  io::stdin().read_line(&mut input).unwrap();
  input.trim().to_string()
}

pub fn display_tasks(tasks: &[Task]){
  if tasks.len() == 0{
    println!("No tasks to show");
    return;
  }
  println!("-----Pending Tasks-----");
  for task in tasks.iter().filter(|t| t.status == TaskStatus::Pending){
    println!("{:?}", task);
  }
  println!("-----Completed Tasks-----");
  for task in tasks.iter().filter(|t| t.status == TaskStatus::Completed){
    println!("{:?}", task);
  }
}