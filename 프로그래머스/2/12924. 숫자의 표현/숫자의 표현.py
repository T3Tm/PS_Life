'''
'25. 08. 07

1. n을 표현하는 방법이 여러가지이다.
2. n을 연속한 자연수로 표현하는 방법
'''
def solution(n):
    answer = 0
    l = r = 0
    sums = 0
    while l <= r and r <= n:
        if sums <= n:
            if sums == n:
                answer += 1
            r += 1
            sums += r
        else:
            sums -= l
            l += 1
    return answer