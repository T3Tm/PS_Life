'''
'25. 08. 24

1. 올바르게 짝지어진 괄호
2. 1 <= |S| <= 1000일 때
S의 값을 왼쪽으로 쉬프트 했을 때 올바르게 짝지어진 괄호 문자열이 되게 하는 x의 개수를 return하여라.

ex)
    ()[]{} x = 0 만족
    x는 0부터 5까지만 가능, 0일 때만 만족한다. 아니지
    []{}() x = 2, 
    {}()[] x = 4 총 3번 가능

1. 왼쪽으로 쉬프트 하는 방식 O(1)에 가능
2. 올바른 괄호인지 판단하는 방법 O(|S|)에 판단 가능
3. 총 왼쪽으로 쉬프트하는 횟수 |S| - 1번

쉬프트 하면서 올바른 괄호 판단하는 시간 복잡도 => O(|S|^2) 10^6 이므로 충분히 N^2으로 돌려도 됨.

'''
from collections import deque
def is_right(word: deque) -> bool:
    s = []
        
    other = {']' : '[', '}' : '{', ')' : '('}
    for ch in word:
        if ch in '[({':
            s.append(ch)
        #빼내야 함.
        else:
            #스택의 맨 위가 쌍을 이루는 괄호인지 판별
            if s and s[-1] == other[ch]:
                s.pop()
            #아니면 끝내기
            else:
                return False
    if s:return False
    return True

def solution(s):
    answer = 0
    dq = deque([*s])#디큐에 넣어 놓는다.
    
    #쉬프트 횟수는 deque_len번 => 변경 후 체크할 거기 때문에
    for _ in range(len(dq)):
        front = dq.popleft()
        dq.append(front)#뒤에 넣기
        answer += is_right(dq)
    return answer