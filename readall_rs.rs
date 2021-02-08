use std::io::{self, Read};

fn main() {
    let mut buffer = Vec::new();
    io::stdin().read_to_end(&mut buffer).unwrap();

    println!("length: {}", buffer.len());
}
