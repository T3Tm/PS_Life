'''
'25. 09. 24.(수)

1. n개의 음이 아닌 정수가 있음.
2. 적절히 더하거나 빼서 타겟 넘버를 만들려고 함.

2^20의 경우의 수가 있음.
backtracking으로 풀이를 진행하면 됨.

'''
answer = 0
def backtracking(depth: int, numbers: list, target: int, total: int) -> None:
    global answer
    #depth == numbers가 되면 종료
    if depth == len(numbers):
        #내가 찾으려는 숫자와 동일하면 1 증가
        if total == target: answer += 1
        return
    #현재 depth에 있는 number를 더하거나 뺄 수 있음.
    backtracking(depth + 1, numbers, target, total + numbers[depth])
    backtracking(depth + 1, numbers, target, total - numbers[depth])
    
    
def solution(numbers, target):
    global answer
    backtracking(0, numbers, target, 0)
    return answer