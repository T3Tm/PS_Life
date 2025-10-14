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

/*
w, x, y, c
w, x1, y1, x2, y2
w == 0

	(x, y) c arr[x][y] = c
	한 행에서만 진해앟면 되기 때문에
	1024 시복

w == 1

	예를 들어 1차원 prefix
	2차원으로 해놓는다면
	합을 구하는 경우는 O(1)
	1024
*/
func main() {
	defer writer.Flush()
	var n, m int
	fmt.Fscanf(reader, "%d %d ", &n, &m)
	var ary = make([][]int, n)

	var prefix = make([][]int, n+2)

	for i := 0; i < n; i++ {
		ary[i] = make([]int, n)
		prefix[i+1] = make([]int, n+2)
		for j := 0; j < n; j++ {
			fmt.Fscanf(reader, "%d ", &ary[i][j])
		}
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			prefix[i][j] = prefix[i][j-1] + ary[i-1][j-1]
		}
	}

	for ; m > 0; m-- {
		var cmd int
		fmt.Fscanf(reader, "%d ", &cmd)
		switch cmd {
		case 0:
			var x, y, c int
			fmt.Fscanf(reader, "%d %d %d ", &x, &y, &c)
			//해당 값 업데이트
			gap := c - ary[x-1][y-1]
			ary[x-1][y-1] = c //변경
			for col := y; col <= n; col++ {
				prefix[x][col] += gap
			}
		case 1:
			var x1, y1, x2, y2 int
			fmt.Fscanf(reader, "%d %d %d %d ", &x1, &y1, &x2, &y2)
			var answer = 0
			for i := x1; i <= x2; i++ {
				answer += prefix[i][y2] - prefix[i][y1-1]
			}

			fmt.Fprintln(writer, answer)
		}
	}
}
