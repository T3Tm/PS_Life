'''
'25. 10. 11.(토)

1. 양의 정수 n이 주어짐
2. k진수로 바꾸었을 떄 조건에 맞는 소수가 몇 개인지 알아보려함.

1. k진수로 변환한다.
2. 해당 진수로 변환시 0으로 split한다.
3. 소수 판별한다(n^.5)
4. 결과 도출한다.
'''
def is_prime(n: int) -> bool:
    if n == 1:return False
    for i in range(2, int(n**.5) + 1):
        if n % i == 0:return False
    return True

def solution(n, k):
    answer = 0
    
    #현재 소수 담을 string
    number = ''
    
    #소수 판별
    while n:
        alpha = n % k#다음으로 넣을 숫자
        n//=k
        if alpha == 0:
            #현재까지 쌓은 number가 '' 가 아닌 있는 숫자이면서
            #소수인지 판별하여 갯수세주기
            if number and is_prime(int(number[::-1])):
                answer += 1
            number = ''
            continue
        #아니라면 number에 쌓기
        number += f'{alpha}'
    if number and is_prime(int(number[::-1])):
        answer += 1
    return answer