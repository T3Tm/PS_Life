'''
'25. 10. 19.(일)

1. 2 * n 타일링을 채우는 방법을 알아내어라

n : 1 1
n : 2 2
n : 3 3
n : 4 5

DP[i] := DP[i - 1] + DP[i - 2]

'''
def solution(n):
    MOD = 10**9 + 7
    dp = [0] * (n + 1)
    dp[0] = dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = (dp[i-1] + dp[i-2])%MOD
    return dp[n]