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

var (
	data []int
	tree []int
)

func findCloseBinary(n int) int{
	ret := 1
	for n > 0{
		ret <<= 1 
		n >>= 1
	}
	ret <<= 1
	return ret
}
//tree는 홀수의 개수
func build(l, r, node int) int{
	if l == r{
		tree[node] = data[l]&1
		return tree[node]
	}
	mid := (l + r) >> 1
	tree[node] = build(l, mid, node << 1) + build(mid + 1, r, node << 1 | 1)
	return tree[node]
}

func update(l, left, right, node, value int) int{
	if l < left || right < l{
		return tree[node]
	}
	if l <= left && right <= l{
		tree[node] = value&1
		return tree[node]
	}
	mid := (left + right) >> 1
	tree[node] = update(l, left, mid, node << 1, value) + update(l, mid + 1, right, node << 1 | 1, value)
	return tree[node]
}

func query(l, r, left, right, node int) int{
	if r < left || right < l{
		return 0
	}
	if l <= left && right <= r{
		return tree[node]
	}
	mid := (left + right) >> 1
	return query(l, r, left, mid, node << 1) + query(l, r, mid + 1, right, node << 1 | 1)
}

func main(){
	defer writer.Flush()
	var n int
	fmt.Fscanf(reader, "%d ", &n)
	data = make([]int, n + 2)
	for i:=1; i <= n; i++{
		fmt.Fscanf(reader, "%d ", &data[i])
	}
	
	size := findCloseBinary(n)
	tree = make([]int, size)

	build(1, n, 1)//만들기

	var m int
	for fmt.Fscanf(reader, "%d ", &m);m > 0;m--{
		var cmd, l, r int
		fmt.Fscanf(reader, "%d %d %d ", &cmd, &l, &r)

		switch cmd{
		case 1:
			update(l, 1, n, 1, r)
		case 2:
			ret := query(l, r, 1, n, 1)
			fmt.Fprintln(writer, r - l - ret + 1)
		case 3:
			ret := query(l, r, 1, n, 1)
			fmt.Fprintln(writer, ret)
		}
	}
}