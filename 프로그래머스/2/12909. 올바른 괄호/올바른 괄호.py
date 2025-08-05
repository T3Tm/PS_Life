'''
'25. 08. 05
1. 올바른 괄호의 쌍을 알아내어라.
2. () 이런 것이 올바른 괄호
3. )( 이런 것은 올바른 괄호가 아니다.


1. 현재 보고 있는 문자가 단순히 ( 라면 스택에 넣는다.
2. )라면 스택에 ( 문자가 있는지 확인한다.
3. 없다면 해당 괄호는 성립할 수 없으므로 false 리턴한다.
4. 모든 문자를 다 마친 뒤 스택에 괄호가 남아있다면 이 문자열도 성립할 수 없는 괄호이다.
'''
def solution(s):
    answer = True
    stack = []
    
    for word in s:
        if word == '(':stack.append(0)
        #스택 안에 있는지 확인
        else:
            if stack:stack.pop()
            #없는 경우
            else:
                answer = False
                break
    if stack: answer = False
    return answer