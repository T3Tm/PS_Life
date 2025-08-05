'''
'25. 08. 05
1. 길이가 같은 배열 A, B 자연수로만 이뤄져있음.
2. 최종적으로 누적된 값이 최소가 되도록 해야 한다.

A1 * B1 + A2 * B2 + A3 * B3 => 최소

A는 오름차순, B는 내림차순으로 한 뒤 서로 곱해서 더해주면 최소가 되지 않을까?
'''
def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    
    for i in range(len(A)):
        answer += A[i] * B[i]
    return answer