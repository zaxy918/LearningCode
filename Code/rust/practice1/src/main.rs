fn main() {
    let mut s1 = String::from("Hello");
    s1.push_str(", Rust!");
    println!("{s1}");
    let s2 = "你好，Rust世界！";
    // Print 你好
    println!("{}", &s2[..6]);
    // Print Rust世界
    println!("{}", &s2[9..]);
}
