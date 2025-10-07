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

	var m, n int64
	fmt.Fscanln(reader, &m, &n)

	var slices []int = make([]int, n)
	for i := range slices{
		fmt.Fscan(reader, &slices[i])
	}

	var left, right int64 = 1, 1e15 + 1

	for left <= right{
		var mid int64 = (left + right) >> 1//현재 과자의 길이

		var count int64 = 0//mid로 잘랐을 시 과자의 갯수
		
		for _, value := range slices{
			count += int64(value) / mid
		}

		if count < m{
			right = mid - 1
		}else{
			left = mid + 1
		}
	}
	fmt.Fprintln(writer, right)
	
}