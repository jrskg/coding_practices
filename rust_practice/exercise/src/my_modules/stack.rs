pub struct Stack<T>{
  arr: Vec<T>,
  top: usize,
  capacity: usize
}

impl<T> Stack<T>{
  pub fn new(capacity: usize) -> Self{
    Stack{
      arr: Vec::with_capacity(capacity),
      top: 0,
      capacity
    }
  }

  pub fn push(&mut self, data:T){
    if self.top == self.capacity {
      println!("Stack overflow");
      return;
    }
    self.arr.push(data);
    self.top += 1;
  }

  pub fn pop(&mut self){
    if self.top <= 0 {
      println!("Stack underflow");
      return;
    }
    self.arr.pop();
    self.top -= 1;
  }

  pub fn top(&self) -> Option<&T>{
    if self.top <= 0 {
      println!("Stack underflow");
      return None;
    }
    Some(&self.arr[self.top - 1])
  }
}