'''
'25. 08. 11

1. 한 번 K 칸앞으로 점프 K만큼의 건전지사용
2. 현재까지 온 거리 x2 순간이동 건전지 x

N거리를 움직이는데 사용해야 되는 건전지 사용량 최솟값
'''
def solution(n):
    ans = 0
    while n:
        ans += n&1
        n>>=1
    return ans