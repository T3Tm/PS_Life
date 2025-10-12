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
	tree []int64
)

func findCloseBinary(n int) (ret int){
	ret = 1
	for n > 0{
		n >>= 1
		ret <<= 1
	}
	ret <<= 1
	return
}

func build(left, right, node int) int64{
	if left == right{
		tree[node] = int64(data[left])
		return tree[node]
	}
	mid := (left + right) >> 1
	tree[node] = build(left, mid, node << 1) + build(mid + 1, right, node << 1 | 1)
	return tree[node]
}

func update(l, r, left, right, node, value int) int64{
	if r < left || right < l{
		return tree[node]
	}
	if l <= left && right <= r{
		tree[node] += int64(value)
		return tree[node]
	}
	mid := (left + right) >> 1
	tree[node] = update(l, r, left, mid, node << 1, value) + update(l, r, mid + 1, right, node << 1 | 1, value)
	return tree[node]
}

func query(l, r, left, right, node int) int64{
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
	var n, q int
	fmt.Fscanf(reader, "%d %d ", &n, &q)
	size := findCloseBinary(n)
	data = make([]int, n + 2)
	tree = make([]int64, size)

	//query cnt
	for ;q > 0;q--{
		var cmd, p, q int
		fmt.Fscanf(reader, "%d %d %d ", &cmd, &p, &q)
		//fmt.Fprintf(writer, "cmd : %d p : %d q : %d\n", cmd, p, q)
		

		


		if cmd == 1{
			update(p, p, 1, n, 1, q)
		}else{
			ret := query(p, q, 1, n, 1)
			fmt.Fprintln(writer, ret)
		}

		// fmt.Fprintln(writer, "현재 배열 상태")
		// for _, value := range tree{
		// 	fmt.Fprintf(writer, "%d ", value)
		// }
		// fmt.Fprintln(writer)
	}
	
	
}