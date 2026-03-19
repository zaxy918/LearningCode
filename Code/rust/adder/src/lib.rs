pub fn add(left: u64, right: u64) -> u64 {
    left + right
}
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle::from(8, 7);
        let smaller = Rectangle::from(5, 1);
        assert!(larger.is_contain(&smaller));
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = Rectangle::from(8, 7);
        let smaller = Rectangle::from(5, 1);
        assert!(!smaller.is_contain(&larger));
    }
}
