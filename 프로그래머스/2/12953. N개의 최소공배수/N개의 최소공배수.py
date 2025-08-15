'''
'25. 08. 15

1. n개의 수를 주었을 때 최소공배수를 반환하여라

파이썬에는 lcm이라는 함수가 있는데 가능한가. 버전 3.8이라 없네..
그러면 gcd로 구현하면 된다.
(x * y) / gcd(x, y) == lcm(x, y)이기 때문이다.
'''
from math import gcd
def solution(arr):
    answer = arr[0]
    for i in range(1, len(arr)):
        answer = (answer * arr[i]) // gcd(answer, arr[i])
    return answer