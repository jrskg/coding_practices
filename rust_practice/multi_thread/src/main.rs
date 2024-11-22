use std::{sync::mpsc, thread, time::Instant};

fn main() {
    let start = Instant::now();
    let total_threads = 5;
    let n = 1000_000_000;   
    let chunk_size = n/total_threads;

    let (tx, rx) = mpsc::channel();

    for i in 0..total_threads{
        let tx = tx.clone();
        let start = i * chunk_size + 1;
        let end = if i == total_threads - 1 {n} else {(i+1)*chunk_size};

        thread::spawn(move || {
            println!("Thread spawning for range [{}, {}]", start, end);
            let partial_sum:u64 = (start..=end).sum();
            tx.send(partial_sum).unwrap();
        });
    }
    drop(tx);

    let mut final_sum:u64 = 0;
    for sum in rx{
        final_sum += sum;
    }
    println!("The final sum is {}", final_sum);
    let dur = start.elapsed();
    println!("{:?}", dur);
}
