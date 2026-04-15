struct Point<T> {
    x: T,
    y: T,
}
impl<T> Point<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
    fn x(&self) -> &T {
        &self.x
    }
}

impl Point<f64> {
    fn dis_to(&self, other: &Point<f64>) -> f64 {
        let dx = self.x - other.x;
        let dy = self.y - other.y;
        (dx * dx + dy * dy).sqrt()
    }
}

fn main() {
    let p1 = Point::new(1.0, 2.0);
    let p2 = Point::new(4.0, 6.0);
    println!("p1.x = {}", p1.x());
    println!("Distance: {}", p1.dis_to(&p2));
}
