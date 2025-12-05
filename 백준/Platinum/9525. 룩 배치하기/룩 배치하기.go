package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	graph  [][]int
	n      int

	done   []int
	choice []int
)

func match(x, visCnt int) int {
	if done[x] == visCnt {
		return 0
	}
	done[x] = visCnt
	for _, nxt := range graph[x] {
		if choice[nxt] == -1 || match(choice[nxt], visCnt) == 1 {
			choice[nxt] = x
			return 1
		}
	}
	return 0
}

func dfs(x, y int, board []string, visited [][]int, rowCnt int) {
	if y == n {
		return
	}
	if visited[x][y] > 0 || board[x][y] == 'X' {
		return
	}

	visited[x][y] = rowCnt
	dfs(x, y+1, board, visited, rowCnt)
}

func main() {
	defer writer.Flush()

	fmt.Fscanln(reader, &n)

	var board = make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &board[i])
	}

	var visited = make([][]int, n)
	for i := range visited {
		visited[i] = make([]int, n)
	}
	//오른쪽으로만 움직이는 dfs 실시
	var rowCnt = 1
	for i := range board {
		for j := range board[i] {
			if visited[i][j] > 0 || board[i][j] == 'X' {
				continue
			}
			dfs(i, j, board, visited, rowCnt)
			rowCnt++
		}
	}
	//총
	graph = make([][]int, rowCnt) //행 갯수 만큼 col로 가야된다.

	var col = 0
	for j := 0; j < n; j++ {
		//열을 기준으로 행을 돌면서 똑같은 열이라고 처리해주기
		for i := 0; i < n; i++ {
			if board[i][j] == 'X' {
				col++
				continue
			}
			nowRow := visited[i][j]
			graph[nowRow] = append(graph[nowRow], col) //갈 수 있는 경로체크
		}
		col++
	}

	done = make([]int, rowCnt)
	choice = make([]int, col)
	var (
		visCnt = 0
		ans    = 0
	)
	for i := range choice {
		choice[i] = -1
	}

	for i := 0; i < rowCnt; i++ {
		visCnt++
		ans += match(i, visCnt)
	}

	fmt.Fprintln(writer, ans)
}
