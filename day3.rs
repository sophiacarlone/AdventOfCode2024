use std::fs::File;
use std::path::Path;
use std::io::prelude::*;

fn main(){
    //open file
    let path = Path::new("input.txt");
    let display = path.display(); //helps prints paths with format!
    let mut file = match File::open(&path){
        Err(e) => panic!("file cannot open {}: {}", display, e),
        Ok(file) => file,
    };
    let mut s = String::new();
    match file.read_to_string(&mut s){
        Err(e) => panic!("{}", e),
        Ok(_) => println!("file is: {}", s), //get rid of this later
    };

    //part 1
    for c in s.chars(){
        println!("{}", c);
    }

    let sum1 = 0;
    println!("{}", sum1);
}