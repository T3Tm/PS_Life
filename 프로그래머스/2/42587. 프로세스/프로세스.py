# from collections import deque
# def solution(priorities, location):
#     answer = 0
#     idx_q = deque([i for i in range(len(priorities))])
#     q = deque(priorities)
#     max_value = max(q)
#     while q:
#         if(q[0] == max_value):
#             answer+=1
#             q.popleft()
#             if(idx_q.popleft() == location):
#                 break
#             max_value = max(q)
#             continue
#         q.rotate(-1)
#         idx_q.rotate(-1)
#     return answer
from collections import deque
def solution(priorities, location):
    #1. 프로세스 하나 꺼내기
    #2. 우선순위가 가장 큰 프로세스 꺼내기
    #3. 
    deq = deque()
    for idx, value in enumerate(priorities):
        deq.append((idx, value))
    answer = 1
    while deq:
        max_q = -1
        for value in deq:
            max_q = max(max_q, value[1])
            
        front = deq.popleft()
        if front[1] != max_q:#최댓값 아님
            deq.append(front)
            continue
        
        if front[0] == location:break
        answer += 1
    return answer