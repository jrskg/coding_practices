package main

import "fmt"

type Paymenter interface {
	Pay(amount float64) error
	Refund(amount float64) error
}

type CreditCard struct{}

func (c CreditCard) Pay(amount float64) error {
	fmt.Println("Paid", amount, "using Credit Card")
	return nil
}

func (c CreditCard) Refund(amount float64) error {
	fmt.Println("Refund", amount, "using Credit Card")
	return nil
}

type PayPal struct{}

func (p PayPal) Pay(amount float64) error {
	fmt.Println("Paid", amount, "using PayPal")
	return nil
}

func (p PayPal) Refund(amount float64) error {
	fmt.Println("Refund", amount, "using PayPal")
	return nil
}

type BankTransfer struct{}

func (b BankTransfer) Pay(amount float64) error {
	fmt.Println("Paid", amount, "using Bank Transfer")
	return nil
}

func (b BankTransfer) Refund(amount float64) error {
	fmt.Println("Refund", amount, "using Bank Transfer")
	return nil
}

type PaymentGateway struct {
	Gateway Paymenter
}

func PaymentSystem() {
	cc := CreditCard{}
	p := PaymentGateway{
		Gateway: cc,
	}
	p.Gateway.Pay(1000)
	p.Gateway.Refund(1000)

	pp := PayPal{}
	p = PaymentGateway{
		Gateway: pp,
	}

	p.Gateway.Pay(2000)
	p.Gateway.Refund(1000)

	bt := BankTransfer{}
	p = PaymentGateway{
		Gateway: bt,
	}
	p.Gateway.Pay(3000)
	p.Gateway.Refund(2000)

	payments := []Paymenter{cc, pp, bt}

	for _, payment := range payments {
		payment.Pay(3000)
		payment.Refund(2000)
	}
}
