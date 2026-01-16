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
7명의 여자
7명은 가로 or 세로 인접
이다솜파의 학생들로만 구성될 필요가 없음

이다솜파 학생이 4명이어야 함.
7자리 뽑는데

서로 가로나 세로로 인접한다?

	      o
		o o o

전체 경우의 수 : 480700

서로 가로나 세로로 인접한다는 말이 무엇일까?
단순히 가로 세로로 연결돼있으면 되는 것 같음.

1. 백트래킹으로 좌표 따기
2. dfs를 통해서 7개 방문 가능한지 확인하기
3. S > Y인지 확인하기
*/
var (
	board    [5]string
	activate [7][7]bool
	visited  [7][7]int

	vis = 1
	dx  = []int{0, 0, 1, -1}
	dy  = []int{1, -1, 0, 0}

	finds = map[uint8]int{'Y': 0, 'S': 0}

	ans int
)

func bactracking(depth, pre int) {
	if depth == 7 {
		var last_activate = pre - 1
		var row = last_activate / 5
		var col = last_activate % 5
		finds['Y'] = 0
		finds['S'] = 0 //초기화

		dfs(row, col) //음 활성화된 마지막 좌표를 pre-1로 알 수 있구나
		vis++
		if finds['Y']+finds['S'] < 7 || finds['Y'] > finds['S'] {
			return
		}
		ans++
		return
	}

	for i := pre; i < 25; i++ {
		var row = i / 5
		var col = i % 5
		activate[row][col] = true
		bactracking(depth+1, i+1)
		activate[row][col] = false
	}
}

func dfs(x, y int) {
	if visited[x][y] == vis {
		return
	}
	visited[x][y] = vis
	finds[board[x][y]]++
	for i := 0; i < 4; i++ {
		var nx = x + dx[i]
		var ny = y + dy[i]
		if nx < 0 || nx >= 5 || ny < 0 || ny >= 5 {
			continue
		}
		if !activate[nx][ny] {
			continue
		}
		dfs(nx, ny)
	}
}

func main() {
	defer writer.Flush()

	for i := 0; i < 5; i++ {
		fmt.Fscanln(reader, &board[i])
	}
	bactracking(0, 0)
	fmt.Fprintln(writer, ans)
}
