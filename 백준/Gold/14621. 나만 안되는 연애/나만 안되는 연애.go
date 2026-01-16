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
)

/*
	1. M - M, W - W는 그래프를 애초에 연결하지 않으면 되지 않나??
	2. ST를 만족한다.
	3. MST를 만족한다.

	1. 크루스칼 알고리즘을 짜면 된다.

	1. 그래프를 일단 다 푸쉬한다.
	2. 오름차순으로 정렬한다.
	3. 하나씩 빼면서 연결한다.
	4. disjoint set을 사용하여 그래프 연결
*/

var (
	parent [1002]int //서로 연결됐는지 확인

)

func find(x int) int {
	if parent[x] < 0 {
		return x
	}
	parent[x] = find(parent[x])
	return parent[x]
}

func merge(x, y int) {
	x = find(x)
	y = find(y)

	if x == y {
		return
	}
	if x > y {
		x, y = y, x
	}
	parent[x] += parent[y]
	parent[y] = x //부모 덮기
}

type node struct {
	u, v, d int
}

var (
	n, m int
	ary  []string

	graph []node
)

func main() {
	defer writer.Flush()
	for i := 0; i < 1002; i++ {
		parent[i] = -1
	}
	fmt.Fscanln(reader, &n, &m)

	ary = make([]string, n)
	for i := range ary {
		fmt.Fscan(reader, &ary[i])
		//fmt.Fprintln(writer, ary[i])
	}
	fmt.Fscanln(reader)

	for i := 0; i < m; i++ {
		var u, v, d int
		fmt.Fscanln(reader, &u, &v, &d)
		u--
		v--
		if ary[u] == ary[v] {
			continue
		} //이 그래프는 필요가 없음

		graph = append(graph, node{u, v, d})
	}

	sort.Slice(graph, func(i, j int) bool {
		var front, back = graph[i], graph[j]
		return front.d < back.d
	})

	var conn = 0
	var total = 0
	for i := 0; i < len(graph) && conn < n-1; i++ {
		var u_parent = find(graph[i].u)
		var v_parent = find(graph[i].v)
		if u_parent == v_parent {
			continue
		}
		merge(u_parent, v_parent)
		conn++
		total += graph[i].d
	}
	if conn == n-1 {
		fmt.Fprintln(writer, total)
	} else {
		fmt.Fprintln(writer, -1)
	}
}
