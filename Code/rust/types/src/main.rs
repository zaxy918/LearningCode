fn main() {
    let x = 999;
    let y: i64 = 111_222_333;
    let z = 1.99f32;
    println!("x: {x}, y: {y}, z: {z}");

    let tup: (i32, i64, f32) = (x, y, z);
    let (a, b, c) = tup;
    println!("a: {a}, b: {b}, c: {c}");
    println!("tup: ({}, {}, {})", tup.0, tup.1, tup.2);

    let arr = [x, y as i32, z as i32];
    let arr2: [i64; 3] = [89, 111, 222];
    let arr3 = [0; 3]; // Creates an array of 3 elements, all initialized to 0

    let m;
    m = 9;
    println!("m: {m}");
}
