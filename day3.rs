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
    let mut enabled_seq = String::new();
    let mut mul1str = String::new();
    let mut mul2str = String::new();
    let mut enabled = true;

    for c in s.chars(){
        if c == 'm' { seq.push('m'); }
        else if c == 'u' && seq == "m" { seq.push(c); }
        else if c == 'l' && seq == "mu" { seq.push(c); }
        else if c == '(' && seq == "mul" { seq.push(c); }
        else if c.is_digit(10) && seq == "mul(" { mul1str.push(c); }
        else if c == ',' && seq == "mul(" { seq.push(c); }
        else if c.is_digit(10) && seq == "mul(," { mul2str.push(c); }
        else if c == ')' && seq == "mul(," { 
            seq.push(c); //for my sanity
            if enabled {
                sum1 = sum1 + (mul1str.parse::<i32>().unwrap() * mul2str.parse::<i32>().unwrap());
            }
            seq.clear(); 
            mul1str.clear();
            mul2str.clear();
            enabled_seq.clear();
        }
        else if c == 'd' { enabled_seq.push(c); }
        else if c == 'o' && enabled_seq == "d" { 
            enabled_seq.push(c);
            enabled = true; 
        }
        else if c == 'n' && enabled_seq == "do" { enabled_seq.push(c); }
        else if c == '\'' && enabled_seq == "don" { enabled_seq.push(c); }
        else if c == 't' && enabled_seq == "don'" { 
            enabled_seq.push(c);
            enabled = false;
        }
        else { 
            seq.clear(); 
            mul1str.clear();
            mul2str.clear();
            enabled_seq.clear();
        }
    }
    
    println!("{}", sum1);
}