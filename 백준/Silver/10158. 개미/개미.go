package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)
func main(){
	defer writer.Flush()
	var w, h int64	
	var p, q int64
	var plus int64
	fmt.Fscanln(reader, &w, &h)
	fmt.Fscanln(reader, &p, &q)
	fmt.Fscanln(reader, &plus)

	div_w := (p + plus) / w
	p = (p + plus) % w

	div_h := (q + plus) / h
	q = (q + plus) % h

	//1, 3, 5라면 거꾸로 
	if div_w % 2 == 1{
		p = w - p
	}
	if div_h % 2 == 1{
		q = h - q
	}

	fmt.Fprintln(writer, p, q)
}