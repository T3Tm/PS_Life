'''
'25. 10. 17.(금)

1. x -> y 변환

1. x + n
2. x << 1
3. x * 3

1 <= x <= y <= 10^6
1 <= n < y

DP로
DP[i] := i로 변환하기 위해 필요한 최소 연산 횟수

테이블 정의
'''
def solution(x, y, n):
    MAX = 0x3f3f3f3f
    dp = [MAX] * (y + 1)    
    dp[x] = 0#base
    
    for i in range(x, y + 1):
        if i - n >= 0 and dp[i - n] != MAX:
            dp[i] = dp[i - n] + 1
        
        if i % 2 == 0 and dp[i >> 1] != MAX:
            dp[i] = min(dp[i], dp[i >> 1] + 1)
        
        if i % 3 == 0 and dp[i // 3] != MAX:
            dp[i] = min(dp[i], dp[i // 3] + 1)
    return [dp[y], -1][dp[y] == MAX]