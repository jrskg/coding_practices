use crate::task::task::Task;
use std::fs;

pub fn save_to_file(tasks: &[Task], filename: &str) -> Result<(), String> {
    let json = serde_json::to_string(tasks).map_err(|e| e.to_string())?;
    fs::write(filename, json).map_err(|e| e.to_string())?;
    Ok(())
}

pub fn read_task_from_file(filename: &str) -> Result<Vec<Task>, String> {
    let content = fs::read_to_string(filename).map_err(|e| e.to_string())?;
    let tasks: Vec<Task> = serde_json::from_str(&content).map_err(|e| e.to_string())?;
    Ok(tasks)
}
