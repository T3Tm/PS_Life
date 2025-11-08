'''
'25. 11. 8.(토)

1. x > 0, x와 비트가 1 ~ 2개 다른 수 중 제일 작은 수

일단 제일 작은 수이려면 하나 더 큰 수이면 된다.
하지만 이랬을 경우 
7 -> 8
15 -> 16
이랬을 때 비트가 전부 바뀌므로 안된다.

1 ~ 2개만 바뀌려면 제일 뒤에 있는 비트 중에서
01인 구간을 찾고 두개만 바꿔주면 된다.
or 1을 더해주면 된다.
1. 제일 뒤에있는 비트가 0이면 켜주면 제일 작은 수
2. 제일 뒤에있는 비트가 1이면 처음으로 만나는 01 구간에서 바꿔주면 제일 작은 수.
'''
def findSmallestNumber(number: int) -> int:
    #1번 조건
    if number & 1 == 0:
        return number | 1
    
    #2번 조건
    for idx in range(1, 52):
        if not (number & (1 << idx)):
            return (number ^ (1 << idx)) & ~(1 << (idx - 1))

def solution(numbers):
    answer = []
    for num in numbers:
        insert_number = findSmallestNumber(num)
        answer.append(insert_number)
    return answer