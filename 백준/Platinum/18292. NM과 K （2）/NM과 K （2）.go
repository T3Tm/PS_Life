package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader    = bufio.NewReader(os.Stdin)
	writer    = bufio.NewWriter(os.Stdout)
	arr       [][]int
	dp        [12][52][1 << 11]int64
	rowValue  [12][1 << 11]int
	bitCnt    [1 << 11]int
	chk       [1 << 11]bool //불가능한 조합 따로 체크하기
	cchk      [1 << 11][1 << 11]bool
	initValue int64 = -5 * 1e7
	n, m, k   int
)

func dfs(x, y, z int) int64 {
	if x == n {
		if y == k {
			return 0
		}
		return initValue
	}
	//x 행에서 y
	if dp[x][y][z] != initValue {
		return dp[x][y][z]
	}

	for j := 0; j < (1 << m); j++ {
		if k-y < bitCnt[j] || chk[j] || cchk[z][j] {
			continue
		} //더 많게는 비트를 킬 수 없음.
		dp[x][y][z] = max(dp[x][y][z], dfs(x+1, y+bitCnt[j], j)+int64(rowValue[x][j]))
	}
	return dp[x][y][z]
}

func main() {
	defer writer.Flush()
	fmt.Fscanf(reader, "%d %d %d ", &n, &m, &k)
	arr = make([][]int, n)
	for i := range arr {
		arr[i] = make([]int, m)
		for j := range arr[i] {
			fmt.Fscanf(reader, "%d ", &arr[i][j])
		}
	}

	for i := 1; i < (1 << m); i++ { //2^10
		//비트 몇 개 켜져있는지 확인하기
		var cnt = 0
		var failNumber = 0b0011  //
		for j := 0; j < m; j++ { //10
			if i&(1<<j) > 0 {
				cnt++
			}
			if i&failNumber == failNumber {
				chk[i] = true
			}
			failNumber <<= 1 //한 칸씩 쉬프트
		}
		bitCnt[i] = cnt //해당 모양에서는 비트 몇 개 켜져있음.
	}

	for i := 0; i < n; i++ { //10
		for j := 1; j < (1 << m); j++ { //2^10
			var total = 0
			for z := 0; z < m; z++ { //10
				if j&(1<<z) > 0 {
					total += arr[i][m-1-z]
				}
			}
			rowValue[i][j] = total
		}
	}

	for i := 0; i < (1 << m); i++ {
		if chk[i] {
			continue
		}
		for j := 0; j < (1 << m); j++ {
			if chk[j] {
				continue
			}
			//이제 i랑 j가 서로 위아래로 마주치는 순간이 있는지 확인
			for idx := 0; idx < 10; idx++ {
				if i&(1<<idx) > 0 && j&(1<<idx) > 0 {
					cchk[i][j] = true
					break
				}
			}
		}
	}

	//DP[i][j][k] i, j까지 k개를 선택했을 때 최댓값
	for i := 0; i < n; i++ {
		for j := 0; j < k; j++ {
			for z := 0; z < (1 << m); z++ {
				dp[i][j][z] = initValue
			}
		}
	}

	fmt.Fprintln(writer, dfs(0, 0, 0))
}
