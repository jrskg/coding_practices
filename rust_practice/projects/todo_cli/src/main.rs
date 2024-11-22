use db::{connect, setup};
use menu::{get_input, show_menu};
use task::{add_new_task, delete_task, fetch_all_todos, update_status};

mod db;
mod menu;
mod task;

#[tokio::main]
async fn main() {
    let pool = connect().await.expect("Failed to connect to db");
    setup(&pool).await.expect("Failed to initialize db");
    let mut tasks = fetch_all_todos(&pool).await.unwrap_or(vec![]);

    loop {
        show_menu();
        let choice: u8 = get_input("Enter you choice : ").parse().unwrap_or(0);
        match choice {
            1 => {
                if tasks.is_empty() {
                    println!("\n\nNo tasks found\n\n");
                } else {
                    println!();
                    for task in tasks.iter() {
                        println!(
                            "ID: {}, Title: {}, Description: {}, Status: {}",
                            task.id,
                            task.title,
                            task.description,
                            task.status
                        );
                    }
                }
            }
            2 => {
                let title = get_input("Enter title : ");
                let description = get_input("Enter description : ");
                match add_new_task(&pool, title, description).await {
                    Err(err) => println!("\nAdd task failed, Err :- {}", err),
                    Ok(data) => {
                        println!("\nTask Added");
                        tasks.push(data)
                    },
                }
            }
            3 => {
                let id = get_input("Enter task id : ").parse().unwrap_or(-1);
                if id < 0{
                    println!("\nInvalid id given");
                    continue;
                }
                let status: u8 = get_input("Enter status to set \n1 for Pending\n2 for Completed\n -> ").parse().unwrap_or(0);
                if status < 1 && status > 2 {
                    println!("\nInvalid status");
                    continue;
                }
                let status = if status == 1 {"Pending"} else {"Completed"};
                match update_status(&pool, id, status).await {
                    Err(err) => println!("\nUpdate status failed, {}", err),
                    Ok(_) => {
                        println!("\nTask status updated");
                        if let Some(task) = tasks.iter_mut().find(|t| t.id == id) {
                            task.status = status.to_string();
                        }
                    }
                }
            }
            4 => {
                let id = get_input("Enter task id : ").parse().unwrap_or(-1);
                if id < 0{
                    println!("\nInvalid id");
                    continue;
                }
                match delete_task(&pool, id).await {
                    Err(err) => println!("\nDelete task failed, {}", err),
                    Ok(_) => {
                        println!("\nTask deleted");
                        tasks.retain(|t| t.id != id);
                    }
                }
            }
            5 => {
                println!("\nQuitting");
                break;
            }
            _ => println!("\nInvalid Input!!"),
        }
    }
}
