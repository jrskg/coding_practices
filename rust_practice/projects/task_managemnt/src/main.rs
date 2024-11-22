mod task;
mod cli;
mod persistence;

// Task Manager
// 1. List Tasks
// 2. Add Task
// 3. Complete Task
// 4. Save Tasks
// 5. Load Tasks
// 6. Exit

use persistence::*;
use cli::*;
use task::task::Task;
fn main() {
    let mut tasks: Vec<Task> = vec![];
    match read_task_from_file("okay.json") {
        Ok(task_from_file) => tasks = task_from_file,
        Err(_) => {}
    }
    loop {
        show_menu();
        let user_choice:u8 = get_input("Enter your choice : ").parse().unwrap_or(0);
        match user_choice {
            1 => display_tasks(&tasks),
            2 => {
                let id = tasks.len() as u32 + 1;
                let name = get_input("Enter task name : ");
                let priority: u8 = get_input("Enter task priority (1 - 5) : ").parse().unwrap_or(1);
                let due_date = get_input("Enter due date (YYYY-MM-DD) : ");
                tasks.push(Task::new(id, name, priority, due_date));
                println!("Task added");
            },
            3 => {
                let task_id = get_input("Enter task id : ");
                match task_id.parse::<u32>() {
                    Ok(id) => {
                        if let Some(task) = tasks.iter_mut().find(|t| t.id == id){
                            task.mark_completed();
                            println!("Task updated");
                        }
                    },
                    Err(_) => println!("Invalid id format, it should be a number")
                }
            }
            4 => {
                save_to_file(&tasks, "okay.json").unwrap();
                println!("Quitting");
                break;
            }
            _ => println!("Invalid input")
        }
    }
}
