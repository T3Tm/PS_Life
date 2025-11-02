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

type Pair struct {
	x, y int
}

type heap[T any] struct {
	container []T
	len       int
	compare   func(a, b T) bool
}

func makeHeap[T any](data T, less func(a, b T) bool) *heap[T] {
	ret := &heap[T]{}
	ret.container = make([]T, 0)
	ret.container = append(ret.container, data)
	ret.len = 0
	ret.compare = less
	return ret
}

func (p *heap[T]) size() int {
	return p.len
}

/*
제일 말단 노드로 넣고
위에 있는 것과 비교 후 올리면 된다.
*/
func (p *heap[T]) push(data T) {
	p.container = append(p.container, data) //제일 말단으로 올리기
	p.len++
	var idx = p.len

	for idx > 1 {
		//내가 부모보다 클지 작을지는 모르겠고
		//compare함수에 다라서 바뀌는지 아닌지만 바뀌면 된다.
		parent, now := p.container[idx>>1], p.container[idx]
		if p.compare(now, parent) { //서로 바꿔야 함.
			p.container[idx>>1], p.container[idx] = p.container[idx], p.container[idx>>1]
		} else {
			break
		}
		idx >>= 1
	}

}

func (p *heap[T]) delete() (ret T) {
	ret = p.top() //제일 위에 있는 것 갖고 오기
	var (
		item = p.container[p.len]
		idx  = 1
	)
	//fmt.Fprintln(writer, item)
	p.container = p.container[:p.len]
	p.len--

	for idx<<1 <= p.len {
		left, right := idx<<1, idx<<1|1

		compare_idx := left
		if right <= p.len && p.compare(p.container[right], p.container[left]) {
			compare_idx = right
		}

		if p.compare(p.container[compare_idx], item) {
			p.container[idx] = p.container[compare_idx]
			idx = compare_idx
		} else {
			break
		}
	}
	if p.len != 0 {
		p.container[idx] = item
	}
	return ret
}

func (p *heap[T]) top() (ret T) {
	return p.container[1]
}

//힙

/*
	1. insert(push) 하나 넣기
	2. delete(pop) 하나 빼기
	3. peek/top (최대 최소 확인) 제일 위에 확인
*/

func main() {
	defer writer.Flush()

	var n int
	fmt.Fscanf(reader, "%d ", &n)
	var ary = make([]Pair, n)
	for i := range ary {
		fmt.Fscanf(reader, "%d %d ", &ary[i].x, &ary[i].y)
	}

	var (
		l, p int
	)
	fmt.Fscanf(reader, "%d %d ", &l, &p)
	ary = append(ary, Pair{l, 0})
	
	var pq = makeHeap(ary[0], func(a, b Pair) bool {
		if a.y == b.y {
			return a.x < b.x
		}
		return a.y > b.y
	})

	sort.Slice(ary, func(i, j int) bool {
		if ary[i].x == ary[j].x {
			return ary[i].y > ary[j].y
		}
		return ary[i].x < ary[j].x
	})

	var (
		answer = 0
		idx    = 0
	)
	for l > p {
		for ary[idx].x <= p && idx < n {
			pq.push(ary[idx])
			idx++
		}
		if pq.len != 0 {
			top := pq.delete()
			p += top.y
			answer++
		} else {
			answer = -1
			break
		}
	}
	fmt.Fprintln(writer, answer)
}
