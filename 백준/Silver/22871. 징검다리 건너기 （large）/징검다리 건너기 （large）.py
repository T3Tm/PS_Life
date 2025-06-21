import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline
#항상 오른쪽으로만 이동
#i -> j이동할 때 (j- i) * (1 + |Ai - Aj|)만큼 힘을 사용
#최대 K만큼 힘을 사용가능
INF = 10 ** 6
dp = [INF] * 5001
def dfs(cur: int, point_list: list) -> int:
    if cur == len(point_list) - 1:
        return 0
    
    if dp[cur] != INF:
        return dp[cur]
    
    for step in range(1, len(point_list) - cur):
        next = cur + step
        dp[cur] = min(dp[cur], max(dfs(next, point_list), step * (1 + abs(point_list[cur] - point_list[next]))))
    
    return dp[cur]

def solve(n: int, point_list: list) -> int:
    return dfs(0, point_list)

def main():
    n = int(input())
    point_list = [*map(int, input().split())]
    print(solve(n, point_list))
    
main()