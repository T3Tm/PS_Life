'''
'25. 12. 22.(월)

1. 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 있을 때 만들 수 있는 소수는 몇 개인가

7P1
7P2
7P3

permutation을 통해서 소수를 찾고
출력한다.
'''
from itertools import permutations as perm
def isPrime(n: int) -> bool:
    if n == 0 or n == 1:return False
    for i in range(2, int(n**.5) + 1):
        if n % i == 0:return False
    return True
def solution(numbers: str):
    answer = 0
    
    number_list = [*numbers]
    
    result = set()
    for i in range(1, len(numbers) + 1):
        for comb in perm(number_list, i):
            str_number = ''.join(comb)
            number = int(str_number)
            
            if isPrime(number):
                result.add(number)
    
    return len(result)