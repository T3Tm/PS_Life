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

type pair struct {
	x, y int
}

var (
	redList  = make([]pair, 0)
	blueList = make([]pair, 0)
	visited  []bool

	blueGraph [][]int
	redGraph  [][]int

	componentNumber map[int]int
	componentCnt    []int
	parent          []int //red, blue 단순한 그래프 연결
	visParent       []int // red, blue 그래프 연결 수단

	totalCnt int
)

func dfs(x, vis int) {
	visited[x] = true
	componentNumber[x] = vis
	totalCnt++
	for _, next := range blueGraph[x] {
		if visited[next] {
			continue
		}
		dfs(next, vis)
	}
}

func union(x, y int, parent []int) {
	x, y = find(x, parent), find(y, parent)
	if x == y {
		return
	}

	//더 작은 부모한테 몰아주기
	if x > y {
		x, y = y, x
	}

	parent[x] += parent[y]
	parent[y] = x
}

func find(x int, parent []int) int {
	if parent[x] < 0 {
		return x
	}
	parent[x] = find(parent[x], parent)
	return parent[x]
}

func solution(n, k int) {
	red, blue := 0, 0
	//빨강으로만 그래프 이뤄보기
	//파랑으로만 그래프 이뤄보기
	parent = make([]int, n+1)
	//초기화
	for i := 0; i <= n; i++ {
		parent[i] = -1
	}
	for _, pairs := range redList {
		x, y := pairs.x, pairs.y
		x, y = find(x, parent), find(y, parent)
		if x == y {
			continue
		}
		union(x, y, parent)
		red++
	}

	//초기화
	for i := 0; i <= n; i++ {
		parent[i] = -1
	}

	for _, pairs := range blueList {
		x, y := pairs.x, pairs.y
		x, y = find(x, parent), find(y, parent)
		if x == y {
			continue
		}
		union(x, y, parent)
		blue++
	}
	/* k개를 골라서 만들 수 없음 */
	if !(n-1-red <= k && k <= blue) {
		fmt.Fprintln(writer, 0)
		return
	}
	// number : 컴포넌트
	componentNumber = make(map[int]int)

	/* 1번 정점부터 n번까지 컴포넌트 dfs 연결 */
	// 블루로만 연결했을 때

	visited = make([]bool, n+1)

	visParent = make([]int, 0)
	vis := 0
	for i := 1; i <= n; i++ {
		if visited[i] {
			continue
		}
		totalCnt = 0
		dfs(i, vis)

		visParent = append(visParent, -1)
		vis++
	}

	var result = make([]pair, 0)

	var needRed = n - 1 - k
	/* 필수 컴포넌트 연결 */

	for i := 0; i < vis; i++ {
		visParent[i] = -1
	}

	var used = make([]bool, len(redList))

	//초기화
	for i := 0; i <= n; i++ {
		parent[i] = -1
	}

	for i, pairs := range redList {
		x_com, y_com := componentNumber[pairs.x], componentNumber[pairs.y]
		x, y := find(x_com, visParent), find(y_com, visParent)
		if x == y {
			continue
		}

		//아니라면 머지해주고 정답에다가 쌓아준다.
		result = append(result, pairs)
		used[i] = true
		union(x, y, visParent)

		x, y = find(pairs.x, parent), find(pairs.y, parent)
		union(x, y, parent) //빨간색으로 연결
		needRed--
	}

	/* 다 연결은 됐으니 blue 하나씩 빼면서 red 하나 연결하기 */
	/* 연결되지 않은 빨간색부터 */

	for i := 0; needRed > 0 && i < len(redList); i++ {
		if used[i] {
			continue
		}

		//사용하지 않은 현재 레드 간선을 연결
		x, y := redList[i].x, redList[i].y
		x, y = find(x, parent), find(y, parent)
		if x == y {
			continue
		}
		//이제는 같은 컴포넌트에서 갯수 없애고 이 빨간색 연결
		//fmt.Fprintln(writer, "x : ", x, y)
		result = append(result, redList[i])
		needRed--
		union(x, y, parent)
	}

	for i, cnt := 0, 0; cnt < k && i < len(blueList); i++ {
		x, y := blueList[i].x, blueList[i].y
		//fmt.Fprintln(writer, "x : ", x, y)
		x, y = find(x, parent), find(y, parent)
		if x == y {
			continue
		}
		result = append(result, blueList[i])
		union(x, y, parent)
	}

	for _, pairs := range result {
		fmt.Fprintln(writer, pairs.x, pairs.y)
	}
}

func main() {
	defer writer.Flush()
	var n, m, k int
	fmt.Fscanf(reader, "%d %d %d ", &n, &m, &k)
	blueGraph = make([][]int, n+1)
	redGraph = make([][]int, n+1)
	for i := 1; i <= n; i++ {
		blueGraph[i] = make([]int, 0)
		redGraph[i] = make([]int, 0)
	}

	for i := 0; i < m; i++ {
		var color, f, t int
		fmt.Fscanf(reader, "%c %d %d ", &color, &f, &t)

		if color == 'R' {
			redList = append(redList, pair{x: f, y: t})
			redGraph[f] = append(redGraph[f], t)
			redGraph[t] = append(redGraph[t], f)
		} else {
			blueList = append(blueList, pair{x: f, y: t})
			blueGraph[f] = append(blueGraph[f], t)
			blueGraph[t] = append(blueGraph[t], f)
		}
	}
	solution(n, k)
}
