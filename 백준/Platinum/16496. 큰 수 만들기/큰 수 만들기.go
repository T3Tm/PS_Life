package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()
	var n int
	fmt.Fscanf(reader, "%d ", &n)

	var ary = make([]int, n)
	for i := range ary {
		fmt.Fscanf(reader, "%d ", &ary[i])
	}

	sort.Slice(ary, func(x, y int) bool {
		xx, yy := strconv.Itoa(ary[x]), strconv.Itoa(ary[y])

		if xx+yy < yy+xx {
			return false
		}
		return true
	})

	var answer = ""
	for _, v := range ary {
		answer += strconv.Itoa(v)
	}

	if answer[0] == '0' {
		answer = "0"
	}
	fmt.Fprintln(writer, answer)
}
