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
	done   []int
	choice []int

	visCnt int
)

type shark struct {
	size, velocity, wise int
}

func (s *shark) better(other shark) bool {
	return s.velocity >= other.velocity && s.wise >= other.wise && s.size >= other.size
}
func (s *shark) less(other shark) bool {
	return s.velocity <= other.velocity && s.wise <= other.wise && s.size <= other.size
}

func dfs(x int) int {
	if done[x] == visCnt {
		return 0
	}
	done[x] = visCnt
	for _, next := range graph[x] {
		if choice[next] == -1 || dfs(choice[next]) == 1 {
			choice[next] = x
			return 1
		}
	}
	return 0
}

func main() {
	defer writer.Flush()
	var n int
	fmt.Fscanf(reader, "%d ", &n)
	var sharks = make([]shark, n)
	graph = make([][]int, n)
	choice = make([]int, n)
	for i := range sharks {
		choice[i] = -1
		fmt.Fscanf(reader, "%d %d %d ", &sharks[i].size, &sharks[i].velocity, &sharks[i].wise)
	}
	//fmt.Fprintln(writer, sharks)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if sharks[i].better(sharks[j]) {
				graph[i] = append(graph[i], j)
			} else if sharks[i].less(sharks[j]) {
				graph[j] = append(graph[j], i)
			}
		}
	}
	var ans = 0
	done = make([]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < 2; j++ {
			visCnt++
			ans += dfs(i)
		}
	}
	//fmt.Fprintln(writer, graph)
	//fmt.Fprintln(writer, ans)
	fmt.Fprintln(writer, n-ans)
}
