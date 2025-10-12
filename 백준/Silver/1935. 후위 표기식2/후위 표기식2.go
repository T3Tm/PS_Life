package main

//후위 표기식?
import (
	"bufio"
	"fmt"
	"os"
)
var (
	reader = bufio.NewReader(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

func main(){
	defer writer.Flush()
	var n int
	var lines string
	fmt.Fscanln(reader, &n)
	fmt.Fscanln(reader, &lines)
	
	var trans map[int]float64 = make(map[int]float64)

	for i, tmp := 0, 0; i<n;i++{
		fmt.Fscan(reader, &tmp)
		trans[i+65] = float64(tmp)
	}

	//fmt.Fprintln(writer, trans)

	//1. 후위표기식은 
	//2. 스택으로 해결하면 됨.
	//3. 숫자, 숫자, 곱셈이면 곱셈하면 됨.
	//result := 0.

	stack := make([]float64, 0)
	for _, value := range lines{
		if values, ok := trans[int(value)]; ok{
			stack = append(stack, float64(values))
			continue
		}
		a, b := stack[len(stack) - 1], stack[len(stack) - 2]
		stack = stack[:len(stack) - 2]
		c := 0.
		//fmt.Fprintln(writer, c)
		switch value{
		case '*':
			c = a * b
		case '-':
			c = b - a
		case '/':
			c = b / a
		case '+':
			c = a + b
		}
		//fmt.Fprintln(writer, c)
		stack = append(stack, c)
	}

	fmt.Fprintf(writer, "%.2f", stack[len(stack) - 1])
}