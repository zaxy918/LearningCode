struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn from(width: u32, height: u32) -> Rectangle {
        println!("A rectagnle width{width}, height{height} is created");
        Rectangle { width, height }
    }

    fn is_contain(&self, other: &Rectangle) -> bool {
        self.width >= other.width && self.height >= other.height
    }
}

fn main() {
    let rec1 = Rectangle::from(3, 5);
    let rec2 = Rectangle::from(6, 9);
    println!(
        "Is rec1 ({},{}) contains rec2 ({},{})? {}",
        rec1.width,
        rec1.height,
        rec2.width,
        rec2.height,
        rec1.is_contain(&rec2)
    );
}
