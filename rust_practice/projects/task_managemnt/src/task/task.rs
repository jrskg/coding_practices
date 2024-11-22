use super::status::TaskStatus;
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Debug)]
pub struct Task{
  pub id: u32,
  pub name: String,
  pub priority: u8,
  pub status: TaskStatus,
  pub due_date: String
}

impl Task {
    pub fn new(id: u32, name: String, priority: u8, due_date: String) -> Self {
      Self{
        id, name, priority, due_date,
        status: TaskStatus::Pending
      }
    }

    pub fn mark_completed(&mut self){
      self.status = TaskStatus::Completed;
    }
}