package main

import (
	"fmt"
	"math"
)

type Shape interface {
	Area() float64
	Perimeter() float64
}

type Rectangle struct {
	Width  float64
	Height float64
}

func (r Rectangle) Area() float64 {
	return r.Height * r.Width
}

func (r Rectangle) Perimeter() float64 {
	return 2 * (r.Height + r.Width)
}

type Circle struct {
	Radius float64
}

func (c Circle) Area() float64 {
	return 2 * math.Pi * c.Radius * c.Radius
}

func (c Circle) Perimeter() float64 {
	return 2 * math.Pi * c.Radius
}
func InterfaceDriver() {
	var s Shape = Rectangle{
		Width:  2,
		Height: 4,
	}
	fmt.Println("Area of Rectangle", s.Area())
	fmt.Println("Perimeter of Rectangle", s.Perimeter())

	s = Circle{
		Radius: 2,
	}
	fmt.Println("Area of Circle", s.Area())
	fmt.Println("Perimeter of Circle", s.Perimeter())

}
