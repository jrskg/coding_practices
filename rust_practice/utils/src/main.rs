fn main() {
    let a: i8 = 90;
    let b: u32 = 32;
    let c = 100.091;

    println!("a : {} b : {} c : {}", a, b, c);
    //    example();
    // example_string();

    // let sentence = String::from("This is a string");
    // let first_word = get_first_word(sentence);
    // println!("{}", first_word);

    // for_loop_example();

    // let my_str = String::from("This is a string");
    // okay(my_str);
    // let my_str2 = my_str;
    // println!("{}",my_str);

    let mut s1 = String::from("Hello ");
    let s2 = &mut s1;
    // println!("{}", s2);
    s2.push_str("Ok");
    // okay(&s1);
    borrow_str(&mut s1);
    borrow_str(&mut s1);
    // okay(&s1);
    // okay(&s1);
    // okay(&s1);
    println!("{}", s1);
}

fn borrow_str(s:&mut String){
    s.push_str("World");
}

fn okay(s:&String){
    println!("{}", s);
}

fn _example() {
    let is_male = true;
    let is_above_18 = true;

    if is_male {
        println!("You are a male");
    } else {
        println!("You are not a male");
    }

    if is_above_18 && is_male {
        println!("You are a legal male");
    }
}

fn _example_string() {
    let greet = String::from("Welcome");
    let char1 = greet.chars().nth(0);
    
    match char1 {
        Some(c) => println!("{}", c),
        None => println!("No character at that index")
    };
}

fn _get_first_word(sentence:String) -> String {
    let mut word = String::from("");
    for char in sentence.chars(){
        if char == ' '{
            break;
        }
        word.push(char);
    }
    word
}

fn _for_loop_example(){
    let n = 11;
    for i in 0..n{
        println!("{}", i);
    }

    let mut i = 0;
    while i < n{
        println!("{}", i);
        i += 1
    }
}
