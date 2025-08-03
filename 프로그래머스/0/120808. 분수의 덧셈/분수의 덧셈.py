'''
'25. 08. 03

1. 분자 numer1, 분모 denom1
2. 분자 numer2, 분모 denom2
3. 두 분수를 더해서 기약분수로 나타내시오.

1. 통분해서 더해준 뒤
2. 최대공약수로 분자 분모를 나눠주면 된다.
'''
from math import gcd
def solution(numer1, denom1, numer2, denom2):
    down = denom2 * denom1
    up = numer2 * denom1 + numer1 * denom2
    
    gcd_value = gcd(down, up)
    answer = [up // gcd_value, down // gcd_value]
    return answer