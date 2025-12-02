package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	n, m   int
	sit    [12][1 << 11]bool

	dp        [11][1 << 11]int       //i행에서 j모양으로 앉아 있을 때
	colChk    [1 << 11]bool          //행에서 j모양일 때 가능한지 판별
	rowChk    [1 << 11][1 << 11]bool //i행에서 j모양이고, i + 1에서 j모양일 때 가능한지 판별
	bitCnt    [11][1 << 11]int       //x행에 j모양으로 앉는다면 몇 개를 더해야되는지
	initValue = -1
)

func reset() {
	for i := 0; i < n; i++ {
		for j := 0; j < (1 << m); j++ {
			dp[i][j] = initValue
			bitCnt[i][j] = 0
			sit[i][j] = true
		}
	}
}

func dfs(x, y int) int {
	if x == n {
		return 0
	}

	if dp[x][y] != initValue {
		return dp[x][y]
	}
	for i := 0; i < (1 << m); i++ {
		if !sit[x][i] || colChk[i] || rowChk[y][i] {
			continue
		}
		dp[x][y] = max(dp[x][y], dfs(x+1, i)+bitCnt[x][i])
	}
	return dp[x][y]
}

func main() {
	defer writer.Flush()
	//DP 10칸일 때 비트 세주기
	//
	for i := 1; i < (1 << 11); i++ {
		var failNumber = 0b0011
		for j := 0; j < 10; j++ {
			if i&failNumber == failNumber {
				colChk[i] = true //불가능한 방법
			}
			failNumber <<= 1
		}
	}

	for i := 1; i < (1 << 11); i++ {
		if colChk[i] {
			continue
		}
		for j := 1; j < (1 << 11); j++ {
			if colChk[j] {
				continue
			}
			var (
				Chk1 = 0b0010
				Chk2 = 0b0001
			)

			for z := 0; z < 9; z++ {
				if i&Chk1 == Chk1 && j&Chk2 == Chk2 {
					rowChk[i][j] = true
					break
				}
				if i&Chk2 == Chk2 && j&Chk1 == Chk1 {
					rowChk[i][j] = true
					break
				}
				Chk1 <<= 1
				Chk2 <<= 1
			}
		}
	}

	var c int
	for fmt.Fscanf(reader, "%d ", &c); c > 0; c-- {
		fmt.Fscanf(reader, "%d %d ", &n, &m)
		reset() //DP 벨류 리셋
		for i := 0; i < n; i++ {
			var line string
			fmt.Fscanf(reader, "%s ", &line)
			for z := 1; z < (1 << m); z++ {
				for j := 0; j < m; j++ {
					if line[m-1-j] == 'x' && (z&(1<<j) > 0) {
						sit[i][z] = false
					}
				}
			}

		}
		for i := 0; i < n; i++ {
			for j := 1; j < (1 << m); j++ {
				for z := 0; z < m; z++ {
					if j&(1<<z) > 0 && sit[i][j] {
						bitCnt[i][j]++
					}
				}
			}
		}
		fmt.Fprintln(writer, dfs(0, 0))
	}
}
