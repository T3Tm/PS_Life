'''
'25. 11. 2.(화)

1. |+-10^c|의 버튼들이 있음

12345까지는 단순히 버튼 누르는 것이 더 좋음.

6789
하나 더 줄이고 +하는 것이 좋음


100 1번
3번

34번

100
34
'''
def solution(storey):
    answer = 0
    for i in range(9):
        remain = storey % 10
        storey //= 10
        if remain < 5:
            answer += remain
        elif remain == 5:
            if storey % 10 >= 5:
                storey += 1
            answer += 10 - remain
        else:
            answer += 10 - remain
            storey += 1
    return answer