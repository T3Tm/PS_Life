import sys
input = sys.stdin.readline
'''
1 > 2
2 > 3
무게가 중간이 절대로 될 수 없다.

1. 나보다 무조건 커야하는 것이 절반 이상이면 무조건 가운데에 들어갈 수 없다.
2. 나보다 무조건 작아야하는 것이 절반 이상이면 무조건 가운데에 들어갈 수 없다.

나보다 커야한다
나보다 작아야 한다.

순서를 나타낼 수 있는 지표가 뭐가 있지?

2 > 1
4 > 3
5 > 1
4 > 2



2 -> 1
4 -> 2, 3
dp[A][B]

A -> B이면 1을 올리면 된다.
'''
def solution() -> None:
    n, m = map(int, input().split())
    half_one = (n + 1) >> 1

    dp = [[0]* (n + 1) for _ in range(n + 1)]
    for _ in range(m):
        x, y = map(int, input().split())
        dp[x][y] = 1
    
    for k in range(1, n + 1):
        for x in range(1, n + 1):
            for y in range(1, n + 1):
                if dp[x][k] and dp[k][y]:
                    dp[x][y] = 1
    
    answer = 0
    for i in range(1, n + 1):
        bigger = smaller = 0
        for other in range(1, n + 1):
            if i == other:continue
            bigger += dp[i][other]
            smaller += dp[other][i]
        
        if bigger >= half_one or smaller >= half_one:
            answer += 1
    print(answer)
            
    
if __name__ == '__main__':
    solution()