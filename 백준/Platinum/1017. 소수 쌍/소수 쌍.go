package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	arr    []int
	eratos [2002]bool

	graph [][]int

	done   []int
	visCnt int
	choice []int

	gos []int
)

func dfs(x int) int {
	if done[x] == visCnt {
		return 0
	}
	done[x] = visCnt
	for _, nxt := range graph[x] {
		if choice[nxt] == -1 || dfs(choice[nxt]) == 1 {
			choice[nxt] = x
			gos[x] = nxt
			return 1
		}
	}
	return 0
}

func main() {
	defer writer.Flush()
	var n int
	fmt.Fscanln(reader, &n)

	arr = make([]int, n)
	graph = make([][]int, n)
	choice = make([]int, n)
	done = make([]int, n)
	gos = make([]int, n)
	for i := range arr {
		fmt.Fscan(reader, &arr[i])
	}

	for i := 2; i*i <= 2002; i++ {
		if eratos[i] {
			continue
		}
		for j := i * i; j < 2002; j += i {
			eratos[j] = true
		}
	}

	for i := 1; i < n; i++ {
		for j := 1; j < n; j++ {
			if i == j {
				continue
			}
			if eratos[arr[i]+arr[j]] { //소수쌍을 알아내기
				continue
			}
			graph[i] = append(graph[i], j)
		}
	}

	//fmt.Fprintln(writer, arr)
	var result []int
	for i := 1; i < n; i++ {
		if eratos[arr[0]+arr[i]] {
			continue
		}
		for j := 0; j < n; j++ {
			gos[j] = -1
			choice[j] = -1
		} //아무곳도 가지 않았음.
		gos[0] = i
		choice[i] = 0
		var ans = 0
		// A -> B
		for j := 1; j < n; j++ {
			if i == j {
				continue
			}
			visCnt++
			ans += dfs(j)
		}
		//fmt.Fprintln(writer, choice, ans)

		//fmt.Fprintln(writer, "간선 : ", ans)
		// 일단 0번이랑 i번이랑 짝을 지어놓기
		if ans>>1 == (n>>1)-1 {
			result = append(result, arr[i])
		}
	}

	sort.Slice(result, func(i, j int) bool {
		return result[i] < result[j]
	})

	for _, v := range result {
		fmt.Fprint(writer, v, " ")
	}
	if len(result) == 0 {
		fmt.Fprintln(writer, -1)
	}
}
