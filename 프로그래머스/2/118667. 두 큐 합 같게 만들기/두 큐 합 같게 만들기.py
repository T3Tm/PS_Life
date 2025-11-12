'''
'25. 11. 12.(수)

1. 하나의 길이가 30만이기 때문에, 그냥 다 돌리면 된다.

1. 전체합 구한다. 그 후 절반을 구한다.
2. 앞을 빼서 뒤로 넣는 작업을 한다.
'''
from collections import deque
def queue_pop(src: deque, dst: deque, half: int) -> int:
    ret = 0
    dq = deque([v for v in src + dst])
    
    f = b = t = 0
    for i in range(len(src)):
        t += src[i]
        b += 1
        
    if t == half:
        return 0
    
    while b < len(dq):
        if t < half:
            t += dq[b]
            b += 1
            ret += 1
        elif t > half:
            t -= dq[f]
            f += 1
            ret += 1
        
        if half == t:break
        
    if t != half:
        ret = -1
    return ret
    
def solution(queue1, queue2):
    answer = -2
    front = sum(queue1)
    back = sum(queue2)
    
    if (front + back) & 1:return -1
    half = (front + back) >> 1
    
    if half == front == back:return 0
    f = queue_pop(queue1, queue2, half)
    b = queue_pop(queue2, queue1, half)
    
    if f != -1 and b != -1:
        answer = min(f, b)
    elif f == -1:
        answer = b
    else:
        answer = f
    
    
    return answer