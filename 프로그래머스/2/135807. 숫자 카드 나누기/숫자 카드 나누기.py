'''
1. A 배열의 공약수 중 B 배열과 서로소인 수

2. B 배열의 공약수 중 A 배열과 서로소인 수

1. 각 최대공약수를 구해준다.
2. 해당 최대공약수를 기준으로 답을 구해준다.


'''
from math import gcd
def getGcd(array: list) -> int:
    ret = array[0]
    for i in range(1, len(array)):
        ret = gcd(ret, array[i])
    return ret

def isDivide(v: int, array: list) -> bool:
    for value in array:
        if value % v == 0:return True
    return False

def solution(arrayA, arrayB):
    answer = 0
    gcd_A = getGcd(arrayA)
    gcd_B = getGcd(arrayB)
    
    if not isDivide(gcd_A, arrayB):
        answer = gcd_A
    
    if not isDivide(gcd_B, arrayA):
        answer = max(answer, gcd_B)
        
    return answer