use sqlx::{mysql::MySqlPoolOptions, Pool, MySql};
use std::error::Error;

pub async fn connect() -> Result<Pool<MySql>, Box<dyn Error>>{
  let pool = MySqlPoolOptions::new()
  .max_connections(5)
  .connect("mysql://root:Suraj@123@localhost:3306/cli_todo")
  .await?;
  Ok(pool)
}

pub async fn setup(pool:&Pool<MySql>) -> Result<(), Box<dyn Error>>{
  sqlx::query(
    r#"
      CREATE TABLE IF NOT EXISTS tasks(
        id INT PRIMARY KEY AUTO_INCREMENT,
        title VARCHAR(255) NOT NULL,
        description TEXT,
        status ENUM('Pending', 'Completed')  DEFAULT 'Pending' 
      )
    "#
  ).execute(pool)
  .await?;

  Ok(())
}