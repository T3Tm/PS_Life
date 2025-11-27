package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)

	jobs     [][]int
	done     []int //매칭이 됐는지 확인
	indegree []int //일이 누구와 매칭됐었는지 확인

	visCnt int
)

func dfs(x int) bool {
	if done[x] == visCnt {
		return false
	}

	done[x] = visCnt //해당 애는 매칭됐음
	//dfs가 여기서 한 번만 하는 것이 아니라. 매칭을 두 번 진행하는 것이다.

	for _, next := range jobs[x] {
		if indegree[next] == -1 || dfs(indegree[next]) {
			indegree[next] = x
			return true
		}
	}

	return false
}

func main() {
	defer writer.Flush()
	var n, m int
	fmt.Fscanf(reader, "%d %d ", &n, &m)

	jobs = make([][]int, 2*n)

	for i := 0; i < n; i++ {
		var jobsCnt int
		fmt.Fscanf(reader, "%d ", &jobsCnt)
		jobs[2*i] = make([]int, jobsCnt)
		jobs[2*i+1] = make([]int, jobsCnt)
		for j := 0; j < jobsCnt; j++ {
			fmt.Fscanf(reader, "%d ", &jobs[2*i][j])
			jobs[2*i][j]--
			jobs[2*i+1][j] = jobs[2*i][j]
		}
		//fmt.Fprintln(writer, jobs[i])
	}
	var ans = 0
	indegree = make([]int, m)

	for i := range indegree {
		indegree[i] = -1
	}

	for i := 0; i < 2*n; i++ {
		done = make([]int, 2*n)
		visCnt++
		dfs(i)
	}

	for _, value := range indegree {
		if value > -1 {
			ans++
		}
	}

	fmt.Fprintln(writer, ans)
}
