'''
'25. 08. 09
1. n이 주어졌을 떄 다음으로 큰 숫자를 리턴하여라
2. 단 다음으로 큰 숫자는 1의 갯수가 같아야 한다.

1의 갯수가 최대로 나올 수 있는 것이 20칸이고
'''
def solution(n):
    tmp = n + 1
    p = bin(n)[2:].count('1')
    while p != bin(tmp)[2:].count('1'):
        tmp += 1
    return tmp