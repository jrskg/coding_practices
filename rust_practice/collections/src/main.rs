use std::collections::HashMap;

trait Summary {
    fn summarize(&self) -> String {
        return "This is a default implementation of summarize function".to_string();
    }
    fn get_name(&self) -> &String;
    fn set_name(&mut self, name: String);
    fn get_age(&self) -> u32;
    fn set_age(&mut self, age: u32);
}

struct User {
    name: String,
    age: u32,
}

impl Summary for User {
    fn summarize(&self) -> String {
        format!("The name is {} and the age is {}.", self.name, self.age)
    }
    fn get_name(&self) -> &String {
        return &self.name;
    }
    fn set_name(&mut self, name: String) {
        self.name = name;
    }
    fn get_age(&self) -> u32 {
        self.age
    }
    fn set_age(&mut self, age: u32) {
        self.age = age;
    }
}

fn main() {
    // let vec = vec![1, 2, 3, 4, 5, 6];
    // let evens = get_evens(&vec);
    // println!("{:?}", evens);

    // h_map_example();
    // let arr = vec![(String::from("suraj"), 23), (String::from("arun"), 22), (String::from("rahul"), 20)];
    // let created_map = get_hash_map(&arr);

    // println!("{:?}", created_map);

    // iterator_example();
    // map_filter_example();

    let mut u = User {
        name: String::from("Suraj Gupta"),
        age: 22,
    };
    println!("{}", u.summarize());
    println!("{}", u.get_name());
    println!("{}", u.get_age());
    u.set_name(String::from("Okay Gupta"));
    u.set_age(25);
    println!("{}", u.summarize());
    println!("{}", u.get_name());
    println!("{}", u.get_age());

    trait_as_args(&u);

    let ans;
    let s1 = String::from("small");
    {
        let s2 = String::from("longer");
        ans = lifetime_example(&s1, &s2);
        println!("{}", ans);
    }
    // println!("{}", ans);
}

fn lifetime_example<'a>(str1: &'a str, str2: &'a str) -> &'a str {
    if str1.len() < str2.len() {
        return str2;
    }
    str1
}

fn trait_as_args(item: &impl Summary) {
    println!("{}", item.summarize());
}

fn _map_filter_example() {
    let v1 = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    let only_odds = v1.iter().filter(|x| *x % 2 == 1).map(|x| x * 2);
    let new_vec: Vec<i32> = only_odds.collect();
    // for num in only_odds{
    //   println!("{}", num);
    // }
    println!("{:?}", new_vec);
}

fn _get_evens(vec: &Vec<i32>) -> Vec<i32> {
    let mut ans: Vec<i32> = Vec::new();
    for num in vec {
        if num % 2 == 0 {
            ans.push(*num);
        }
    }
    ans
}

fn _h_map_example() {
    let mut my_map = HashMap::new();
    my_map.insert(String::from("suraj"), 23);
    my_map.insert(String::from("arun"), 22);
    my_map.insert(String::from("rahul"), 20);

    match my_map.get("arun") {
        Some(age) => println!("{}", age),
        None => println!("Arun name not fount"),
    };
}

fn _get_hash_map(arr: &Vec<(String, i32)>) -> HashMap<String, i32> {
    let mut ans = HashMap::new();
    for (first, second) in arr {
        ans.insert(String::from(first), *second);
    }
    ans
}

fn _iterator_example() {
    let arr = vec![1, 2, 3, 4, 5, 6];
    // let itr = arr.iter();

    // for n in itr{
    //   println!("Got {}", n);
    // }

    // let mut mut_itr = arr.iter_mut();

    // for n in mut_itr{
    //   *n = *n + 1;
    // }

    let mut itr = arr.iter();

    while let Some(val) = itr.next() {
        println!("{}", val);
    }

    println!("{:?}", arr);
}
