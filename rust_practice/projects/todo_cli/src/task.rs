use serde::{Deserialize, Serialize};
use sqlx::{mysql::MySqlRow, FromRow, MySql, Pool, Row};

#[derive(Deserialize, Serialize, Debug)]
pub struct Task {
    pub id: i32,
    pub title: String,
    pub description: String,
    pub status: String,
}

impl FromRow<'_, MySqlRow> for Task {
    fn from_row(row: &MySqlRow) -> Result<Self, sqlx::Error> {
        Ok(Task {
            id: row.try_get("id")?,
            title: row.try_get("title")?,
            description: row.try_get("description")?,
            status: row.try_get("status")?,
        })
    }
}

pub async fn fetch_all_todos(pool: &Pool<MySql>) -> Result<Vec<Task>, String> {
    let response = sqlx::query(
        r#"
      SELECT * FROM tasks
    "#,
    )
    .map(|row| Task::from_row(&row).unwrap())
    .fetch_all(pool)
    .await
    .map_err(|e| e.to_string())?;

    Ok(response)
}

pub async fn add_new_task(pool: &Pool<MySql>, title: String, description: String)->Result<Task, String>{
    let insert_result = sqlx::query(
        r#"INSERT INTO tasks (title, description) values(?, ?)"#
    )
    .bind(title)
    .bind(description)
    .execute(pool)
    .await
    .map_err(|e| e.to_string())?; 

    let id = insert_result.last_insert_id() as i32;
    let inserted_row = sqlx::query(
        r#"
            SELECT * FROM tasks WHERE id=?   
        "#
    )
    .bind(id)
    .map(|row| Task::from_row(&row).unwrap())
    .fetch_one(pool)
    .await
    .map_err(|e| e.to_string())?;
    Ok(inserted_row)
}

pub async fn update_status(pool: &Pool<MySql>, task_id: i32, status: &str)->Result<(), String>{
    let update_result = sqlx::query(
        r#"UPDATE tasks SET status=? WHERE id=?"#
    )
    .bind(status)
    .bind(task_id)
    .execute(pool)
    .await
    .map_err(|e| e.to_string())?;

    let affected_rows = update_result.rows_affected();
    if affected_rows < 1{
        return Err("Unable to update the task".to_string());
    }
    Ok(())
}
pub async fn delete_task(pool: &Pool<MySql>, task_id:i32) -> Result<(), String>{
    let delete_result = sqlx::query(
        r#"DELETE FROM tasks WHERE id=?"#
    )
    .bind(task_id)
    .execute(pool)
    .await
    .map_err(|e| e.to_string())?;

    let affected_rows = delete_result.rows_affected();
    if affected_rows < 1{
        return Err("Unable to delete the task".to_string());
    }
    Ok(())
}
