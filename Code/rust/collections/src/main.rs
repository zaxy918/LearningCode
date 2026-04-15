use rand::Rng;
use std::collections::HashMap;

fn median_and_mode() {
    // Arrays with 100 random values from 0 to 100
    let mut arr = Vec::new();
    for _ in 0..100 {
        arr.push(rand::thread_rng().gen_range(0..=100));
    }
    // for i in 0..100 {
    //     println!("arr[{}] = {}", i, arr[i]);
    // }
    // sort the array
    arr.sort();
    // print the median
    println!("The median is {}", arr[arr.len() / 2]);
    // count the mode
    let mut cnt_map = HashMap::new();
    for num in arr {
        *cnt_map.entry(num).or_insert(0) += 1;
    }
    let mut mode = 0;
    for (num, cnt) in cnt_map {
        mode = if cnt > mode { num } else { mode };
    }
    println!("The mode is {}", mode);
}

fn pig_latin(s: &str) -> String {
    if s.is_empty() {
        return String::new();
    } else {
        let first_char = s.chars().next().unwrap();
        if "aeiouAEIOU".contains(first_char) {
            return format!("{}-hay", s);
        } else {
            let rest = &s[first_char.len_utf8()..];
            return format!("{}-{}ay", rest, first_char);
        }
    }
}
fn main() {
    median_and_mode();
    println!("{}", pig_latin("apple"));
    println!("{}", pig_latin("banana"));
}
