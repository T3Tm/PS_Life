'''
'25. 08. 09
1. 알파벳 소문자
2. 2개 짝, 모두 제거

1. stack에다가 현재 문자 넣기
2. 현재 넣을 문자가 stack에 있는 문자와 같다면 없애주기
3. 성공적으로 다 제거 됐으면 1 아니면 0
'''
def solution(s):
    stack = []
    for word in s:
        if stack and word == stack[-1]:
            stack.pop()
        else:
            stack.append(word)
    return 0 if stack else 1