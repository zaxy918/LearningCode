package main

import (
	"fmt"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqt negative number: %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		var e ErrNegativeSqrt = ErrNegativeSqrt(x)
		return 0, e
	}
	z := 10.0
	var pre float64 = 0
	for pre-z > 0.000000000000001 || z-pre > 0.000000000000001 {
		pre = z
		z -= (z*z - x) / (2 * z)
	}
	return z, nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
