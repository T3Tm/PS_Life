'''
'25. 09. 21.(일)

1. 프로세스 하나 꺼내기(젤 앞에 있는 것)
2. 우선순위가 더 높은 것이 있다면 다시 넣기
3. 없으면 현재 1번에서 뽑은 것 실행

1 <= xi <= 100 (배열의 길이)

location의 위치가 몇 번째로 실행되는가
'''
from collections import deque
def solution(priorities, location):
    answer = 0
    dq = deque([[value, i] for i, value in enumerate(priorities)])#queue로 만들어주기
    
    while 1:
        value, Index = dq.popleft()
        #나머지 벨류 값 중에서 높은 것이 없는지 확인
        is_better = False
        for v, idx in dq:
            if value < v:
                is_better = True
                break
        #큰 것이 있음
        if is_better:
            dq.append([value, Index])
            continue
        #여기까지 왔다면 현재 수를 하나는 뺀 것임.
        
        answer += 1
        #없으면 현재 값을 없앨 것임.
        #내가 찾던 숫자인지 확인
        if Index == location:
            break
    return answer