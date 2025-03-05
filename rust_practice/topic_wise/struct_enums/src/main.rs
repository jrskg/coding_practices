struct Person {
    name: String,
    age: u8,
}
impl Person {
    fn is_adult(&self) -> bool {
        self.age >= 18
    }
    fn change_name(&mut self, name: String) {
        self.name = name;
    }
}

struct Point(f32, f32);

struct Logger;
impl Logger {
    fn log(message: &str) {
        println!("{}", message);
    }
}

struct Rectangle {
    width: u32,
    height: u32,
}
impl Rectangle {
    fn new(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }
    fn area(&self) -> u32 {
        self.width * self.height
    }
    fn is_square(&self) -> bool {
        self.width == self.height
    }
    fn scale(&mut self, factor: u32) -> Result<(), String> {
        if factor > 1 {
            self.width = self.width * factor;
            self.height = self.height * factor;
            return Ok(());
        }

        Err(String::from("Invalid factor valur given"))
    }
}

enum TrafficLight {
    Red,
    Yellow,
    Green,
}
impl TrafficLight {
    fn duration(light: TrafficLight) -> u8 {
        match light {
            TrafficLight::Red => 60,
            TrafficLight::Yellow => 10,
            TrafficLight::Green => 30,
        }
    }
}

enum Shape {
    Circle(f32),
    Rectangle(f32, f32),
}
impl Shape {
    fn area(&self) -> f32 {
        match self {
            Shape::Circle(radius) => 3.14 * radius * radius,
            Shape::Rectangle(width, height) => width * height,
        }
    }
}

enum Message {
    Text(String),
    Move(i32, i32),
    Quit,
    ChangeColor(i32, i32, i32),
}
impl Message {
    fn print_message(&self) {
        match self {
            Message::Text(text) => println!("{}", text),
            Message::Move(x, y) => println!("Move to x: {}, y: {}", x, y),
            Message::Quit => println!("Quit"),
            Message::ChangeColor(a, b, c) => {
                println!("Change color to R: {}, G: {}, B: {}", a, b, c)
            }
        }
    }
}

enum VehicleType {
    Car,
    Bike,
    Truck,
}
struct Vehicle {
    vehicle_type: VehicleType,
    brand: String,
    model: String,
    year: u16,
}
impl Vehicle {
    fn get_details(&self) {
        let type_str = match self.vehicle_type {
            VehicleType::Bike => "Bike",
            VehicleType::Car => "Car",
            VehicleType::Truck => "Truck",
        };
        println!("Brand: {}", self.brand);
        println!("Model: {}", self.model);
        println!("Vehicle Type: {}", type_str);
        println!("Year: {}", self.year);
    }
}

enum AccountType{
    Savings,
    Checking
}
struct BankAccount{
    account_number: u32,
    balance: f64,
    account_type: AccountType
}
impl BankAccount{
    fn deposit(&mut self, amount: f64){
        if amount > 0.0{
            self.balance += amount;
        }
    }
    fn withdraw(&mut self, amount: f64) -> Result<f64, String>{
        if amount <= 0.0{
            return Err(String::from("Invalid amount"));
        }
        if amount > self.balance{
            return Err(String::from("Insufficient balance"));
        }
        self.balance -= amount;
        Ok(amount)
    }
    fn get_account_details(&self){
        let account_type = match self.account_type {
            AccountType::Checking => "Checking",
            AccountType::Savings => "Savings"
        };
        println!("Account Number: {}", self.account_number);
        println!("Account Type: {}", account_type);
        println!("Balance: {}", self.balance);
    }
}

fn main() {
    let mut person = Person {
        name: String::from("Suraj Gupta"),
        age: 21,
    };

    println!("Name: {}", person.name);
    println!("Age: {}", person.age);

    let ok = Person::is_adult(&person);
    println!("Is Adult: {}", ok);

    if person.is_adult() {
        println!("{} is an adult", person.name);
    } else {
        println!("{} is not an adult", person.name);
    }

    println!("Changing name...");
    person.change_name(String::from("JR_SKG"));
    println!("Name after change: {}", person.name);

    let rect = Point(3.0, 4.0);
    println!("x: {}, y: {}", rect.0, rect.1);

    Logger::log("Hi i am from Logger struct.");

    let mut rect2 = Rectangle::new(10, 30);
    println!("Area: {}", rect2.area());
    let _ = rect2.scale(2).unwrap();
    println!("Area after scale: {}", rect2.area());
    if rect2.is_square() {
        println!("This is a square.");
    }

    println!(
        "Duration of red light: {}",
        TrafficLight::duration(TrafficLight::Red)
    );
    println!(
        "Duration of yellow light: {}",
        TrafficLight::duration(TrafficLight::Yellow)
    );
    println!(
        "Duration of green light: {}",
        TrafficLight::duration(TrafficLight::Green)
    );

    let circle = Shape::Circle(3.0);
    println!("Area of circle : {}", circle.area());

    let rect3 = Shape::Rectangle(3.5, 5.4);
    println!("Area of Reactangle: {}", rect3.area());

    let text = Message::Text(String::from("A text from Text enum variant"));
    text.print_message();

    let move_message = Message::Move(10, 6);
    move_message.print_message();

    let quit = Message::Quit;
    quit.print_message();

    let chnage_color = Message::ChangeColor(256, 256, 256);
    chnage_color.print_message();

    let my_vehicle = Vehicle {
        brand: String::from("Toyato"),
        model: String::from("A model"),
        year: 2025,
        vehicle_type: VehicleType::Car,
    };

    my_vehicle.get_details();

    let mut acc = BankAccount{
        account_number: 123456,
        balance: 1000000.0,
        account_type: AccountType::Savings
    };
    acc.get_account_details();
    acc.deposit(100000.0);
    acc.get_account_details();
    let _ = acc.withdraw(50000.0).unwrap();
    acc.get_account_details();
}
