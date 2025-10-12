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

type MyArray struct {
	left, right int
}
type data struct {
	idx, value, left int
}

type stack struct {
	size     int
	elements []data
}

func (s *stack) append(data data) {
	s.elements = append(s.elements, data)
	s.size++ //사이즈 키우기
}

func (s *stack) pop() data {
	s.size--
	top := s.elements[s.size]
	s.elements = s.elements[:s.size]
	return top
}

func (s *stack) top() data {
	return s.elements[s.size-1]
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	defer writer.Flush()
	var n int

	fmt.Fscanf(reader, "%d ", &n)
	var ary = make([]int, n)
	for i := range ary {
		fmt.Fscanf(reader, "%d ", &ary[i])
	}
	var array = make([]MyArray, n) //ary에 맞는 left, right 남기기
	var now = new(stack)
	for idx, value := range ary {
		for now.size > 0 && now.top().value > value {
			top := now.pop()
			array[top.idx].right = idx - 1
		}
		now.append(data{idx, value, -1})
	}
	for now.size > 0 {
		top := now.pop()
		array[top.idx].right = n - 1
	}
	//뒤에서부터 앞으로 ㄱㄱ
	for idx := n - 1; idx >= 0; idx-- {
		value := ary[idx]
		for now.size > 0 && now.top().value > value {
			top := now.pop()
			array[top.idx].left = idx + 1
		}
		now.append(data{idx, value, -1})
	}
	for now.size > 0 {
		top := now.pop()
		array[top.idx].left = 0
	}

	//array에 저장 끝
	//prefix_sum
	var prefix_sum = make([]int64, n+1)
	for i := 1; i <= n; i++ {
		prefix_sum[i] = prefix_sum[i-1] + int64(ary[i-1])
	}

	/*
		1. for문으로 돈다.
		2. 해당 idx에 최대로 벌려질 수 있는 left, right를 구한다.
		3. 해당 누적합을 이용하여 정답을 도출
	*/
	var answer int64 = 0
	for idx, value := range ary {
		//value는 min값
		sum := prefix_sum[array[idx].right+1] - prefix_sum[array[idx].left]
		answer = max(answer, sum*int64(value))
	}

	fmt.Fprintln(writer, answer)

	//자신이 최대로 있을 수 있는 idx
	//for idx, value := range array {
	//	fmt.Fprintf(writer, "idx : %d left : %d right : %d\n", idx, value.left, value.right)
	//}
}
