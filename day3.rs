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
    let mut sum1 = 0;

    let mut seq = String::new();
    // let mut mul1: i8 = 0; //said it only goes up to three digits
    let mut mul1str = String::new();
    let mut mul2str = String::new();

    for c in s.chars(){
        // println!("{}", c);
        if c == 'm' { seq.push('m'); }
        else if c == 'u' && seq == "m" { seq.push(c); }
        else if c == 'l' && seq == "mu" { seq.push(c); }
        else if c == '(' && seq == "mul" { seq.push(c); }
        else if c.is_digit(10) && seq == "mul(" { mul1str.push(c); }
        else if c == ',' && seq == "mul(" { seq.push(c); }
        else if c.is_digit(10) && seq == "mul(," { mul2str.push(c); }
        else if c == ')' && seq == "mul(," { 
            seq.push(c); //for my sanity
            println!("{}, {}, {}", seq, mul1str, mul2str);
            sum1 = sum1 + (mul1str.parse::<i32>().unwrap() * mul2str.parse::<i32>().unwrap());
            seq.clear(); 
            mul1str.clear();
            mul2str.clear();
        }
        else { 
            seq.clear(); 
            mul1str.clear();
            mul2str.clear();
        }
    }
    
    println!("{}", sum1);
}

//garbage collection
// for i in 0..s.len(){
    //     let mut sub = &s[i..];
    //     match sub.find("mul"){
    //         Some(i) => {},
    //         None => break,
    //     };
    //     println!("{}", sub);
    // }