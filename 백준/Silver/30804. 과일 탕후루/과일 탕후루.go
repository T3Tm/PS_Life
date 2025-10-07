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

func max(a, b int) int{
	if a > b {
		return a
	}
	return b
}
func main(){
	defer writer.Flush()
	var n int
	fmt.Fscanln(reader, &n)

	var slices = make([]int, n)
	for i := range slices{
		fmt.Fscan(reader, &slices[i])
	}
	//1. 종류를 2개로 고정하면서
	//2. 숫자를 계속해서 넣어주기
	//3. 

	var category = make(map[int]int)

	//key가 2개가 유지가 되게끔 계속해서 추가
	var front int = 0
	var total int = 0//현재 총 갯수
	var maxi_total int = 0
	for _, value := range slices{
		total++
		category[value]++
		//키 갯수 세기
		key_count := len(category)
		for key_count > 2{
			front_value := slices[front]
			category[front_value]--
			total--
			if category[front_value] == 0{
				delete(category, front_value)
			}
			key_count = len(category)
			front++
		}
		maxi_total = max(maxi_total, total)
	}

	fmt.Fprintln(writer, maxi_total)
}