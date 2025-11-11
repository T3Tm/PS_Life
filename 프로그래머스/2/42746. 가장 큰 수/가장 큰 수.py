'''
'25. 11. 11.(화) 빼빼로 데이..?

1. 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
343
334

3430
34
이해 됐다.
1. 일단 큰 수부터 먼저 나와야 하며
2. 맨 앞자리가 같다면
    34, 30 이면
    당연히 34가 먼저 나오는 것이 좋음.
    34보다 3은 34가 먼저 나오는 것이 좋긴 함
    근데
    3이랑 30은
    3이 먼저 나온느 것이 이득이지.
    334 보다
    343이 늦기 때문에
    334 먼저 ㄱ
'''
from functools import cmp_to_key
def compare(x: int, y: int) -> int:
    str_x, str_y = str(x), str(y)
    if str_x + str_y < str_y + str_x:
        return 1
    elif str_x + str_y == str_y + str_x:
        return 0
    return -1
    
def solution(numbers):
    answer = ''
    numbers.sort(key=cmp_to_key(compare))
    for num in numbers:
        answer += f'{num}'
    if answer[0] == '0':
        answer = '0'
    return answer