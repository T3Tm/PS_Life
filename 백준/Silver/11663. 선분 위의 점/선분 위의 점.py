import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline


def solve(point: list, line: list) -> None:
    point.sort()
    
    for x, y in line:
        left_idx = bisect_left(point, x)
        right_idx = bisect_right(point, y)
        print(right_idx - left_idx)
        
def main():
    n, m = map(int, input().split())
    point_list = [*map(int, input().split())]
    line_list = [[*map(int, input().split())] for _ in range(m)]
    solve(point_list, line_list)
    
main()