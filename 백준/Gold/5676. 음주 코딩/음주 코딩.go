package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

var tree []int
var data []int
//init 재귀를 돌면서 세그 만들기
//완전 이진트리로 만들어졌기에
func init_(left, right, node int) int{
	if left == right{
		tree[node] = data[left]
		return tree[node]
	}
	mid := (left + right) >> 1
	
	tree[node] = init_(left, mid, node << 1) * init_(mid + 1, right, node << 1 | 1)
	//fmt.Fprintf(writer, "left : %d right : %d node : %d tree[node] : %d\n", left, right, node, tree[node])
	return tree[node]
}
//update
func update(i, j, left, right, node, value int){
	//범위를 벗어남
	if right < i || j < left{
		return
	}
	if left == right{
		tree[node] = value
		return
	}
	mid := (left + right) >> 1
	update(i, j, left, mid, node << 1, value)
	update(i, j, mid + 1, right, node << 1 | 1, value)
	tree[node] = tree[node << 1] * tree[node << 1 | 1]
}
//query
func query(i, j, left, right, node int) int{
	if right < i || j < left {
		return 1
	}
	if i <= left && right <= j{
		return tree[node]
	}
	mid := (left + right) >> 1
	return query(i, j, left, mid, node << 1) * query(i, j, mid + 1, right, node << 1 | 1)
}

func nextScan(n, k *int) bool{
	if _, err := fmt.Fscanf(reader, "%d %d ", &*n, &*k); errors.Is(err, io.EOF){
		return false
	}
	return true
}


func findCloseSecond(number int) (ret int){
	ret = 1
	for number > 0{
		ret <<= 1
		number >>= 1
	}
	ret <<= 1
	return
}
func main(){
	defer writer.Flush()
	var n, k int

	for nextScan(&n, &k){
		//fmt.Fprintf(writer, "n : %d k : %d\n", n, k)
		size := findCloseSecond(n)
		
		//n개의 숫자를 받아들이기
		data = make([]int, n + 2)
		tree = make([]int, size)
		for i := 1; i <= int(n); i++{
			fmt.Fscanf(reader,"%d ", &data[i])
			if data[i] > 0{
				data[i] = 1
			} else if data[i] < 0{
				data[i] = -1
			}
		}
		/*일단 1로 초기화*/
		for i := range tree{
			tree[i] = 1
		}
		// fmt.Fprintln(writer, size)

		// for i:= 1; i <= n; i++{
		// 	fmt.Fprintf(writer, "%d ", data[i])
		// }
		// fmt.Fprintln(writer)
		init_(1, n, 1)

		// fmt.Fprintln(writer, "배열 출력")
		// for _, value := range tree{
		// 	fmt.Fprintf(writer, "%d ", value)
		// }
		// fmt.Fprintln(writer)
		//하나의 인풋
		for k > 0{
			k--
			var cmd, i, j int
			fmt.Fscanf(reader, "%c %d %d ",&cmd, &i, &j)
			
			// 변경
			if cmd == 'C'{
				if j > 0{
					j = 1
				} else if j < 0{
					j = -1
				}
				update(i, i, 1, n, 1, j)
			}else{
				ret := query(i, j, 1, n, 1)
				//fmt.Fprintf(writer, "i : %d j : %d return value : %d\n",i, j, ret)
				output := ' '
				if ret < 0{
					output = '-'
				}else if ret > 0{
					output = '+'
				}else{
					output = '0'
				}
				fmt.Fprintf(writer, "%c", output)
			}
		}
		fmt.Fprintln(writer)
	}
}