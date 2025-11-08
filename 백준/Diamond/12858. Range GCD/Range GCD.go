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

type tuple struct {
	gcd   int64
	last  int64
	total int64
}

var (
	tree []tuple
	lazy []int64
	data []int
)

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return abs(a)
	} else if a == 0 {
		return abs(b)
	}

	if abs(a) >= abs(b) {
		return gcd(abs(b), abs(a)%abs(b))
	}
	return gcd(abs(a), abs(b)%abs(a))
}

func build(left, right, node int) {
	if left == right {
		tree[node] = tuple{
			0, int64(data[left]), int64(data[left]),
		}
		return
	}
	mid := (left + right) >> 1
	build(left, mid, node<<1)
	build(mid+1, right, node<<1|1)

	tree[node] = tuple{
		gcd(gcd(tree[node<<1].gcd, tree[node<<1|1].gcd), abs(tree[node<<1|1].last-tree[node<<1].last)),
		max(tree[node<<1].last, tree[node<<1|1].last),
		tree[node<<1].total + tree[node<<1|1].total,
	}
}

// Arr[i : j] + value
func update(i, j, left, right, node, value int) {
	propagation(left, right, node)
	if right < i || j < left {
		return
	}

	//구간에 정확히 들어왔을 때
	if i <= left && right <= j {
		lazy[node] += int64(value)     //현재 업데이트해야 되는 값
		propagation(left, right, node) //일단 퍼트리기
		return
	}
	mid := (left + right) >> 1
	update(i, j, left, mid, node<<1, value)
	update(i, j, mid+1, right, node<<1|1, value)
	tree[node] = tuple{
		gcd(gcd(tree[node<<1].gcd, tree[node<<1|1].gcd), abs(tree[node<<1|1].last-tree[node<<1].last)),
		max(tree[node<<1].last, tree[node<<1|1].last),
		tree[node<<1].total + tree[node<<1|1].total,
	}
}

func query(i, j, left, right, node int) int64 {
	propagation(left, right, node)
	if right < i || j < left {
		return 0
	}

	if i <= left && right <= j {
		return gcd(tree[node].gcd, tree[node].last)
	}

	mid := (left + right) >> 1
	front := query(i, j, left, mid, node<<1)
	back := query(i, j, mid+1, right, node<<1|1)
	return gcd(front, back)
}

func propagation(left, right, node int) {
	//
	if lazy[node] == 0 {
		return
	}
	//내가 마지막 자식이라면 더이상 퍼트리기 안 해도 된다.
	//현재 node에다가 right - left 만큼 더해주고
	tree[node].total += lazy[node] * int64(right-left+1)
	tree[node].last += lazy[node]
	//같지 않다는 것은 퍼트릴 것이 있단느 것
	if left != right {
		lazy[node<<1] += lazy[node]
		lazy[node<<1|1] += lazy[node]
	}
	lazy[node] = 0
}

func findCloseBinary(number int) (ret int) {
	ret = 2
	for number > 0 {
		ret <<= 1
		number >>= 1
	}
	return
}

func main() {
	defer writer.Flush()
	var n, q int
	fmt.Fscanf(reader, "%d ", &n)

	size := findCloseBinary(n)

	//fmt.Fprintln(writer, size)
	tree = make([]tuple, size)
	lazy = make([]int64, size)
	data = make([]int, n+2)

	for i := 1; i <= n; i++ {
		fmt.Fscanf(reader, "%d ", &data[i])
	}
	build(1, n, 1)

	//for i := 1; i < size; i++ {
	//	fmt.Fprintln(writer, "i : ", i, "gcd : ", tree[i].gcd)
	//}

	fmt.Fscanf(reader, "%d ", &q)
	for ; q > 0; q-- {
		var t, a, b int
		fmt.Fscanf(reader, "%d %d %d ", &t, &a, &b)
		if t == 0 {
			ret := query(a, b, 1, n, 1)
			fmt.Fprintln(writer, ret)
		} else {
			update(a, b, 1, n, 1, t)
		}
		//fmt.Fprintln(writer, "q : ", q)
		//for i := 1; i < size; i++ {
		//	fmt.Fprintln(writer, "i : ", i, "gcd : ", tree[i].gcd, "total : ", tree[i].total)
		//}
		//fmt.Fprintln(writer, "-------")
	}
}
