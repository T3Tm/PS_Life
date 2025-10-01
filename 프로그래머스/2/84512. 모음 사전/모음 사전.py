'''
'25. 10. 1.(수)

1. A,E,I,O,U만 사용할 수 있다.
2. 모두 길이가 5이하의 단어이다.

해당 단어가 몇 번째일지 생각해보아라.
5 * 5 * 5 * 5 * 5
전부 해봤자 3125가지의 경우의 수이다.
backtracking을 통하여서 차례대로 문자를 만들고 해당 문자가 맞는지 확인하면 된다.
'''
answer = 0
flag = False
def backtracking(depth: int, target: str, now: list) -> None:
    global answer, flag
    if flag:return
    if depth == 5:
        return
    
    if target == ''.join(now):
        flag = True
        return
    
    for alphabet in 'AEIOU':
        now[depth] = alphabet
        answer += 1
        backtracking(depth + 1, target, now)
        if target == ''.join(now):
            flag = True
            return
        now[depth] = ''
def solution(word):
    global answer
    backtracking(0, word, [''] * 5)
    return answer